#include <SoftwareSerial.h>

#define rxPin 8
#define txPin 9

SoftwareSerial SerialBT(rxPin, txPin); // RX, TX

String serialReadString = "";
String bluetoothReadString = "";

void setup() {
  //pinMode(rxPin2, INPUT);
  //pinMode(txPin2, OUTPUT);

  Serial.begin(9600);
  SerialBT.begin(9600);
}

void loop() {

  _serial();
  _bluetoothReceive();
  
  if (serialReadString.indexOf("DO") >= 0) {
    serialReadString.remove(serialReadString.indexOf("DO"), 3);
    _bluetoothSend();
  }
  
}
