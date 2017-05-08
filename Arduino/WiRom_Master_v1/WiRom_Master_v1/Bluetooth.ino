/*void _bluetoothSend(){
  //serialReadString.remove(0, 2);
  Serial.println("_bluetoothSend = " + serialReadString);
  Serial1.println(serialReadString);
  serialReadString = "";
} //end void _bluetoothSend()

void _bluetoothReceive(){
  while (Serial1.available() > 0 ) {
    serial1ReadString += char(Serial1.read());
    //serial1ReadString.remove(serial1ReadString.indexOf("\n") - 1, 2);
    Serial.print(serial1ReadString);
    serial1ReadString = "";
  }
} //end void _bluetoothReceive()*/
