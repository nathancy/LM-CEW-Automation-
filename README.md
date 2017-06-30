# Liquid-Metal Electronics

```
Project Overview Video
```

[![Video](http://img.youtube.com/vi/lNZG33T3vko/0.jpg)](https://www.youtube.com/watch?v=lNZG33T3vko)

Repository that holds code to control an Arduino microcontroller and capacitive displacement sensors to automate the process of continuous electrowetting. This implementation enables accurate positional control by utilizing a microcontroller and positional feedback sensors using the [Capacitive Sensing Library](http://playground.arduino.cc/Main/CapacitiveSensor?from=Main.CapSense) to directly improve liquid metal testing.

# Modules

1. Full Integration module
2. Isolated sensor-reading module
3. Isolated positional input module
4. Isolated voltage trigger module

# Developers Guide

1.	Attach capacitive displacement sensors to the Arduino Mega
2.	Select Arduino Mega in the Arduino IDE
3.	Run `CEW_Automation.ino` in the Arduino IDE
4.	Open the serial monitor and input desired liquid metal position 

For project history and implementation: [Continuous Electrowetting Automation](http://www.nathan-lam.com/projects/continuous-electrowetting-automation)