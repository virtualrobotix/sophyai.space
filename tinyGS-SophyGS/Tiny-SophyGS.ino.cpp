# 1 "C:\\Users\\SOPHYA~1\\AppData\\Local\\Temp\\tmpsshj_een"
#include <Arduino.h>
# 1 "D:/Lavoro/Progetti 2021/sophyai.space/tinyGS-SophyGS/Tiny-SophyGS.ino"
# 67 "D:/Lavoro/Progetti 2021/sophyai.space/tinyGS-SophyGS/Tiny-SophyGS.ino"
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include "src/ConfigManager/ConfigManager.h"
#include "src/Display/Display.h"
#include "src/Mqtt/MQTT_Client.h"
#include "src/Mqtt/MQTT_Client_Fees.h"
#include "src/Status.h"
#include "src/Radio/Radio.h"
#include "src/ArduinoOTA/ArduinoOTA.h"
#include "src/OTA/OTA.h"
#include <ESPNtpClient.h>
#include "src/Logger/Logger.h"

#if RADIOLIB_VERSION_MAJOR != (0x04) || RADIOLIB_VERSION_MINOR != (0x02) || RADIOLIB_VERSION_PATCH != (0x01) || RADIOLIB_VERSION_EXTRA != (0x00)
#error "You are not using the correct version of RadioLib please copy TinyGS/lib/RadioLib on Arduino/libraries"
#endif

#if RADIOLIB_GODMODE == 0 && !PLATFORMIO
#error "Using Arduino IDE is not recommended, please follow this guide https://github.com/G4lile0/tinyGS/wiki/Arduino-IDE or edit /RadioLib/src/BuildOpt.h and uncomment #define RADIOLIB_GODMODE around line 367"
#endif

ConfigManager& configManager = ConfigManager::getInstance();
MQTT_Client& mqtt = MQTT_Client::getInstance();
MQTT_Client_Fees& mqtt_sophygs = MQTT_Client_Fees::getInstance();

Radio& radio = Radio::getInstance();

const char* ntpServer = "time.cloudflare.com";
void printLocalTime();


Status status;
Status status_sophy;


void printControls();
void switchTestmode();
void checkButton();
void setupNTP();
void ntp_cb (NTPEvent_t e);
void configured();
void wifiConnected();
void setup();
void loop();
void handleSerial();
#line 110 "D:/Lavoro/Progetti 2021/sophyai.space/tinyGS-SophyGS/Tiny-SophyGS.ino"
void ntp_cb (NTPEvent_t e)
{
  switch (e.event) {
    case timeSyncd:
    case partlySync:

      status.time_offset = e.info.offset;
      break;
    default:
      break;
  }
}

void configured()
{
  configManager.setConfiguredCallback(NULL);
  configManager.printConfig();
  radio.init();
}

void wifiConnected()
{
  configManager.setWifiConnectionCallback(NULL);
  setupNTP();
  displayShowConnected();
  configManager.delay(100);

  if (configManager.getLowPower())
  {
    Log::debug(PSTR("Set low power CPU=80Mhz"));
    setCpuFrequencyMhz(80);
  }

  configManager.delay(400);
  radio.init();
}

void setup()
{
  setCpuFrequencyMhz(240);
  Serial.begin(115200);
  delay(100);

  Log::console(PSTR("TinyGS-SophyAI.space Version %d - %s"), status.version, status.git_version);
  configManager.setWifiConnectionCallback(wifiConnected);
  configManager.setConfiguredCallback(configured);
  configManager.init();
  if (configManager.isFailSafeActive())
  {
    Log::console(PSTR("FATAL ERROR: The board is in a boot loop, rescue mode launched. Connect to the WiFi AP: %s, and open a web browser on ip 192.168.4.1 to fix your configuration problem or upload a new firmware."), configManager.getThingName());
    configManager.forceApMode(true);
    return;
  }

  configManager.doLoop();
  pinMode (configManager.getBoardConfig().PROG__BUTTON, INPUT_PULLUP);
  displayInit();
  displayShowInitialCredits();
  configManager.delay(1000);
  mqtt.begin();
  mqtt_sophygs.begin();


  if (configManager.getOledBright() == 0)
  {
    displayTurnOff();
  }

  printControls();
}

void loop() {
  configManager.doLoop();
  if (configManager.isFailSafeActive())
    return;

  ArduinoOTA.handle();
  handleSerial();
  checkButton();

  if (configManager.getState() < 2)
  {
    displayShowApMode();
    return;
  }

  if (radio.isReady())
  {
    status.radio_ready = true;
    radio.listen();
  }
  else {
    status.radio_ready = false;
  }

  if (configManager.getState() < 4)
  {
    displayShowStaMode(configManager.isApMode());
    return;
  }



  mqtt.loop();
  mqtt_sophygs.loop();
  OTA::loop();
  if (configManager.getOledBright() != 0) displayUpdate();
}

void setupNTP()
{
  NTP.setInterval (120);
  NTP.setTimeZone (configManager.getTZ ());
  NTP.onNTPSyncEvent (ntp_cb);
  NTP.setMinSyncAccuracy (2000);
  NTP.settimeSyncThreshold (1000);
  NTP.setMaxNumSyncRetry (2);
  NTP.begin (ntpServer);
  Serial.printf ("NTP started");

  time_t startedSync = millis ();
  while (NTP.syncStatus() != syncd && millis() - startedSync < 5000)
  {
    configManager.delay(100);
  }

  printLocalTime();
}

void checkButton()
{
  #define RESET_BUTTON_TIME 8000
  static unsigned long buttPressedStart = 0;
  if (!digitalRead (configManager.getBoardConfig().PROG__BUTTON))
  {
    if (!buttPressedStart)
    {
      buttPressedStart = millis();
    }
    else if (millis() - buttPressedStart > RESET_BUTTON_TIME)
    {
      Log::console(PSTR("Rescue mode forced by button long press!"));
      Log::console(PSTR("Connect to the WiFi AP: %s and open a web browser on ip 192.168.4.1 to configure your station and manually reboot when you finish."), configManager.getThingName());
      configManager.forceDefaultPassword(true);
      configManager.forceApMode(true);
      buttPressedStart = 0;
    }
  }
  else {
    unsigned long elapsedTime = millis() - buttPressedStart;
    if (elapsedTime > 30 && elapsedTime < 1000)
      displayNextFrame();
    buttPressedStart = 0;
  }
}

void handleSerial()
{
  if(Serial.available())
  {
    radio.disableInterrupt();


    char serialCmd = Serial.read();


    configManager.delay(50);


    while(Serial.available())
    {
      Serial.read();
    }


    switch(serialCmd) {
      case 'e':
        configManager.resetAllConfig();
        ESP.restart();
        break;
      case 't':
        switchTestmode();
        break;
      case 'b':
        ESP.restart();
        break;
      case 'p':
        if (!configManager.getAllowTx())
        {
          Log::console(PSTR("Radio transmission is not allowed by config! Check your config on the web panel and make sure transmission is allowed by local regulations"));
          break;
        }

        static long lastTestPacketTime = 0;
        if (millis() - lastTestPacketTime < 20*1000)
        {
          Log::console(PSTR("Please wait a few seconds to send another test packet."));
          break;
        }

        radio.sendTestPacket();
        lastTestPacketTime = millis();
        Log::console(PSTR("Sending test packet to nearby stations!"));
        break;
      default:
        Log::console(PSTR("Unknown command: %c"), serialCmd);
        break;
    }

    radio.enableInterrupt();
  }
}

void switchTestmode()
{
  if (configManager.getTestMode())
  {
      configManager.setTestMode(false);
      Log::console(PSTR("Changed from test mode to normal mode"));
  }
  else
  {
      configManager.setTestMode(true);
      Log::console(PSTR("Changed from normal mode to test mode"));
  }
}

void printLocalTime()
{
    time_t currenttime = time (NULL);
    if (currenttime < 0) {
        Log::error (PSTR ("Failed to obtain time: %d"), currenttime);
        return;
    }
    struct tm* timeinfo;

    timeinfo = localtime (&currenttime);

  Serial.println(timeinfo, "%A, %B %d %Y %H:%M:%S");
}


void printControls()
{
  Log::console(PSTR("------------- Controls -------------"));
  Log::console(PSTR("t - change the test mode and restart"));
  Log::console(PSTR("e - erase board config and reset"));
  Log::console(PSTR("b - reboot the board"));
  Log::console(PSTR("p - send test packet to nearby stations (to check transmission)"));
  Log::console(PSTR("------------------------------------"));
}