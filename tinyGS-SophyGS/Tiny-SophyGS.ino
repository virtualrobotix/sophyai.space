/***********************************************************************
  tinyGS.ini - GroundStation firmware
  
  Copyright (C) 2020 -2021 @G4lile0, @gmag12 and @dev_4m1g0

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <https://www.gnu.org/licenses/>.

  ***********************************************************************

  TinyGS is an open network of Ground Stations distributed around the
  world to receive and operate LoRa satellites, weather probes and other
  flying objects, using cheap and versatile modules.

  This project is based on ESP32 boards and is compatible with sx126x and
  sx127x you can build you own board using one of these modules but most
  of us use a development board like the ones listed in the Supported
  boards section.

  Supported boards
    Heltec WiFi LoRa 32 V1 (433MHz & 863-928MHz versions)
    Heltec WiFi LoRa 32 V2 (433MHz & 863-928MHz versions)
    TTGO LoRa32 V1 (433MHz & 868-915MHz versions)
    TTGO LoRa32 V2 (433MHz & 868-915MHz versions)
    TTGO LoRa32 V2 (Manually swapped SX1267 to SX1278)
    T-BEAM + OLED (433MHz & 868-915MHz versions)
    T-BEAM V1.0 + OLED
    FOSSA 1W Ground Station (433MHz & 868-915MHz versions)
    ESP32 dev board + SX126X with crystal (Custom build, OLED optional)
    ESP32 dev board + SX126X with TCXO (Custom build, OLED optional)
    ESP32 dev board + SX127X (Custom build, OLED optional)

  Supported modules
    sx126x
    sx127x

    Web of the project: https://tinygs.com/
    Github: https://github.com/G4lile0/tinyGS
    Main community chat: https://t.me/joinchat/DmYSElZahiJGwHX6jCzB3Q

    In order to onfigure your Ground Station please open a private chat to get your credentials https://t.me/tinygs_personal_bot
    Data channel (station status and received packets): https://t.me/tinyGS_Telemetry
    Test channel (simulator packets received by test groundstations): https://t.me/TinyGS_Test

    Developers:
      @gmag12       https://twitter.com/gmag12
      @dev_4m1g0    https://twitter.com/dev_4m1g0
      @g4lile0      https://twitter.com/G4lile0

====================================================
  IMPORTANT:
    - Follow this guide to get started: https://github.com/G4lile0/tinyGS/wiki/Quick-Start
    - Arduino IDE is NOT recommended, please use Platformio: https://github.com/G4lile0/tinyGS/wiki/Platformio

**************************************************************************/

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
#include <ArduinoP13.h>  // Satellite tracking
#define MAP_MAXX   128
#define MAP_MAXY    64

/* Setup a satellite to track */
// const char *tleName = "FEES (AL OBJ)";
// const char *tlel1   = "1 48082U 21022AL  21114.15389910  .00002956  00000-0  20395-3 0  9998";
// const char *tlel2   = "2 48082  97.5625  17.4313 0017331 124.4755  12.9113 15.06444099  3406";

const char *tleName = "FEES";
const char *tlel1   = "1 48082U 21022AL  21144.56510677  .00001413  00000-0  99473-4 0  9993";
const char *tlel2   = "2 48082  97.5590  47.2794 0017276  28.6038  55.9884 15.06536559  7980";

// const char *tleName = "OBJECT AL";
// const char *tlel1   = "1 48082U 21022AL  21144.56510677  .00001413  00000-0  99473-4 0  9993";
// const char *tlel2   = "2 48082  97.5590  47.2794 0017276  28.6038  55.9884 15.06536559  7980";

// International Space Station
// const char *tleName = "ISS (ZARYA)";
// const char *tlel1   = "1 25544U 98067A   19132.94086806  .00001341  00000-0  28838-4 0  9999";
// const char *tlel2   = "2 25544  51.6422 176.3402 0001360 345.7469  23.7758 15.52660993169782";

// For testing purpose (geostationary, no motion)
//const char *tleName = "ES'HAIL 2";
//const char *tlel1   = "1 43700U 18090A   19132.49026609  .00000132  00000-0  00000-0 0  9990";
//const char *tlel2   = "2 43700   0.0182 271.8232 0001691 166.1779 354.2495  1.00270105  1678";


const char  *pcMyName = "IU2IOL";    // Observer name
double       dMyLAT   =  45.3043;    // Latitude (Breitengrad): N -> +, S -> -
double       dMyLON   =   9.5050;    // Longitude (Längengrad): E -> +, W -> -
double       dMyALT   =      0.0;    // Altitude ASL (m)
// double       dMyALT   =    386.0;    // Altitude ASL (m)

double       dfreqRX  = 145.800;     // Nominal downlink frequency
double       dfreqTX  = 437.800;     // Nominal uplink frequency

int          iYear    = 2021;        // Set start year
int          iMonth   = 5;           // Set start month
int          iDay     = 05;          // Set start day
int          iHour    = 21;          // Set start hour
int          iMinute  = 1;           // Set start minute
int          iSecond  = 41;          // Set start second

double       dSatLAT  = 0;           // Satellite latitude
double       dSatLON  = 0;           // Satellite longitude
double       dSatAZ   = 0;           // Satellite azimuth
double       dSatEL   = 0;           // Satellite elevation

double       dSunLAT  = 0;           // Sun latitude
double       dSunLON  = 0;           // Sun longitude
double       dSunAZ   = 0;           // Sun azimuth
double       dSunEL   = 0;           // Sun elevation

int          ixQTH    = 0;           // Map pixel coordinate x of QTH
int          iyQTH    = 0;           // Map pixel coordinate y of QTH
int          ixSAT    = 0;           // Map pixel coordinate x of satellite
int          iySAT    = 0;           // Map pixel coordinate y of satellite
int          ixSUN    = 0;           // Map pixel coordinate x of sun
int          iySUN    = 0;           // Map pixel coordinate y of sun

char         acBuffer[20];            // Buffer for ASCII time

int          aiSatFP[32][2];          // Array for storing the satellite footprint map coordinates
int          aiSunFP[32][2];          // Array for storing the sunlight footprint map coordinates

/* End Arduino P13*/
#if  RADIOLIB_VERSION_MAJOR != (0x04) || RADIOLIB_VERSION_MINOR != (0x02) || RADIOLIB_VERSION_PATCH != (0x01) || RADIOLIB_VERSION_EXTRA != (0x00)
#error "You are not using the correct version of RadioLib please copy TinyGS/lib/RadioLib on Arduino/libraries"
#endif

#ifndef RADIOLIB_GODMODE
#if !PLATFORMIO
#error "Using Arduino IDE is not recommended, please follow this guide https://github.com/G4lile0/tinyGS/wiki/Arduino-IDE or edit /RadioLib/src/BuildOpt.h and uncomment #define RADIOLIB_GODMODE around line 367" 
#endif
#endif

ConfigManager& configManager = ConfigManager::getInstance();
MQTT_Client& mqtt = MQTT_Client::getInstance();
MQTT_Client_Fees& mqtt_sophygs = MQTT_Client_Fees::getInstance();
 
Radio& radio = Radio::getInstance();

const char* ntpServer = "time.cloudflare.com";
void printLocalTime();

// Global status
Status status;
Status status_sophy;


void printControls();
void switchTestmode();
void checkButton();
void setupNTP();

void ntp_cb (NTPEvent_t e)
{
  switch (e.event) {
    case timeSyncd:
    case partlySync:
      //Serial.printf ("[NTP Event] %s\n", NTP.ntpEvent2str (e));
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
  arduino_ota_setup();
  configManager.delay(100); // finish animation

  if (configManager.getLowPower())
  {
    Log::debug(PSTR("Set low power CPU=80Mhz"));
    setCpuFrequencyMhz(80); //Set CPU clock to 80MHz
  }

  configManager.delay(400); // wait to show the connected screen and stabilize frequency
  //radio.init();
}

void check_azel(double check_time, bool logOut=false)
{
  static double last_check;
  if (millis() - last_check > check_time) {
    last_check = millis();
    time_t currenttime = time (NULL);
    if (currenttime < 0) {
        Log::error (PSTR ("Failed to obtain time: %d"), currenttime);
        return;
    }
    struct tm* ti;
    
    // ti = localtime (&currenttime);
    ti = gmtime (&currenttime);

    P13Sun Sun;   // Create object for the sun
    // Log::console("GMT: %d-%d-%d %d:%d:%d", ti->tm_year, ti->tm_mon, ti->tm_mday, ti->tm_hour, ti->tm_min, ti->tm_sec);
    P13DateTime MyTime(ti->tm_year + 1900, ti->tm_mon + 1, ti->tm_mday, ti->tm_hour, ti->tm_min, ti->tm_sec); // Set start time for the prediction, ti->tm_hour-2
    // P13Observer MyQTH(pcMyName, 45.0, 9.0, 0.0);              // Set observer coordinates
    // P13Observer MyQTH(pcMyName, dMyLAT, dMyLON, dMyALT);              // Set observer coordinates
    P13Observer MyQTH(configManager.getThingName(), configManager.getLatitude(), configManager.getLongitude(), dMyALT);              // Set observer coordinates

    P13Satellite MySAT(tleName, tlel1, tlel2);                        // Create satellite definition from TLE
    
  //  latlon2xy(ixQTH, iyQTH, dMyLAT, dMyLON, 128, 64);      // Get x/y for the pixel map 128x64 EPS32 Display dimension1 
    latlon2xy(ixQTH, iyQTH, configManager.getLatitude(), configManager.getLongitude(), 128, 64);      // Get x/y for the pixel map 128x64 EPS32 Display dimension1 
    
    MyTime.ascii(acBuffer);             // Get time for prediction as ASCII string
    MySAT.predict(MyTime);              // Predict satellite for specific time
    MySAT.latlon(dSatLAT, dSatLON);     // Get the rectangular coordinates
    MySAT.elaz(MyQTH, dSatEL, dSatAZ);  // Get azimuth and elevation for MyQTH
    latlon2xy(ixSAT, iySAT, dSatLAT, dSatLON, 128, 64);  // Get x/y for the pixel map
    status_sophy.satPos[0]=ixSAT;
    status_sophy.satPos[1]=iySAT;
    
  /* 
    // Calcualte footprint
    
    MySAT.footprint(aiSatFP, (sizeof(aiSatFP)/sizeof(int)/2), MAP_MAXX, MAP_MAXY, dSatLAT, dSatLON);
    
    for (int iz = 0; iz < (sizeof(aiSatFP)/sizeof(int)/2); iz++)
    {
      Log::console("%2d: x = %d, y = %d\r\n", iz, aiSatFP[iz][0], aiSatFP[iz][1]);
    }
  */

    if (logOut) {
    //  Log::console("tv.sec",tv.tv_sec);

      /*  For UNO instead of Serial.printf
      sprintf(buf, "\r\n\Prediction for %s at %s (MAP %dx%d: x = %d,y = %d):\r\n\r\n", MySAT.name, MyQTH.name, MAP_MAXX, MAP_MAXY, ixQTH, iyQTH);
      Serial.print(buf);
      */

      Log::console("%s - Prediction for %s from %s (Lat=%.4f Lon=%.4f, MAP %dx%d: x=%d,y=%d):\r\n Lat=%.4f Lon=%.4f (MAP %dx%d: x=%d,y=%d) Az=%.2f El=%.2f", acBuffer, MySAT.name, MyQTH.name, (MyQTH.LA * RAD_TO_DEG), (MyQTH.LO * RAD_TO_DEG), MAP_MAXX, MAP_MAXY, ixQTH, iyQTH, dSatLAT, dSatLON, MAP_MAXX, MAP_MAXY, ixSAT, iySAT, dSatAZ, dSatEL);
  //  Log::console("%s -> Lat: %.4f Lon: %.4f (MAP %dx%d: x = %d,y = %d) Az: %.2f El: %.2f\r\n\r\n", acBuffer, dSatLAT, dSatLON, MAP_MAXX, MAP_MAXY, ixSAT, iySAT, dSatAZ, dSatEL);

    //  Log::console("RX: %.6f MHz, TX: %.6f MHz\r\n\r\n", MySAT.doppler(dfreqRX, P13_FRX), MySAT.doppler(dfreqTX, P13_FTX));

    //  Serial.println("Satellite footprint map coordinates:");
    //  Log::console("Satellite footprint map coordinates:\n\r");
    }
  }
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
    configManager.setConfiguredCallback(NULL);
    configManager.setWifiConnectionCallback(NULL);
    Log::console(PSTR("FATAL ERROR: The board is in a boot loop, rescue mode launched. Connect to the WiFi AP: %s, and open a web browser on ip 192.168.4.1 to fix your configuration problem or upload a new firmware."), configManager.getThingName());
    return;
  }
  // make sure to call doLoop at least once before starting to use the configManager
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
  {
    static bool updateAttepted = false;
    if (!updateAttepted && configManager.isConnected()) {
      updateAttepted = true;
      OTA::update(); // try to update as last resource to recover from this state
    }

    if (millis() > 10000 || updateAttepted)
      configManager.forceApMode(true);
    
    return;
  }

  ArduinoOTA.handle();
  handleSerial();

  if (configManager.getState() < 2) // not ready or not configured
  {
    displayShowApMode();
    return;
  }
  
  // configured and no connection
  checkButton();
  if (radio.isReady())
  {
    status.radio_ready = true;
    radio.listen();
  }
  else {
    status.radio_ready = false;
  }

  if (configManager.getState() < 4) // connection or ap mode
  {
    displayShowStaMode(configManager.isApMode());
    return;
  }

  // connected
  check_azel(10000);
  mqtt.loop();
  mqtt_sophygs.loop();
  OTA::loop();
  if (configManager.getOledBright() != 0) displayUpdate();

}

void setupNTP()
{
  NTP.setInterval (120); // Sync each 2 minutes
  NTP.setTimeZone (configManager.getTZ()); // Get TX from config manager
  NTP.onNTPSyncEvent (ntp_cb); // Register event callback
  NTP.setMinSyncAccuracy (2000); // Sync accuracy target is 2 ms
  NTP.settimeSyncThreshold (1000); // Sync only if calculated offset absolute value is greater than 1 ms
  NTP.setMaxNumSyncRetry (2); // 2 resync trials if accuracy not reached
  NTP.begin (ntpServer); // Start NTP client
  Serial.printf ("NTP starting... ");
  
  time_t startedSync = millis ();
  while (NTP.syncStatus() != syncd && millis() - startedSync < 5000) // Wait 5 seconds to get sync
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
    else if (millis() - buttPressedStart > RESET_BUTTON_TIME) // long press
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
    if (elapsedTime > 30 && elapsedTime < 1000) // short press
      displayNextFrame();
    buttPressedStart = 0;
  }
}

void handleSerial()
{
  if(Serial.available())
  {
    radio.disableInterrupt();

    // get the first character
    char serialCmd = Serial.read();

    // wait for a bit to receive any trailing characters
    configManager.delay(50);

    // dump the serial buffer
    while(Serial.available())
    {
      Serial.read();
    }

    // process serial command
    switch(serialCmd) {
      case 'a':
        check_azel(2000, true);
        break;
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

// function to print controls
void printControls()
{
  Log::console(PSTR("------------- Controls -------------"));
  Log::console(PSTR("t - change the test mode and restart"));
  Log::console(PSTR("e - erase board config and reset"));
  Log::console(PSTR("b - reboot the board"));
  Log::console(PSTR("p - send test packet to nearby stations (to check transmission)"));
  Log::console(PSTR("a - azimuth and elevation selected satellite"));
  Log::console(PSTR("------------------------------------"));
}