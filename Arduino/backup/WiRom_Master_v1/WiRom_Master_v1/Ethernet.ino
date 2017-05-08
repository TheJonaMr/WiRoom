byte rip[] = {0,0,0,0};

String httpReq[16] = {"", "", "", "", "", "", 
                      "", "", "", "", "", "", 
                      "", "", "", ""};

//EthernetClient client;

void _ethernet(){

  String readString, postData = "";
  
  client = server.available();
  if (client) {
    
    client.getRemoteIP(rip);
    Serial.print(F("client@"));
    for (int bcount= 0; bcount < 4; bcount++)
    {
      Serial.print(rip[bcount], DEC);
      if (bcount<3) Serial.print(".");
    }
    Serial.println("");
     
      while (client.connected()) {
        while (client.available()) {
          char c = client.read();

          Serial.print(c);

          readString += c;
          if (c == '\n') readString = "";
          else if (readString.indexOf(F("GET ")) == 0 || readString.indexOf(F("POST ")) == 0) httpReq[0] += c;
          else if (readString.indexOf(F("Accept: ")) == 0) httpReq[5] += c;
          else if (readString.indexOf(F("Cookie: sessionID=")) == 0) httpReq[10] += c;
          else if (readString.indexOf(F("AJAXdat=")) == 0) httpReq[15] += c;
          
          
      } //end if (client.available())

      for (int i = 0; i < 16; i++) if (httpReq[i] != "") httpReq[i].remove(0, 1);
      httpReq[0].remove(httpReq[0].indexOf(F("HTTP/1.1")) - 1, httpReq[0].length());

      Serial.println();

      //Debugg Http Request Data
      Serial.print(F("httpReq[0]  = ")); //GET/POST
      Serial.println(httpReq[0]);
      Serial.print(F("httpReq[10] = ")); //Cookie
      Serial.println(httpReq[10]);
      Serial.print(F("httpReq[15] = ")); //AjaxData
      Serial.println(httpReq[15]);
      Serial.println();
            
      if (httpReq[0].equals(F("/"))) handler(F("/logon.htm"), httpReq[15], httpReq[10]);
      
      else if (httpReq[0].indexOf(F("/ax/")) >= 0) {        
        httpReq[0].remove(0 ,4);
        Serial.println(httpReq[0]);

        if (httpReq[0].indexOf(F("uD")) >= 0) handler(httpReq[0], httpReq[15], httpReq[10]);
        
        else Serial.println("No handler for " + httpReq[0]);
      }
      else if (httpReq[0] != "") {
        handler(httpReq[0], httpReq[15], httpReq[10]);
      }
      else Serial.println(F("WTF is dis?"));

      client.stop();

      readString, postData = "";
      for (int i = 0; i < 16; i++) httpReq[i] = "";
      
    } //end while (client.connected())
  } //end if (client)
} //end void _ethernet()
