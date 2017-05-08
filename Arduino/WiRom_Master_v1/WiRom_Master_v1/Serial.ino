/*void _serial()
{
  if (serialReadString.indexOf("DONE") < 0)
  {
    if (Serial.available() > 0 ) serialReadString += char(Serial.read());
    
    if (serialReadString.indexOf("Print") >= 0) 
    {
      serialReadString.remove(serialReadString.indexOf("Print"), 5);
      Serial.println("serialReadString = " + serialReadString);
    }
    if (serialReadString.indexOf("Clear") >= 0) serialReadString = "";
  }
}*/
