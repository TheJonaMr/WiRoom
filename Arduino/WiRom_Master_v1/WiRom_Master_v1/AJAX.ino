int num = 0;

void ajax(EthernetClient client, String postData) {
  //Serial.println("AJAX");
  //Serial.println(postData);
  client.println(F("HTTP/1.1 200 OK\nContent-Type: text/plain\n"));
  client.print(F("<h2>Text has been changed :D _"));
  client.print(String(num));
  client.println(F("_</h2>"));
  num++;

  if (postData.indexOf("&LED13=1") == 0) {
        digitalWrite(13, HIGH);
  }
  else if (postData.indexOf("&LED13=0") == 0) {
      digitalWrite(13, LOW);
  }
}
