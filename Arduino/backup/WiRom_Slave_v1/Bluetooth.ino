void _bluetoothSend(){
  Serial.println("BT_Send = " + serialReadString);
  SerialBT.print(serialReadString);
  serialReadString = "";  
} //end void _SerialBTSend()

void _bluetoothReceive(){
while (SerialBT.available() > 0 ) {
  bluetoothReadString += char(SerialBT.read());
  //SerialBT.remove(SerialBT.indexOf("\n") - 1, 2);
  Serial.print(bluetoothReadString);
  bluetoothReadString = "";  
  }
} //end void _SerialBTReceive()
