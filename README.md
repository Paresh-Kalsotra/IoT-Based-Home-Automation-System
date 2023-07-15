# IoT-Based-Home-Automation-System
**ABOUT THE PROJECT:**
The IoT-based home automation system is designed around an ESP32 controller and integrates with the Blynk app, enabling seamless remote control of various home appliances.
Created a simple interface on the blynk app to remotely control the appliance through relays(lights,fan,ac etc can be turned ON/OFF remotely) 
One of the core features of this system is the utilization of a Passive Infrared (PIR) sensor to detect the presence of a person.When the PIR sensor detects motion, it triggers a relay that turns on the lights in the vicinity. Conversely, when no motion is detected, the system automatically switches off the lights.
This automatic lighting functionality ensures that the lights are only active when someone is present, promoting energy efficiency, conserving energy and reducing unnecessary electricity consumption.
By combining the power of the ESP32 controller, Blynk app, and PIR sensor, this home automation system streamlines the control of home appliances and optimizes the lighting system, making it more intelligent and responsive to the presence of individuals in the home. It can be integrated with almost all the home appliances and can be used to control them remotely from any part of the world over internet.

# Hardware components Used:
1.	ESP32
2.	PIR sensor
3.	Jumper Wires
4.	4-channel Relay Module
5.	Jumper wires
6.	Switch board
7.	Light bulb and others

# Software setup:
1.	Wrote a sketch on the Arduino IDE and uploaded it  on the esp32.
2.	Used the blynk app to create virtual switches, to remotely control the appliances.

# Blynk interface:
**Blynk template and Device for virtual switches**
![Screenshot (404)](https://github.com/Paresh-Kalsotra/IoT-Based-Home-Automation-System/assets/83598734/8d8259b1-98c2-4cf2-9b65-ae5f25b81508)
![Screenshot (402)](https://github.com/Paresh-Kalsotra/IoT-Based-Home-Automation-System/assets/83598734/62056c27-75f5-463a-9105-d18801e99a78)
![Screenshot (405)](https://github.com/Paresh-Kalsotra/IoT-Based-Home-Automation-System/assets/83598734/db12a15e-eca6-4c6d-986d-b7141adbbf5e)
