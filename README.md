<p align="right">
<img src="/doc/images/TinyGS_logo.png" width="400">
</p>
<p align="left">
<img src="/doc/images/SophyAI Final.jpg" width="400">
</p>


SophyGS is an open source firmware fork of TinyGS . It's connected to an open network of Ground Stations distributed around the world to rtx and operate LoRa satellites, weather probes and other flying objects, using cheap and versatile modules. Our revision of firmware connect TinyGS network and share info with this network and sophyai.space network that is a specific network for realtime rtx comunication with lora satellite as FEES cubesat.

# Hardware

This project is based on ESP32 boards and currently it is compatible with sx126x and sx127x LoRa módules but we plan to support more radio módules in the future.

Currently we are officially supporting the following proven LoRa boards:

- **Heltec WiFi LoRa 32 V1 (433MHz &amp; 863-928MHz versions)**
- **Heltec WiFi LoRa 32 V2 (433MHz &amp; 863-928MHz versions)**
- **TTGO LoRa32 V1 (433MHz &amp; 868-915MHz versions)**
- **TTGO LoRa32 V2 (433MHz &amp; 868-915MHz versions)**
- **TTGO LoRa32 V2 (Manually swapped SX1267 to SX1278)**
- **T-BEAM + OLED (433MHz &amp; 868-915MHz versions)**
- **T-BEAM V1.0 + OLED**
- **FOSSA 1W Ground Station (433MHz &amp; 868-915MHz versions)**
- **ESP32 dev board + SX126X with crystal (Custom build, OLED optional)**
- **ESP32 dev board + SX126X with TCXO (Custom build, OLED optional)**
- **ESP32 dev board + SX127X (Custom build, OLED optional)**

However, any ESP32 board with sx126x or sx127x módule can be configured using templates. You can find more info about them [here](https://github.com/G4lile0/tinyGS/wiki/Board-Templates).

# Install
The first time you flash your board you can use the [one click uploader](https://github.com/iw2lsi/SophyaiGS-Uploader) available for Linux, Windows and Mac. You can find instrictions [here](https://github.com/iw2lsi/SophyaiGS-Uploader).

You can also download the latest [release](https://github.com/virtualrobotix/sophyai.space/tree/main/release) and flash it with PlatformIO. If you dont know PlatformIO here you have our [PlatformIO guide](https://github.com/virtualrobotix/sophyai.space/wiki/Platformio).

Later you can update your Ground Station via [local web OTA or auto update method](https://github.com/virtualrobotix/sophyai.space/wiki/OTA-Update).

You can also use Arduino IDE, but is a longer and hard path, because you need to install all dependencies. [Arduino guide](https://github.com/virtualrobotix/sophyai.space/wiki/Arduino-IDE)

# Configuration

Check our wiki [configuration page](https://github.com/virtualrobotix/sophyai.space/wiki/Ground-Station-configuration)


# Main data website sophyai.space
All data recived in realtime are share in our alfa version of DashBoard 

[http://sophyai.space:1880/worldmap/](http://sophyai.space:1880/worldmap/)



# OTA update and Auto Tuning

Once your Ground Station is alive and connected it can be automagically updated with the last version by the server via [OTA](https://github.com/G4lile0/tinyGS/wiki/OTA-Update).

Also the Ground stations can be remote configured automagically ([Auto Tuning](https://github.com/G4lile0/tinyGS/wiki/Radio-Tuning-Guide)) to be able to hear the next satellite pass with the correct settings.

Both systems are optional and you can opt-out at your Ground Station configuration, for example if you want to only support one specific satellite. But we recommend activating both to maintain the network health.

# Community

We are using Telegram as the main communication channel for the project. There are also two channels where you can subscribe and be updated automátically whenever a new packet is received by the network from the Satellite.

- [Main community chat](https://t.me/joinchat/DmYSElZahiJGwHX6jCzB3Q)
- [Data channel](https://t.me/tinyGS_Telemetry) station status and received packets
- [Test channel](https://t.me/TinyGS_Test) RX packets by groundstations in test mode

# SophyAI.space GS History
In 2016 we decide to develop our first cubesat . The name of cubesat is Fees . It derive of my experience 12 year of experience in Ardupilot drone. 
Fees was launch in March 2021 . After some days in space we understand that 1 gs is not enought for control our satellite . So decide to implement our bi directional realtime global ground station . We start from idea of TinyGS project they did a great job , but we need a realtime network and reliable uplink around the world. 
So we decide to start with this great project. 



# Contribute

You can contribute to SophyAIGS by

- Providing Pull Requests (Features, Proof of Concepts, Language files or Fixes)
- Testing new released features and report issues
- Contributing missing documentation for features and devices templates

# Documentation

Check our [wiki](https://github.com/G4lile0/tinyGS/wiki)!

# Project dependencies

This project relies on several third party libraries:

- RadioLib
- ArduinoJson
- ESP8266\_SSD1306
- IoTWebConf2
- PubSubClient
- ESPNTPClient
- FailSafeMode
- TinyGS 

# TinyGS team
The main TinyGS developer team is:
- 4m1g0
- G4lile0
- gmag11

# Sophyai.space Team
- [Roberto Iu2IOL](https://github.com/virtualrobotix)
- [Iw2LSI](https://github.com/iw2lsi)
- [KanyonKris](https://github.com/KanyonKris)

# Contributors SophyAIGS
Join us at our Discord channel this is the link : https://discord.gg/ZvaRrRuTFC we need arduino developer , and Radio Ham with regular licence for try the connection (RTX) with satellite in our network , and user for recive the radio packet from lora satellite around the globe.

# License

This program is licensed under GPL-3.0
