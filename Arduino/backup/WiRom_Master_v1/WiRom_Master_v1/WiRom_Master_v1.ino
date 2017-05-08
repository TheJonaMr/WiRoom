//Code for Ethernet
#include <SPI.h>
#include <Ethernet.h>
#include <SD.h>

#define REQ_BUF_SZ 30
#define SERIAL_BUFFER_SIZE 32

byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
//IPAddress ip(192, 168, 1, 200);

String serialReadString = "";
String serial1ReadString = "";

long _time;

EthernetServer server(80);
EthernetClient client;

//General Code
void setup() {
  // disable Ethernet chip
  pinMode(10, OUTPUT);
  pinMode(13, OUTPUT);
  digitalWrite(10, HIGH);
  
  Serial.begin(9600);
  Serial1.begin(9600);

  // initialize SD card
  if (!SD.begin(4)) {
    Serial.println(F("No SD card detected"));
    return;    // init failed
  }
  
  // start the Ethernet connection and the server:
    Ethernet.begin(mac);
    server.begin();
    Serial.print(F("server@"));
    Serial.println(Ethernet.localIP());

    _time = getTime();
    Serial.println(_time);
  }

void loop() {
  _ethernet();
  
  /*_serial();
  _bluetoothReceive();
  
  if (serialReadString.indexOf("DONE") >= 0) {
    serialReadString.remove(serialReadString.indexOf("DONE"), 4);    
    _bluetoothSend();
  }*/
}

long getTime() {
  char timeServer[] = "nist.time.gov";
  String readString, epochTime = "";

  if (client.connect(timeServer, 80)) {
    //Serial.println(F("connected to Time Server"));
    // Make a HTTP request:
    client.println(F("GET http://www.time.gov/actualtime.cgi?lzbc=siqm9b HTTP/1.1"));
    client.println(F("Host: www.time.gov"));
    //client.println(F("User-Agent: arduino-ethernet"));
    //client.println(F("Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8"));
    //client.println(F("Accept-Language: en-US,en;q=0.5"));
    //client.println(F("Accept-Encoding: gzip, deflate"));
    //client.println(F("Connection: keep-alive"));
    //client.println(F("Upgrade-Insecure-Requests: 1"));
    client.println();
  }
  
  while (true){
    if (client.available()) {
      char c = client.read();
      readString += c;
      if (c == '\n') readString = "";
      else if (readString.indexOf(F("<timestamp time=")) == 0) epochTime += c;
    }
    if (!client.connected()) {
      //Serial.println(F("disconnecting from Time Server"));
      client.stop();
      epochTime.remove(0, 2);
      epochTime.remove(10, epochTime.length());
      return epochTime.toInt();
    }
  }

  //50 days 4320000 --- 0004320000
  //1492730971 --- GMT: Thu, 20 Apr 2017 23:29:31 GMT
  //1492737415 --- GMT: Fri, 21 Apr 2017 01:16:55 GMT
  
  //0004320000    //sec
  //1492737415    //sec
  //0000000005126 //milli
}

