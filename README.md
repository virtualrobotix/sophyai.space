<p align="center">
<img src="/doc/images/SophyAI Final.jpg" width="400">
</p>
<p align="center">
<img src="/doc/images/Sophyai.space-observation.png" width="600">
</p>
<p align="center">
<img src="/doc/images/Sophyai.space-smart-dashboard.png" width="600">
</p>


SophyGS is an open source firmware fork of TinyGS . It's connected to an open network of Ground Stations distributed around the world to rtx and operate LoRa satellites, weather probes and other flying objects, using cheap and versatile modules. Share info with  sophyai.space network that is a specific network for realtime rtx comunication with lora satellite as FEES cubesat and future mavlink based cubesat .

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

# SophyGS network Configuration

Check our wiki [configuration page](https://github.com/virtualrobotix/sophyai.space/wiki/Ground-Station-configuration)


# Main data website sophyai.space
All data recived in realtime are share in our alfa version of DashBoard 

[http://sophyai.space:1880/worldmap/](http://sophyai.space:1880/worldmap/)

# OTA update and Auto Tuning

Once your Ground Station is alive and connected it can be automagically updated with the last version by the server via [OTA](https://github.com/G4lile0/tinyGS/wiki/OTA-Update).

Also the Ground stations can be remote configured automagically ([Auto Tuning](https://github.com/G4lile0/tinyGS/wiki/Radio-Tuning-Guide)) to be able to hear the next satellite pass with the correct settings.

Both systems are optional and you can opt-out at your Ground Station configuration, for example if you want to only support one specific satellite. But we recommend activating both to maintain the network health.

# SophyAI.space GS History
In 2016 we decide to develop our first cubesat . The name of cubesat is Fees . It derive of my experience 12 year of experience in Ardupilot drone. 
Fees was launch in March 2021 . After some days in space we understand that 1 gs is not enought for control our satellite . So decide to implement our bi directional realtime global ground station . We start from idea of TinyGS project they did a great job , but we need a realtime network and reliable uplink around the world. 
So we decide to start with this great project. 

# Contribute

You can contribute to by projects

- Providing Pull Requests (Features, Proof of Concepts, Language files or Fixes)
- Testing new released features and report issues
- Contributing missing documentation for features and devices templates


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

# Sophyai.space Team
- [Roberto Iu2IOL](https://github.com/virtualrobotix)
- [Iw2LSI](https://github.com/iw2lsi)
- [KanyonKris](https://github.com/KanyonKris)


# TinyGS team
Thanks to TinyGS developer team for the work done on TinyGS client . Our first revision of client was a fork of tinyGS work:
- [4m1g0] (https://github.com/4m1g0)
- [G4lile0] (https://github.com/G4lile0)
- [gmag11] (https://github.com/gmag11)


# Discord community of Sophyai.space project 
Join us at our Discord channel this is the link : https://discord.gg/ZvaRrRuTFC we need arduino developer , and Radio Ham with regular licence for try the connection (RTX) with satellite in our network , and user for recive the radio packet from lora satellite around the globe.

# Faq about Sophyai.space fork
**What is FEES cubesat ?** 
Fees is an Ham Satellite developed by small company  in italy you can found the full story here http://www.lasernavigation.it/the-cubesat-fees-flexible-experimental-embedded-satelliteproject-update/ , my contribution on project is in the hardware tecnology it’s derived by other hardware called VRBrain based on STM32 micro processor that support opensource ardupilot firmware for DIY drones , we have a huge opensource community that work with our hardware and other compatibile ,too like pixhawk. I start my work in opensource community with drone 13 years ago , the cubesat from my point of view is a great opportunity and only an evolution of a drone tecnology, and my personal target for hobby and R&D  is to develop a mavlink protocol compatibile with the space . All is opensource and available on our github and our community.
Fees was the first prototype of this kind of sat already in the space . In one special version we demostrated that it’s already compatibile with ardupilot inside . The version in the space don’t use yet ardupilot because we did not ready with the a stable firmware for space that could be available in the next version of satellite.Until now we start do develop a ardupilot sat simulator based on sophyai.space network and tecnology.
What i  learn in first 3 months is space need for define the functionality of new network. 
That kind of work will be in future available for research lab , university , ham community to learn more about space and cubesat tecnology.

**Why we don’t use TinyGS as it is and did a fork  ?** 
The actual architecture of  TinyGS technology from our point of view is not usable for develop a opensource realtime communication protocol with opensource satellite in the space , ma vision is quite different respect of what actually did in tinyGS project .One of big limit of actual TinyGS architecture is that it don’t support realtime comunication and complex protocol . Our target is to support mavlink protocol in realtime wiht this new revision of gs.  So i start the fork and share my work with the community.
In sophyai.space network tecnology we add : 
•    The support for realtime comunication with the node of network that decide to join to different experiment.
•    Local antenna tracking on gs with support of servo or serial protocol (WIP).
•    A small desktop app for interconnect a sat operator or virtual sat operator ground station to the network for inject payload in the network and for recived directly reply for gs around the world . For my point of view a sat operator is equivalent of pilot of drone with his ground station app nothing else. So could be an ham group that decide to send in space or in air by a ballon its cubesat experiment and want control around the world .
•    A new prototype back end able to manage a small group of realtime gs for doing experiment. 
Work in progess:
•    a new mavlink protocol comaptibile with space enviroment. For more info about mavlink check here : http://mavlink.io/en/
•    A simulator of ardupilot cubesat available for all the user that want to test it . 
•    A new opensource hardware for design an education cubesat.

**What mean realtime protocol to comunicate with satellite ?** 
Realtime protocol is a protocol where you have less 1 second from request and reply of your packet to and from drone or cubesat. 
What kind of feature could have a realtime protocol : 
1)    Set and Get parameter to the sat. : On a drone we normally have around 250 parameter to get and set so we need a very fast protocol for get or set it .
2)    Dowload from sat file , image , high res telemetry data . 
3)    Uploading new firmware or batch of parameter . 
4)    Uploading new script for doing special experiment on cubesat .
5)    Sharing the resource of cubesat with community , make a picture , receive a iot relay signal , doing benchmark on antenna , amplifier , sdr algorithms ecc.

**Why we continue to share data with tinyGS project on gs that use our custom firmware ?**
When we add the realtime network support on tinygs code and release all code , patch ecc as in GPLv3 licence request we mantain the compatibility with tinygs for continue to send the data collected by our network to tinygs , too  … thats don’t happen viceversa for the internal backend architecture of tinygs.
**lates update about sharing data with tinygs network: for reason that depend of tinygs network owner we stop to share the data with tinygs**.

**About the ardupilot sat project**
our teams support actively the development of ardupilot sat project .
we are working on early version of simulator that will be online in the next weeks on our network.
this is the link to ardupilot no profit organization for more info : https://ardupilot.org/ 

**what is virtualrobotix**
virtualrobotix is old brand of our drone community where in the past we develop some autopilot hardware like vrbrain that support opensource arudpilot firmware in its different revision.

# License

This program is licensed under GPL-3.0
