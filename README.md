## Express server and Arduino file
This repository is an express server for communicating with serial port to Arduino

### test.ino
This file is for Arduino
Load this file at Arduino IDE
Compile and load to Arduino machine
Close Arduino and execute express  (if IDE isn't closed then serial port is opened to the IDE still)
Send request to communicate

### index.js
This file is for express server
Before start, you should check COM port and serial port number
When Arduino machine is running, you can ask request