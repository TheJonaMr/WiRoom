const char * const extensions[9] = {".ico", ".php", ".css", ".jpg", ".ttf", ".htm", ".gif", ".txt", ".js"};
const char * const contentType[9] = {"image/x-icon", "text/html", "text/css", "image/jpeg", "application/octet-stream", "text/html", "image/gif", "text/plain", "application/javascript"};
const char * const reqLoggin[5] = {"index.htm", "Subpages/control.htm", "users.txt", "cookie.htm", "valCie.txt"};
/*const char * const httpReqHeaders[16] = {"GET", "POST", "Host", "Connection", "Pragma", "Cache-Control", "Accept", 
                                           "Upgrade-Insecure-Requests", "User-Agent", "Accept-Encoding", "Accept-Language", "Cookie", 
                                           "Content-Length", "Referer", "Origin", "ajaxData"};*/

bool LoggedIn;
byte cookieCount = 0;

void handler(String path, String postData, String cookie){
  LoggedIn = validUser(postData, cookie);

  for (int x = 0; x < 8; x++) 
    if(path.indexOf(extensions[x]) >=0) {
      client.print(F("HTTP/1.1 200 OK\nContent-Type: "));
      client.println(String(contentType[x]) + '\n');
    }

  File file = SD.open(path);
  if (file) while (file.available()) client.write(file.read());
  file.close();
}

bool validUser(String userCred, String cookie) {
  String userData[6] = {"", "", "", "", "", ""};
  String username, readCookie = "";
  char c;
  int pswIndex, usernameLength = 0;
  byte userDataIndex = 0;

  if (userCred != ""){
    userCred.remove(0, 9);
    pswIndex = userCred.indexOf(F("&password="));
    for (int i = 0; i < pswIndex; i++) {
      username += userCred[i];
    }
    userCred.remove(0, pswIndex + 10);
  
    File userDir = SD.open("/users");
    while (true) {
      File userFile = userDir.openNextFile();
      if (!userFile) break; // no more files
      else if (userFile.isDirectory()) break;
      
      userData[0] = userFile.name();
      if (userData[0] == "USER_T~1.TXT") break; // no more files
      
      userDataIndex++;
      
      while (userFile && userFile.available()) {
        c = char(userFile.read());
        if (c == '\n') userDataIndex++;
        else userData[userDataIndex] += c;
      }
      userFile.close();
  
      for (int i = 1; i < 5; i++) userData[i].remove(userData[i].length() - 1, userData[i].length());
  
      if (username == userData[1] && userCred == userData[2]) {
        return true;
      }
      
      for (int i = 0; i < 6; i++) Serial.println(userData[i]);
      for (int i = 0; i < 6; i++) userData[i] = "";
      userDataIndex = 0;
    }
  }
  else if (cookie != "") {
    File cookieDir = SD.open("/users/cookie");
    while (true) {
      File userCookieFile = cookieDir.openNextFile();
      if (!userCookieFile) break; // no more files
      while (userCookieFile && userCookieFile.available()) {
        c = char(userCookieFile.read());
        readCookie += c;
        if (c == '\n') {
          readCookie.remove(readCookie.length() - 2);
          //Serial.println("fileContent=" + fileContent);
          if (cookie.equals(readCookie)) {
            userCookieFile.close();
            return true;
          }
          else readCookie = "";
        }
      }
      userCookieFile.close();
    }
  }
  else Serial.println(F("No userData"));
  return false;
}

/*Ha 4 connections åpne samtidig, avslutt connection etter 5 min uten flowing data
 *
 *
 *if client == client keep on going
 *else if !number of clients is 4, add new client
 *
 */

