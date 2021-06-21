//This file is for Arduino
//Load this file at Arduino IDE
//Compile and load to Arduino machine
//Close Arduino and execute express  (if IDE isn't closed then serial port is opened to the IDE still)
//Send request to communicate

/* Arduino USB HID Keyboard Demo
 * Random Key/Random Delay
 */
 uint8_t buf[8] = { 0 }; /* Keyboard report buffer */
 
 String test2;
void setup(){
    Serial.begin(9600);
    pinMode(LED_BUILTIN, OUTPUT);
}
 
void loop(){
  /*
      String str = "i";
 int str_len = str.length() + 1;
 char arr[7];
   str.toCharArray(arr, 7); 
 String test4 = String(arr[0]);
 Serial.println(arr[0] == "i");
for (byte i = 1; i < 2; i = i + 1) {
  
  //getScanCode(arr, i);
 //Serial.println(test2);
}
  */
    if(Serial.available()){
         digitalWrite(LED_BUILTIN, HIGH);      // LED 켜짐 . 디지털 신호 1 (HIGH) 을 준다.
 
  delay(1000);                          //1000밀리초 (=1초) 동안 기다린다. 
 
  digitalWrite(LED_BUILTIN, LOW);  
  
      String str = Serial.readString();
 int str_len = str.length() + 1;
 char arr[8];
   str.toCharArray(arr, 8); 
  String first = String(arr[0]);   
   if (first == "i") {

for (byte i = 1; i <= 7; i = i + 1) {
  //Serial.println(arr[i]);
  
  buf[0] = 0;
  getScanCode(arr, i);
  delay(10);
  releaseKey();  
  
}
Serial.println(1);
   }

  //Serial.println(Serial.readString());
        //in_data = Serial.parseInt();
    }
     else {      
      //Serial.println(1);
    }
    delay(500);
}

void releaseKey()
 {
 buf[0] = 0;
 buf[2] = 0;
 Serial.write(buf, 8); // Release key
 }

 void getScanCode(char v[], int a) {  
  int val = v[a] - '0';
  switch (val) {
  case 1:
  buf[2] = 0x1E;
  break;
  case 2:
  buf[2] = 0x1F;
  break;
  default:
  break;
  }
 }