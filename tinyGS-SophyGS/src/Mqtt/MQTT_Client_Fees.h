/*
  MQTTClient.h - MQTT connection class
  
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
*/

#ifndef MQTT_CLIENT_FEES_H
#define MQTT_CLIENT_FEES_H
//#define SECURE_MQTT // Comment this line if you are not using MQTT over SSL
#define SECURE_MQTT_FEES // Comment this line if you are not using MQTT over SSL
#define LOG_TAG "MQTT"

#include "../ConfigManager/ConfigManager.h"
#include "../Status.h"
#define MQTT_MAX_PACKET_SIZE 1000
#include <PubSubClient.h>
#ifdef SECURE_MQTT_FEES
#include <WiFiClientSecure.h>

static const char DSTroot_CA_FEEES[] PROGMEM = R"EOF(
-----BEGIN CERTIFICATE-----
MIIDnTCCAoWgAwIBAgIUc6Ua9ifFTZV4Pq59gUGujjwnlXEwDQYJKoZIhvcNAQEL
BQAwXTELMAkGA1UEBhMCSVQxEDAOBgNVBAgMB0JlcmdhbW8xITAfBgNVBAoMGElu
dGVybmV0IFdpZGdpdHMgUHR5IEx0ZDEZMBcGA1UEAwwQc29waHlhaV9zYXRfbXF0
dDAgFw0yMTA0MjIxMjE2MThaGA8yMTIxMDMyOTEyMTYxOFowXTELMAkGA1UEBhMC
SVQxEDAOBgNVBAgMB0JlcmdhbW8xITAfBgNVBAoMGEludGVybmV0IFdpZGdpdHMg
UHR5IEx0ZDEZMBcGA1UEAwwQc29waHlhaV9zYXRfbXF0dDCCASIwDQYJKoZIhvcN
AQEBBQADggEPADCCAQoCggEBALJbLWWmtQ/jE4gNANbFsoUkm3m1AOA0u9Btmg1g
sq7C8L7xOALHmRkcjGhuVBZz1Tg93UWT83hjTW43YSA/EnOEwdB6if+kH2dbR4p6
bfVcznB43AY+3yK8HAf+20H+TkKkpWxqjRdLL8QbGCTEXz9lLTPpJ1812RtsYzPS
VJ9XarJWSI69K7+M4KwgIcTuYvy7XAulNtLsSyfKB2WTtSFlqyp4pr4Akiwq/+PF
sAT1gdX/xYWQj68DRvr1ipCdBgIkCVJ6DrAPGWpypm6yCaFUs9n9+FtWGT0Ahdxx
RLHeKblDkusIqz3pgimqFFbqs7fxJAvKE8v+4ttIOVZw8FECAwEAAaNTMFEwHQYD
VR0OBBYEFFueHEHzm+8BBX9Ndz4unOjr7vmpMB8GA1UdIwQYMBaAFFueHEHzm+8B
BX9Ndz4unOjr7vmpMA8GA1UdEwEB/wQFMAMBAf8wDQYJKoZIhvcNAQELBQADggEB
AGSDno8bayOmdUigoNu1SRaPOmg1M5vFLWx2+0JIBaTI1SmrISdz1kJGelv3+qbj
0SpQx/3gqOcg9IglSbA1P5PGtfdT+o7/lTTRRgS87AAZHYvBveTk8LjjbDSrht/n
AXb0Xn/lH/rR3Bj2bjzawXl2T+XcCEU7JRF1l/+L6+C/ME8NongN30vR3zW2ZX64
BceW2XpuSxmsWHqK9OoK9tWNU/hAh8ccWNN5qqNSN34Za4HJoQOpjP9pKgApZtSE
OPY8ODmTO7ZiAVOjLwdqErzGCXUotbioSlc6v+9YlOfOnw07gIRYhcuJ1yXhunil
6ZtQv+jVf4o9g3SOBjxqjwA=
-----END CERTIFICATE-----)EOF";
#else
#include <WiFiClient.h>
#endif

// Global status (status_sophy)
extern Status status_sophy;

class MQTT_Client_Fees : public PubSubClient {
public:
  static MQTT_Client_Fees& getInstance()
  {
    static MQTT_Client_Fees instance; 
    return instance;
  }
  void begin();
  void loop();
  void sendWelcome();
  void sendPingExt();
  void sendRx(String packet, bool noisy);
  void manageMQTTDataFees(char *topic, uint8_t *payload, unsigned int length);
  void sendStatus();
  void scheduleRestart() { scheduledRestart = true; };

protected:
#ifdef SECURE_MQTT
  WiFiClientSecure espClient;
#else
  WiFiClient espClient;
#endif
  void reconnect();

private:
  MQTT_Client_Fees();
  String buildTopic(const char * baseTopic, const char * cmnd);
  void subscribeToAll();
  void manageSatPosOled(char* payload, size_t payload_len);
  void remoteSatCmnd(char* payload, size_t payload_len);

  unsigned long lastPing = 0;
  unsigned long lastConnectionAtempt = 0;
  uint8_t connectionAtempts = 0;
  bool scheduledRestart = false;

  const unsigned long pingInterval = 1 * 60 * 1000;
  const unsigned long reconnectionInterval = 5 * 1000;
  uint16_t connectionTimeout = 5 * 60 * 1000 / reconnectionInterval;

  const char* globalTopic PROGMEM = "sophyaispace/global/%cmnd%";
  const char* cmndTopic PROGMEM = "sophyaispace/%user%/%station%/cmnd/%cmnd%";
  const char* teleTopic PROGMEM = "sophyaispace/%user%/%station%/tele/%cmnd%";
  const char* statTopic PROGMEM = "sophyaispace/%user%/%station%/stat/%cmnd%";

  // tele
  const char* topicWelcome PROGMEM = "welcome";
  const char* topicPing PROGMEM= "ping";
  const char* topicPingExt PROGMEM= "ping";
  const char* topicStatus PROGMEM = "status";
  const char* topicRx PROGMEM= "rx";

  // command
  const char* commandBatchConf PROGMEM= "batch_conf";
  const char* commandUpdate PROGMEM= "update";
  const char* commandSatPos PROGMEM= "sat_pos_oled";
  const char* commandReset PROGMEM= "reset";
  const char* commandFreq PROGMEM= "freq";
  const char* commandBw PROGMEM= "bw";
  const char* commandSf PROGMEM= "sf";
  const char* commandCr PROGMEM= "cr";
  const char* commandCrc PROGMEM= "crc";
  const char* commandLsw PROGMEM= "lsw";
  const char* commandFldro PROGMEM= "fldro";
  const char* commandAldro PROGMEM= "aldro";
  const char* commandPl PROGMEM= "pl";
  const char* commandBegin PROGMEM= "begin";
  const char* commandBeginLora PROGMEM= "begin_lora";
  const char* commandBeginFSK PROGMEM= "begin_fsk";
  const char* commandBr PROGMEM= "br";
  const char* commandFd PROGMEM= "Fd";
  const char* commandFbw PROGMEM= "fbw";
  const char* commandFsw PROGMEM= "fsw";
  const char* commandFook PROGMEM= "fok";
  const char* commandFrame PROGMEM= "frame";
  const char* commandSat PROGMEM= "sat";
  const char* commandStatus PROGMEM= "status";
  const char* commandTest PROGMEM= "test";
  const char* commandRemoteTune PROGMEM= "remoteTune";
  const char* commandRemotetelemetry3rd PROGMEM= "telemetry3rd";
  const char* commandLog PROGMEM= "log";
  const char* commandTx PROGMEM= "tx";
  const char* commandTxB64 PROGMEM= "txB64";
  // GOD MODE  With great power comes great responsibility!
  const char* commandSPIsetRegValue PROGMEM= "SPIsetRegValue";
  const char* commandSPIwriteRegister PROGMEM= "SPIwriteRegister";
  const char* commandSPIreadRegister PROGMEM= "SPIreadRegister";
};

#endif