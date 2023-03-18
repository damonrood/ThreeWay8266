
/*************************************************************

  This is a simple demo of sending and receiving some data.
  Be sure to check out other examples!
 *************************************************************/


/* Fill-in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID "TMPLJd3EI3uQ"
#define BLYNK_TEMPLATE_NAME "ThreeWay"
#define BLYNK_AUTH_TOKEN "NI5cEj1kMras8DqVDBkDZMvSWwn5DVFi"

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial/* Configuration of NTP */





#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#include <ESP8266WiFi.h>
//#include <DNSServer.h>
//#include <ESP8266WebServer.h>
#include <WiFiManager.h>         // https://github.com/tzapu/WiFiManager
//#include <NTPClient.h>
//#include <WiFiUdp.h>
#include <time.h>
//#include <HTTPClient.h>
#include <FS.h>
//#include "datetime.h"
//#include <webSerial.h>
// Set web server port number to 80
WiFiServer server(80);
int currentTimeArr[5];
//NTPClient *_timeClient;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "YourNetworkName";
char pass[] = "YourPassword";
#define SET  4
#define RESET 13
//int currentRelayPin = 0;
//WiFiUDP ntpUDP;
//NTPClient timeClient(ntpUDP, "pool.ntp.org");
int led_gpio = 2;

int offset = -21600;
int dlstOffset = 3600;
int dlst = 0;
bool sliderMoved = false;
const char* ntpServer = "pool.ntp.org";
const long  gmtOffset_sec = -21600;   //Replace with your GMT offset (seconds)
const int   daylightOffset_sec = 3600;  //Replace with your daylight offset (seconds)
//NTPClient timeClient(ntpUDP, "pool.ntp.org", offset+dlstOffset, 60000);

int buttonPressed = 0;
//bool firstTime = true;
//int * retVal = NULL; 
//int ii = 0;
//int oldHour = 0;
//Week Days
//String weekDays[7]={"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
//Month names
//String months[12]={"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};




/*int* setCurrentTime();
    String readFile(fs::FS &fs, const char * path);
    void writeFile(fs::FS &fs, const char * path, const char * message);
*/
//loat moData[120];
long notificationTimer = 3600000;
long beginNotificationTimer = 0;
bool firstTimeNotification = true;
    long utcOffsetInSeconds = 0; 

//int randomTemp = 0;
bool sent = false;
int tab2 = 0;
int tab1 = 0;
int slider1 = 0;
int slider2 = 0;
//int dlst = 0;
int x = 0;
//float averageValue = 0.0;
//bool relaySet = false;
//bool lightToRelay = false;

// You should get Auth Token in the Blynk App.
//// Go to the Project Settings (nut icon).
char auth[] = BLYNK_AUTH_TOKEN;
int oldHour = 0;


int *curTimeArr;
int currentHour;
int currentMinute;
int currentDay;
//nt readValue = 0;
//int maxValue = 0;
//int minValue = 0;

const int current_sensor_pin = A0;  //four pins down on the left
//int sensor_max = 0;
//float amplitude_current = 0.0; //amplitude current
//float effective_value = 0.0; //effective current
//nt deviceState = 0;
//int device_on_current_threshold = 0;
//bool lightStarted = false;
//bool lightStopped = false;
bool wifiConnected = false;
bool newState();
//HTTPClient https;
bool blinking = false;
bool relayOff = true;
int startAMPM = 0;
int stopAMPM = 0;
int startHour= 0;
int stopHour = 0;
int schedulingOn = 0;
bool state = false;
bool buttonWasPressed = false;
BlynkTimer timer;

bool isDaylightSavingsTime();
void setTime();
int lightsState();
void flipSwitch();
void setStartTime(int amPm, int hr);
void setStopTime(int amPm, int hr);
void setWeb();
void writeFile(fs::FS &fs, const char * path, const char * message);
String readFile(fs::FS &fs, const char * path) ;

//void syncTime();

  BLYNK_WRITE(V0)  // button attached to Virtual Pin 1 in SWITCH mode
  {
    Serial.print("V0 is: ");
/*************************************************************

  This is a simple demo of sending and receiving some data.
  Be sure to check out other examples!
 *************************************************************/


/* Fill-in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID "TMPLJd3EI3uQ"
#define BLYNK_TEMPLATE_NAME "ThreeWay"
#define BLYNK_AUTH_TOKEN "NI5cEj1kMras8DqVDBkDZMvSWwn5DVFi"

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial/* Configuration of NTP */





#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#include <ESP8266WiFi.h>
//#include <DNSServer.h>
//#include <ESP8266WebServer.h>
#include <WiFiManager.h>         // https://github.com/tzapu/WiFiManager
//#include <NTPClient.h>
//#include <WiFiUdp.h>
#include <time.h>
//#include <HTTPClient.h>
#include <FS.h>
//#include "datetime.h"
//#include <webSerial.h>
// Set web server port number to 80
WiFiServer server(80);
int currentTimeArr[5];
//NTPClient *_timeClient;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "YourNetworkName";
char pass[] = "YourPassword";
#define SET  4
#define RESET 13
//int currentRelayPin = 0;
//WiFiUDP ntpUDP;
//NTPClient timeClient(ntpUDP, "pool.ntp.org");
int led_gpio = 2;

int offset = -21600;
int dlstOffset = 3600;
int dlst = 0;
bool sliderMoved = false;
const char* ntpServer = "pool.ntp.org";
const long  gmtOffset_sec = -21600;   //Replace with your GMT offset (seconds)
const int   daylightOffset_sec = 3600;  //Replace with your daylight offset (seconds)
//NTPClient timeClient(ntpUDP, "pool.ntp.org", offset+dlstOffset, 60000);

int buttonPressed = 0;
//bool firstTime = true;
//int * retVal = NULL; 
//int ii = 0;
//int oldHour = 0;
//Week Days
//String weekDays[7]={"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
//Month names
//String months[12]={"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};




/*int* setCurrentTime();
    String readFile(fs::FS &fs, const char * path);
    void writeFile(fs::FS &fs, const char * path, const char * message);
*/
//loat moData[120];
long notificationTimer = 3600000;
long beginNotificationTimer = 0;
bool firstTimeNotification = true;
    long utcOffsetInSeconds = 0; 

    bool firstTimeMove = true;
    bool firstTimeSlider1 = true;
    bool firstTimeSlider2 = true;

//int randomTemp = 0;
bool sent = false;
int tab2 = 0;
int tab1 = 0;
int slider1 = 0;
int slider2 = 0;
//int dlst = 0;
int x = 0;
//float averageValue = 0.0;
//bool relaySet = false;
//bool lightToRelay = false;

// You should get Auth Token in the Blynk App.
//// Go to the Project Settings (nut icon).
char auth[] = BLYNK_AUTH_TOKEN;
int oldHour = 0;


int *curTimeArr;
int currentHour;
int currentMinute;
int currentDay;
//nt readValue = 0;
//int maxValue = 0;
//int minValue = 0;

const int current_sensor_pin = A0;  //four pins down on the left
//int sensor_max = 0;
//float amplitude_current = 0.0; //amplitude current
//float effective_value = 0.0; //effective current
//nt deviceState = 0;
//int device_on_current_threshold = 0;
//bool lightStarted = false;
//bool lightStopped = false;
bool wifiConnected = false;
bool newState();
//HTTPClient https;
bool blinking = false;
bool relayOff = true;
int startAMPM = 0;
int stopAMPM = 0;
int startHour= 0;
int stopHour = 0;
int schedulingOn = 0;
bool state = false;
bool buttonWasPressed = false;
BlynkTimer timer;
int lastWrittenSchedOn = 0;
int k = 0;

bool isDaylightSavingsTime();
void setTime();
int lightsState();
void flipSwitch();
void setStartTime(int amPm, int hr);
void setStopTime(int amPm, int hr);
void setWeb();
//void syncTime();

  BLYNK_WRITE(V0)  // button attached to Virtual Pin 1 in SWITCH mode
  {
    Serial.print("V0 is: ");
    buttonPressed = 1;
    
    delay(200);
  }

  BLYNK_WRITE(V5)  // button attached to Virtual Pin 1 in SWITCH mode
  {
    //Serial.print("V0 is: ");
    dlst = 1;
    String strDlst = String(dlst);
    writeFile(SPIFFS,"dlst",strDlst.c_str());   
    delay(20);
  }

  BLYNK_WRITE(V4) {
    stopAMPM = param.asInt();
    String strStopAMPM = String(stopAMPM);
    writeFile(SPIFFS,"stopAMPM",strStopAMPM.c_str());
    Serial.print("stopAMPM is: ");
    Serial.println(stopAMPM);
    setStopTime(stopAMPM, tab2);
        String strSlider2 = String(slider2);
    writeFile(SPIFFS,"slider2",strSlider2.c_str());
  }  
  BLYNK_WRITE(V3) {
    startAMPM = param.asInt();
    String strStartAMPM = String(startAMPM);
    writeFile(SPIFFS,"startAMPM",strStartAMPM.c_str());
    setStopTime(startAMPM, tab1);
          String strSlider1 = String(slider1);
      writeFile(SPIFFS, "slider1", strSlider1.c_str());

  }  

  BLYNK_WRITE(V2) {
    tab2 = param.asInt();
    sliderMoved = true;

      
      setStopTime(stopAMPM, tab2);
    String strTab2 = String(tab2);
    writeFile(SPIFFS,"tab2",strTab2.c_str());
    String strSlider2 = String(slider2);
    writeFile(SPIFFS,"slider2",strSlider2.c_str());
      Serial.println(slider2);
  }

  BLYNK_WRITE(V1) {
    tab1 = param.asInt();
    sliderMoved = true;

  
        setStartTime(startAMPM,tab1);
     
      String strTab1 = String(tab1);
      writeFile(SPIFFS, "tab1", strTab1.c_str());
    
      String strSlider1 = String(slider1);
      writeFile(SPIFFS, "slider1", strSlider1.c_str());

  }

// This function is called every time the device is connected to the Blynk.Cloud
BLYNK_CONNECTED()
{
  // Change Web Link Button message to "Congratulations!"
  Blynk.setProperty(V3, "offImageUrl", "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations.png");
  Blynk.setProperty(V3, "onImageUrl",  "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations_pressed.png");
  Blynk.setProperty(V3, "url", "https://docs.blynk.io/en/getting-started/what-do-i-need-to-blynk/how-quickstart-device-was-made");
}

// This function sends Arduino's uptime every second to Virtual Pin 2.
void myTimerEvent()
{
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
 // Blynk.virtualWrite(V2, millis() / 1000);
}

void setup()
{
  // Debug console
  Serial.begin(115200);
  pinMode(led_gpio, OUTPUT);
  pinMode(SET,OUTPUT);
  digitalWrite(SET,LOW);
  pinMode(RESET,OUTPUT);
  digitalWrite(RESET,LOW);  
  delay(10);
  //configTime(MY_TZ, MY_NTP_SERVER); // --> Here is the IMPORTANT ONE LINER needed in your sketch!

/////////////////////////////8266 wifi //////////////////////
  // WiFiManager
  // Local intialization. Once its business is done, there is no need to keep it around
  WiFiManager wifiManager;
  // Uncomment and run it once, if you want to erase all the stored information
  //wifiManager.resetSettings();
  
  // set custom ip for portal
  //wifiManager.setAPConfig(IPAddress(10,0,1,1), IPAddress(10,0,1,1), IPAddress(255,255,255,0));

  // fetches ssid and pass from eeprom and tries to connect
  // if it does not connect it starts an access point with the specified name
  // here  "AutoConnectAP"
  // and goes into a blocking loop awaiting configuration
  wifiManager.autoConnect("Under_Cabinet_Lights");
  // or use this for auto generated name ESP + ChipID
  //wifiManager.autoConnect();
  
  // if you get here you have connected to the WiFi
  Serial.println("Connected.");
  
  server.begin();
///////////////////////////////////////////////////////////
//////////time ///////////
//setTimeDLST();

    //timeClient.begin();
    
    //timeClient.setTimeOffset(offset+dlstOffset);    
  setTime();
/////////////////////////
  Blynk.config(BLYNK_AUTH_TOKEN);
    while (Blynk.connect() == false) {
  }
    if (Blynk.connected()) {
    Serial.println("Wifi/Blynk started");
  } else {
    Serial.println("Check Router");
  }
  // You can also specify server:
  //Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, "blynk.cloud", 80);
  //Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, IPAddress(192,168,1,100), 8080);

  // Setup a function to be called every second
  timer.setInterval(1000L, myTimerEvent);
  
  // mount and check the filesystem
  bool ok = SPIFFS.begin();
  if (ok) {
    Serial.println("SPIFFS initialized successfully");
    }
  else{
    Serial.println("SPIFFS intialization error");
    }
    /////////////////
configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  //currentRelayPin = 0;
  //EEPROM.get(1, tab1);
  String Dlst = readFile(SPIFFS,"dlst");
  dlst = Dlst.toInt();
  Serial.print("dlst is ");
  Serial.println(dlst);
Blynk.virtualWrite(V5, dlst);
  
  String strTab1 = readFile(SPIFFS,"tab1");
  tab1 = strTab1.toInt();
  Serial.print("tab1 is ");
  Serial.println(tab1);
Blynk.virtualWrite(V1, tab1);  
   
     String strSlider1 = readFile(SPIFFS,"slider1");
  slider1 = strSlider1.toInt();
  Serial.print("slider1 from eeprom is ");
  Serial.println(slider1);
  
  String strTab2 = readFile(SPIFFS,"tab2");
  tab2 = strTab2.toInt();
  Blynk.virtualWrite(V2, tab2);
  
   String strSlider2 = readFile(SPIFFS,"slider2");
  slider2 = strSlider2.toInt();
  Serial.print("slider2 from eeprom is ");
  Serial.println(slider2);

  String strStartAMPM = readFile(SPIFFS,"startAMPM");
  startAMPM = strStartAMPM.toInt();
    Serial.print("in set up startAMPM is ");
  Serial.println(startAMPM);
  Blynk.virtualWrite(V3, startAMPM);
  
  String strStopAMPM = readFile(SPIFFS,"stopAMPM");
  stopAMPM = strStopAMPM.toInt();
  Serial.print("in set up stopAMPM is ");
  Serial.println(stopAMPM);
  Blynk.virtualWrite(V4, stopAMPM);

    
  String scheduOn = readFile(SPIFFS,"schedOn");
  schedulingOn = scheduOn.toInt();
}

void loop()
{
  k++;
  if (WiFi.status() != WL_CONNECTED)
  {
    Serial.println("LOST WiFi restarting");
    //atoAwcUtil->webSerialWriteLine("LOST WiFi restarting");
    ESP.restart();
  }
  Blynk.run();
  timer.run();
  // You can inject your own code or combine it with other sketches.
  // Check other examples on how to communicate with Blynk. Remember
  // to avoid delay() function!
  if(blinking){
    digitalWrite(led_gpio, 0);
    blinking = false;
  }else{
    digitalWrite(led_gpio, 1);
    blinking = true;
  }


  if(buttonPressed){ 
    buttonWasPressed = true;
    flipSwitch();//push latch relay
    buttonPressed = 0;
  }
    /////////////////// do schedule //////////////////////
  setTime();
  //setStartTime(startAMPM, tab1);
  //setStopTime(stopAMPM,tab2);
  /*Serial.print("HOUR_________________");
  Serial.print(currentTimeArr[3]);
  Serial.print("SLIDERS____________________");
  Serial.print(slider1);
   Serial.print("SLIDERS____________________");
 Serial.println(slider2);*/
if(sliderMoved && (currentTimeArr[3] == slider1 || currentTimeArr[3] == slider2)){//this is to prevent moving sliders in current schedule
  //do nothing
  if(firstTimeMove || k ==500){
    Serial.println(sliderMoved);
    Serial.println(currentTimeArr[3]);
    Serial.println(slider1);
    Serial.println(slider2);
    firstTimeMove = false;
    //k=0;
  }
  
}else{
  //Serial.print(schedulingOn); Serial.print(currentTimeArr[3]); Serial.print(sliderMoved);
  if(k == 500){
      Serial.print("Hour ");
      Serial.println(currentTimeArr[3]);
      Serial.print("shedulingOn ");
      Serial.println(schedulingOn);
       Serial.print("slider1 ");
      Serial.println(slider1);
      //k = 0;
  }
  if(slider1 == currentTimeArr[3] && schedulingOn== 0){
    if(firstTimeSlider1){
      Serial.println("In start");
      Serial.println(slider1);
      Serial.println(slider1);
      firstTimeSlider1 = false;
    }
    schedulingOn = 1;
    Serial.println("SCHEDULER STARTED");
    String strSchedOn = String(schedulingOn);
    writeFile(SPIFFS,"schedOn",strSchedOn.c_str());
    lastWrittenSchedOn = schedulingOn;
    flipSwitch();   
  }
if(k == 500){
      Serial.print("slider2 ");
      Serial.println(slider2 );
      Serial.print("Hour is ");
      Serial.println(currentTimeArr[3]);
      k = 0;
}

  if(slider2 == currentTimeArr[3] && schedulingOn == 1){
        if(firstTimeSlider2){
      Serial.println(slider2 );
      Serial.println(currentTimeArr[3]);
      firstTimeSlider2 = false;
    }
    Serial.println("SCHEDULER STOPPED");
    flipSwitch();    
    schedulingOn = 0;
    String strSchedOn = String(schedulingOn);
    writeFile(SPIFFS,"schedOn",strSchedOn.c_str());
    lastWrittenSchedOn = schedulingOn;
    sliderMoved = false;//this is to prevent moving sliders in current schedule
  }
}

if( (currentTimeArr[3] != slider1) && ( currentTimeArr[3] != slider2) ){
  if(lastWrittenSchedOn != schedulingOn){
    String strSchedOn = String(schedulingOn);
    writeFile(SPIFFS,"schedOn",strSchedOn.c_str());
    lastWrittenSchedOn = schedulingOn;
  }
}

    
    if( (newState() != state) && ! buttonWasPressed){
      //manual switch was flipped
      Serial.println("MANUAL SWITCH WAS FLIPPED");
      state = newState(); 
/*      if(lightToRelay){
        lightToRelay = false;
      }else{
        lightToRelay = true;
      }*/
    }
    buttonWasPressed = false;
    setWeb();
    //Serial.print(currentTimeArr[3]);
    if(oldHour != currentTimeArr[0]){
      oldHour = currentTimeArr[0];
      configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
    }
    delay(10);
}    ////////////////////////////////////////////////////



void setTime(){
  time_t rawtime;
  struct tm * timeinfo;
  time (&rawtime);
  timeinfo = localtime (&rawtime);
  //Serial.println(asctime(timeinfo));
  int hr = timeinfo->tm_hour;
  currentTimeArr[3] = hr;
 //Serial.print("Hour is ");
 //Serial.println(hr);  
 //unsigned long epochTime = timeClient.getEpochTime();
    //currentTimeArr[3] = timeClient.getHours()+1;    
  //  struct tm *ptm = gmtime ((time_t *)&epochTime);
    currentTimeArr[0] = timeinfo->tm_year+1900;
    currentTimeArr[1] = timeinfo->tm_mon;
    currentTimeArr[2] = timeinfo->tm_mday;
 /*   Serial.print("Year is ");
    Serial.println(currentTimeArr[0]);
    Serial.print("Month is ");
    Serial.println(currentTimeArr[1]);
    Serial.print("Day is ");
    Serial.println(currentTimeArr[2]);
    Serial.print("Hour is ");
    Serial.println(currentTimeArr[3]);*/
}



/*bool isDaylightSavingsTime(){
  setTime();
  int yr = currentTimeArr[0];
  //Serial.print(yr);
  int dayOfMonth = currentTimeArr[2];
  //Serial.print(dayOfMonth);
  int hr = currentTimeArr[3];
  //Serial.print(hr);
  int mo = currentTimeArr[1];
  //Serial.print(mo);
  int DST = 0;

  // ********************* Calculate offset for Sunday *********************
  int y = yr;                          // DS3231 uses two digit year (required here)
  int x = (y + y / 4 + 2) % 7;    // remainder will identify which day of month
  // is Sunday by subtracting x from the one
  // or two week window.  First two weeks for March
  // and first week for November
  // *********** Test DST: BEGINS on 2nd Sunday of March @ 2:00 AM *********
  if (mo == 3 && dayOfMonth == (14 - x) && hr >= 2)
  {
    DST = 1;                           // Daylight Savings Time is TRUE (add one hour)
  }
  if ((mo == 3 && dayOfMonth > (14 - x)) || mo > 3)
  {
    DST = 1;
  }
  // ************* Test DST: ENDS on 1st Sunday of Nov @ 2:00 AM ************
  if (mo == 11 && dayOfMonth == (7 - x) && hr >= 2)
  {
    DST = 0;                            // daylight savings time is FALSE (Standard time)
  }
  if ((mo == 11 && dayOfMonth > (7 - x)) || mo > 11 || mo < 3)
  {
    DST = 0;
  }
  if (DST == 1)                       // Test DST and add one hour if = 1 (TRUE)
  {
    hr = hr + 1;
  }
  if (DST == 1) {
    return true;
  } else {
    return false;
  }
}*/



void flipSwitch(){
      digitalWrite(SET,HIGH);
    delay(10);
    digitalWrite(SET,LOW);
  /*bool done = false;
  Serial.print("LTR is ");
  Serial.println(lightToRelay);
  Serial.print("newState is ");
  int state = newState();
  Serial.println(state);
  if( lightToRelay && newState()  && !done){
    digitalWrite(RESET,HIGH);
    delay(100);
    digitalWrite(RESET,LOW); 
    done = true;  
    Serial.println("LIGHT IS OFF");
  }
  if(lightToRelay && !newState() && !done ){
    digitalWrite(SET,HIGH);
    delay(100);
    digitalWrite(SET,LOW);
    done = true;
    Serial.println("LIGHT IS ON");
  }
  if( !lightToRelay && !newState()  && !done){
    digitalWrite(RESET,HIGH);
    delay(100);
    digitalWrite(RESET,LOW);
    done = true;
    Serial.println("LIGHT IS ON");
  }
  if(!lightToRelay && newState()  && !done){
    digitalWrite(SET,HIGH);
    delay(100);
    digitalWrite(SET,LOW);
    done = true;
    Serial.println("LIGHT IS OFF");
  }*/
}

void setStartTime(int amPm,int hr){
  Serial.println("in setStartTime");
  Serial.print("hr is ");
  Serial.print(hr);
  if(amPm == 1){
    //it is pm
    if(hr == 12){
      slider1 = 0;
    }else if(hr == 1){
      slider1 = 13;      
    }else if(hr == 2){
      slider1 = 14;      
    }else if(hr == 3){
      slider1 = 15;      
    }else if(hr == 4){
      slider1 = 16;      
    }else if(hr == 5){
      slider1 = 17;      
    }else if(hr == 6){
      slider1 = 18;      
    }else if(hr == 7){
      slider1 = 19;      
    }else if(hr == 8){
      
      slider1 = 20;      
    }else if(hr == 9){
      slider1 = 21;      
    }else if(hr == 10){
      slider1 = 22;      
    }else if(hr == 11){
      slider1 = 23;      
    }
  }else{
    slider1 = hr;
  }
  //Serial.print(slider1);
}

void setStopTime(int amPm, int hr){
  if(amPm == 1){
    //it is pm
    if(hr == 12){
      slider2 = 0;
    }else if(hr == 1){
      slider2 = 13;      
    }else if(hr == 2){
      slider2 = 14;      
    }else if(hr == 3){
      slider2 = 15;      
    }else if(hr == 4){
      slider2 = 16;      
    }else if(hr == 5){
      slider2 = 17;      
    }else if(hr == 6){
      slider2 = 18;      
    }else if(hr == 7){
      slider2 = 19;      
    }else if(hr == 8){
      slider2 = 20;      
    }else if(hr == 9){
      slider2 = 21;      
    }else if(hr == 10){
      slider2 = 22;      
    }else if(hr == 11){
      slider2 = 23;      
    }
  }else{
    slider2 = hr;
  }
  //Serial.print(slider2);
}

////////////////////////////////////////////////////////////////////
//
//  Fuction: readFile
//
//  Input:  SPIFFS,
//          char[]  filename path i.e. "/String.txt"
//
//  Output:  String of what was strored
//
//  Discription:  Stores a string in the /path in SPIFFS
//
/////////////////////////////////////////////////////////////////////
String readFile(fs::FS &fs, const char * path) {
  //Serial.printf("Reading file: %s\r\n", path);
  File file = fs.open(path, "r");
  if (!file || file.isDirectory()) {
    //Serial.println("- empty file or failed to open file");
    return String();
  }
  //Serial.println("- read from file:");
  String fileContent;
  while (file.available()) {
    fileContent += String((char)file.read());
  }
  //Serial.println(fileContent);
  file.close();
  return fileContent;
}

////////////////////////////////////////////////////////////////////
//
//  Fuction: writeFile
//
//  Input:  SPIFFS,
//          char[] filename path i.e. "/String.txt"
//          String to store
//
//  Output:  String of what was strored
//
//  Discription:  Stores a string in the /path in SPIFFS
//
/////////////////////////////////////////////////////////////////////
void writeFile(fs::FS &fs, const char * path, const char * message) {
  //Serial.printf("Writing file: %s\r\n", path);
  //Serial.print("path is : ");
  //Serial.println(path);
  //fs.remove(path);
  File file = fs.open(path, "w");
  if (!file) {
    Serial.println("- failed to open file for writing");
    //WebSerial.println("?EW"); //TODO change to right code
    return;
  }
  
  if (file.print(message)) {
    //Serial.println("- file written");
    if ((strcmp(path, "/timezone.txt") == 0)) {
      //Serial.println("Timezone changed!!!!!!!!11");
    }

  } else {
    Serial.println("- write failed");
  }
}

void setWeb(){
  
  if(newState()){
    Blynk.virtualWrite(V0,1);
    state = true;
  }else{
    Blynk.virtualWrite(V0,0);
    state = false;
  }
  String t1 = readFile(SPIFFS, "tab1");
  Blynk.virtualWrite(V1,t1.toInt());
  String t2 = readFile(SPIFFS, "tab2");
  Blynk.virtualWrite(V2,t2.toInt());
  String start1 = readFile(SPIFFS, "startAMPM");
  Blynk.virtualWrite(V3,start1.toInt());
  String stop1  = readFile(SPIFFS,"stopAMPM");
  Blynk.virtualWrite(V4,stop1.toInt());
  String strDlst = readFile(SPIFFS,"dlst");
  Blynk.virtualWrite(V5,strDlst.toInt());
}




bool newState(){
    //char buf[10];
    bool retVal = false;
  // get amplitude (maximum - or peak value)

for(int i=0;i<10;i++){
float v = analogRead(A0);

   if(v >=1000){
    retVal = true;
    break;
   }else{
    retVal = false;
   }
   //delay(300);
}
//Serial.print("newState is ");
//Serial.println(retVal);
  return retVal;
}



    buttonPressed = 1;
    
    delay(200);
  }

  BLYNK_WRITE(V5)  // button attached to Virtual Pin 1 in SWITCH mode
  {
    //Serial.print("V0 is: ");
    dlst = 1;
    String strDlst = String(dlst);
    writeFile(SPIFFS,"dlst",strDlst.c_str());   
    delay(200);
  }

  BLYNK_WRITE(V4) {
    stopAMPM = param.asInt();
    String strStopAMPM = String(stopAMPM);
    writeFile(SPIFFS,"stopAMPM",strStopAMPM.c_str());
    Serial.print("stopAMPM is: ");
    Serial.println(stopAMPM);
  }  
  BLYNK_WRITE(V3) {
    startAMPM = param.asInt();
    String strStartAMPM = String(startAMPM);
    writeFile(SPIFFS,"startAMPM",strStartAMPM.c_str());

    Serial.print("startAMPM is: ");
    Serial.println(startAMPM);
    Serial.print("Hour is; ");
    Serial.println(currentTimeArr[3]);
  }  

  BLYNK_WRITE(V2) {
    tab2 = param.asInt();
    sliderMoved = true;
    Serial.print("tab2 is: ");
    Serial.println(tab2);
      setTime();
      setStopTime(stopAMPM, tab2);
    String strTab2 = String(tab2);
    writeFile(SPIFFS,"tab2",strTab2.c_str());
    String strSlider2 = String(slider2);
    writeFile(SPIFFS,"slider2",strSlider2.c_str());
    Serial.print("Slider2 is ");
      Serial.println(slider2);
  }

  BLYNK_WRITE(V1) {
    tab1 = param.asInt();
    sliderMoved = true;
    Serial.print("tab1 is: ");
    Serial.println(tab1);
      setTime();
        setStartTime(startAMPM,tab1);
     
      String strTab1 = String(tab1);
      writeFile(SPIFFS, "tab1", strTab1.c_str());
    
      String strSlider1 = String(slider1);
      writeFile(SPIFFS, "slider1", strSlider1.c_str());
        Serial.print("Slider1 is ");
      Serial.println(slider1);
  }

// This function is called every time the device is connected to the Blynk.Cloud
BLYNK_CONNECTED()
{
  // Change Web Link Button message to "Congratulations!"
  Blynk.setProperty(V3, "offImageUrl", "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations.png");
  Blynk.setProperty(V3, "onImageUrl",  "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations_pressed.png");
  Blynk.setProperty(V3, "url", "https://docs.blynk.io/en/getting-started/what-do-i-need-to-blynk/how-quickstart-device-was-made");
}

// This function sends Arduino's uptime every second to Virtual Pin 2.
void myTimerEvent()
{
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
 // Blynk.virtualWrite(V2, millis() / 1000);
}

void setup()
{
  // Debug console
  Serial.begin(115200);
  pinMode(led_gpio, OUTPUT);
  pinMode(SET,OUTPUT);
  digitalWrite(SET,LOW);
  pinMode(RESET,OUTPUT);
  digitalWrite(RESET,LOW);  
  delay(10);
  //configTime(MY_TZ, MY_NTP_SERVER); // --> Here is the IMPORTANT ONE LINER needed in your sketch!

/////////////////////////////8266 wifi //////////////////////
  // WiFiManager
  // Local intialization. Once its business is done, there is no need to keep it around
  WiFiManager wifiManager;
  // Uncomment and run it once, if you want to erase all the stored information
  //wifiManager.resetSettings();
  
  // set custom ip for portal
  //wifiManager.setAPConfig(IPAddress(10,0,1,1), IPAddress(10,0,1,1), IPAddress(255,255,255,0));

  // fetches ssid and pass from eeprom and tries to connect
  // if it does not connect it starts an access point with the specified name
  // here  "AutoConnectAP"
  // and goes into a blocking loop awaiting configuration
  wifiManager.autoConnect("Under_Cabinet_Lights");
  // or use this for auto generated name ESP + ChipID
  //wifiManager.autoConnect();
  
  // if you get here you have connected to the WiFi
  Serial.println("Connected.");
  
  server.begin();
///////////////////////////////////////////////////////////
//////////time ///////////
//setTimeDLST();

    //timeClient.begin();
    
    //timeClient.setTimeOffset(offset+dlstOffset);    
  setTime();
/////////////////////////
  Blynk.config(BLYNK_AUTH_TOKEN);
    while (Blynk.connect() == false) {
  }
    if (Blynk.connected()) {
    Serial.println("Wifi/Blynk started");
  } else {
    Serial.println("Check Router");
  }
  // You can also specify server:
  //Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, "blynk.cloud", 80);
  //Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, IPAddress(192,168,1,100), 8080);

  // Setup a function to be called every second
  timer.setInterval(1000L, myTimerEvent);
  
  // mount and check the filesystem
  bool ok = SPIFFS.begin();
  if (ok) {
    Serial.println("SPIFFS initialized successfully");
    }
  else{
    Serial.println("SPIFFS intialization error");
    }
    /////////////////
configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  //currentRelayPin = 0;
  //EEPROM.get(1, tab1);
  String Dlst = readFile(SPIFFS,"dlst");
  dlst = Dlst.toInt();
  Serial.print("dlst is ");
  Serial.println(dlst);
Blynk.virtualWrite(V5, dlst);
  
  String strTab1 = readFile(SPIFFS,"tab1");
  tab1 = strTab1.toInt();
  Serial.print("tab1 is ");
  Serial.println(tab1);
Blynk.virtualWrite(V1, tab1);  
   
     String strSlider1 = readFile(SPIFFS,"slider1");
  slider1 = strSlider1.toInt();
  Serial.print("slider1 from eeprom is ");
  Serial.println(slider1);
  
  String strTab2 = readFile(SPIFFS,"tab2");
  tab2 = strTab2.toInt();
  Blynk.virtualWrite(V2, tab2);
  
   String strSlider2 = readFile(SPIFFS,"slider2");
  slider2 = strSlider2.toInt();
   
  String strStartAMPM = readFile(SPIFFS,"startAMPM");
  startAMPM = strStartAMPM.toInt();
  Blynk.virtualWrite(V3, startAMPM);
  
  String strStopAMPM = readFile(SPIFFS,"stopAMPM");
  stopAMPM = strStopAMPM.toInt();
  Serial.print("in set up stopAMPM is ");
  Serial.println(stopAMPM);
  Blynk.virtualWrite(V4, stopAMPM);

    
  String scheduOn = readFile(SPIFFS,"schedOn");
  schedulingOn = scheduOn.toInt();
}

void loop()
{
  if (WiFi.status() != WL_CONNECTED)
  {
    Serial.println("LOST WiFi restarting");
    //atoAwcUtil->webSerialWriteLine("LOST WiFi restarting");
    ESP.restart();
  }
  Blynk.run();
  timer.run();
  // You can inject your own code or combine it with other sketches.
  // Check other examples on how to communicate with Blynk. Remember
  // to avoid delay() function!
  if(blinking){
    digitalWrite(led_gpio, 0);
    blinking = false;
  }else{
    digitalWrite(led_gpio, 1);
    blinking = true;
  }


  if(buttonPressed){ 
    buttonWasPressed = true;
    flipSwitch();//push latch relay
    buttonPressed = 0;
  }
    /////////////////// do schedule //////////////////////
  setTime();
  //setStartTime(startAMPM, tab1);
  //setStopTime(stopAMPM,tab2);
  /*Serial.print("HOUR_________________");
  Serial.print(currentTimeArr[3]);
  Serial.print("SLIDERS____________________");
  Serial.print(slider1);
   Serial.print("SLIDERS____________________");
 Serial.println(slider2);*/
if(sliderMoved && (currentTimeArr[3] == slider1 || currentTimeArr[3] == slider2)){//this is to prevent moving sliders in current schedule
  //do nothing
  
}else{
  //Serial.print(schedulingOn); Serial.print(currentTimeArr[3]); Serial.print(sliderMoved);
  if(slider1 == currentTimeArr[3] && schedulingOn== 0){
    schedulingOn = 1;
    Serial.println("SCHEDULER STARTED");
    String strSchedOn = String(schedulingOn);
    writeFile(SPIFFS,"schedOn",strSchedOn.c_str());
    flipSwitch();   
  }


  if(slider2 == currentTimeArr[3] && schedulingOn == 1){
    Serial.println("SCHEDULER STOPPED");
    flipSwitch();    
    schedulingOn = 0;
    String strSchedOn = String(schedulingOn);
    writeFile(SPIFFS,"schedOn",strSchedOn.c_str());
    sliderMoved = false;//this is to prevent moving sliders in current schedule
  }
}

if(currentTimeArr[3] != slider1 && currentTimeArr[3] != slider2){
  schedulingOn = 0;
  String strSchedOn = String(schedulingOn);
  writeFile(SPIFFS,"schedOn",strSchedOn.c_str());
}

    
    if( (newState() != state) && ! buttonWasPressed){
      //manual switch was flipped
      Serial.println("MANUAL SWITCH WAS FLIPPED");
      state = newState(); 
/*      if(lightToRelay){
        lightToRelay = false;
      }else{
        lightToRelay = true;
      }*/
    }
    buttonWasPressed = false;
    setWeb();
    //Serial.print(currentTimeArr[3]);
    if(oldHour != currentTimeArr[0]){
      oldHour = currentTimeArr[0];
      configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
    }
    delay(10);
}    ////////////////////////////////////////////////////



void setTime(){
  time_t rawtime;
  struct tm * timeinfo;
  time (&rawtime);
  timeinfo = localtime (&rawtime);
  //Serial.println(asctime(timeinfo));
  int hr = timeinfo->tm_hour;
  currentTimeArr[3] = hr;
 Serial.print("Hour is ");
 Serial.println(hr);  
 //unsigned long epochTime = timeClient.getEpochTime();
    //currentTimeArr[3] = timeClient.getHours()+1;    
  //  struct tm *ptm = gmtime ((time_t *)&epochTime);
    currentTimeArr[0] = timeinfo->tm_year+1900;
    currentTimeArr[1] = timeinfo->tm_mon;
    currentTimeArr[2] = timeinfo->tm_mday;
 /*   Serial.print("Year is ");
    Serial.println(currentTimeArr[0]);
    Serial.print("Month is ");
    Serial.println(currentTimeArr[1]);
    Serial.print("Day is ");
    Serial.println(currentTimeArr[2]);
    Serial.print("Hour is ");
    Serial.println(currentTimeArr[3]);*/
}



/*bool isDaylightSavingsTime(){
  setTime();
  int yr = currentTimeArr[0];
  //Serial.print(yr);
  int dayOfMonth = currentTimeArr[2];
  //Serial.print(dayOfMonth);
  int hr = currentTimeArr[3];
  //Serial.print(hr);
  int mo = currentTimeArr[1];
  //Serial.print(mo);
  int DST = 0;

  // ********************* Calculate offset for Sunday *********************
  int y = yr;                          // DS3231 uses two digit year (required here)
  int x = (y + y / 4 + 2) % 7;    // remainder will identify which day of month
  // is Sunday by subtracting x from the one
  // or two week window.  First two weeks for March
  // and first week for November
  // *********** Test DST: BEGINS on 2nd Sunday of March @ 2:00 AM *********
  if (mo == 3 && dayOfMonth == (14 - x) && hr >= 2)
  {
    DST = 1;                           // Daylight Savings Time is TRUE (add one hour)
  }
  if ((mo == 3 && dayOfMonth > (14 - x)) || mo > 3)
  {
    DST = 1;
  }
  // ************* Test DST: ENDS on 1st Sunday of Nov @ 2:00 AM ************
  if (mo == 11 && dayOfMonth == (7 - x) && hr >= 2)
  {
    DST = 0;                            // daylight savings time is FALSE (Standard time)
  }
  if ((mo == 11 && dayOfMonth > (7 - x)) || mo > 11 || mo < 3)
  {
    DST = 0;
  }
  if (DST == 1)                       // Test DST and add one hour if = 1 (TRUE)
  {
    hr = hr + 1;
  }
  if (DST == 1) {
    return true;
  } else {
    return false;
  }
}*/



void flipSwitch(){
      digitalWrite(SET,HIGH);
    delay(10);
    digitalWrite(SET,LOW);
  /*bool done = false;
  Serial.print("LTR is ");
  Serial.println(lightToRelay);
  Serial.print("newState is ");
  int state = newState();
  Serial.println(state);
  if( lightToRelay && newState()  && !done){
    digitalWrite(RESET,HIGH);
    delay(100);
    digitalWrite(RESET,LOW); 
    done = true;  
    Serial.println("LIGHT IS OFF");
  }
  if(lightToRelay && !newState() && !done ){
    digitalWrite(SET,HIGH);
    delay(100);
    digitalWrite(SET,LOW);
    done = true;
    Serial.println("LIGHT IS ON");
  }
  if( !lightToRelay && !newState()  && !done){
    digitalWrite(RESET,HIGH);
    delay(100);
    digitalWrite(RESET,LOW);
    done = true;
    Serial.println("LIGHT IS ON");
  }
  if(!lightToRelay && newState()  && !done){
    digitalWrite(SET,HIGH);
    delay(100);
    digitalWrite(SET,LOW);
    done = true;
    Serial.println("LIGHT IS OFF");
  }*/
}

void setStartTime(int amPm,int hr){
  Serial.println("in setStartTime");
  Serial.print("hr is ");
  Serial.print(hr);
  if(amPm == 1){
    //it is pm
    if(hr == 12){
      slider1 = 0;
    }else if(hr == 1){
      slider1 = 13;      
    }else if(hr == 2){
      slider1 = 14;      
    }else if(hr == 3){
      slider1 = 15;      
    }else if(hr == 4){
      slider1 = 16;      
    }else if(hr == 5){
      slider1 = 17;      
    }else if(hr == 6){
      slider1 = 18;      
    }else if(hr == 7){
      slider1 = 19;      
    }else if(hr == 8){
      Serial.print("&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&");
      slider1 = 20;      
    }else if(hr == 9){
      slider1 = 21;      
    }else if(hr == 10){
      slider1 = 22;      
    }else if(hr == 11){
      slider1 = 23;      
    }
  }else{
    slider1 = hr;
  }
  //Serial.print(slider1);
}

void setStopTime(int amPm, int hr){
  if(amPm == 1){
    //it is pm
    if(hr == 12){
      slider2 = 0;
    }else if(hr == 1){
      slider2 = 13;      
    }else if(hr == 2){
      slider2 = 14;      
    }else if(hr == 3){
      slider2 = 15;      
    }else if(hr == 4){
      slider2 = 16;      
    }else if(hr == 5){
      slider2 = 17;      
    }else if(hr == 6){
      slider2 = 18;      
    }else if(hr == 7){
      slider2 = 19;      
    }else if(hr == 8){
      slider2 = 20;      
    }else if(hr == 9){
      slider2 = 21;      
    }else if(hr == 10){
      slider2 = 22;      
    }else if(hr == 11){
      slider2 = 23;      
    }
  }else{
    slider2 = hr;
  }
  //Serial.print(slider2);
}

////////////////////////////////////////////////////////////////////
//
//  Fuction: readFile
//
//  Input:  SPIFFS,
//          char[]  filename path i.e. "/String.txt"
//
//  Output:  String of what was strored
//
//  Discription:  Stores a string in the /path in SPIFFS
//
/////////////////////////////////////////////////////////////////////
String readFile(fs::FS &fs, const char * path) {
  //Serial.printf("Reading file: %s\r\n", path);
  File file = fs.open(path, "r");
  if (!file || file.isDirectory()) {
    //Serial.println("- empty file or failed to open file");
    return String();
  }
  //Serial.println("- read from file:");
  String fileContent;
  while (file.available()) {
    fileContent += String((char)file.read());
  }
  //Serial.println(fileContent);
  file.close();
  return fileContent;
}

////////////////////////////////////////////////////////////////////
//
//  Fuction: writeFile
//
//  Input:  SPIFFS,
//          char[] filename path i.e. "/String.txt"
//          String to store
//
//  Output:  String of what was strored
//
//  Discription:  Stores a string in the /path in SPIFFS
//
/////////////////////////////////////////////////////////////////////
void writeFile(fs::FS &fs, const char * path, const char * message) {
  //Serial.printf("Writing file: %s\r\n", path);
  //Serial.print("path is : ");
  //Serial.println(path);
  //fs.remove(path);
  File file = fs.open(path, "w");
  if (!file) {
    Serial.println("- failed to open file for writing");
    //WebSerial.println("?EW"); //TODO change to right code
    return;
  }
  
  if (file.print(message)) {
    //Serial.println("- file written");
    if ((strcmp(path, "/timezone.txt") == 0)) {
      //Serial.println("Timezone changed!!!!!!!!11");
    }

  } else {
    Serial.println("- write failed");
  }
}

void setWeb(){
  
  if(newState()){
    Blynk.virtualWrite(V0,1);
    state = true;
  }else{
    Blynk.virtualWrite(V0,0);
    state = false;
  }
  String t1 = readFile(SPIFFS, "tab1");
  Blynk.virtualWrite(V1,t1.toInt());
  String t2 = readFile(SPIFFS, "tab2");
  Blynk.virtualWrite(V2,t2.toInt());
  String start1 = readFile(SPIFFS, "startAMPM");
  Blynk.virtualWrite(V3,start1.toInt());
  String stop1  = readFile(SPIFFS,"stopAMPM");
  Blynk.virtualWrite(V4,stop1.toInt());
  String strDlst = readFile(SPIFFS,"dlst");
  Blynk.virtualWrite(V5,strDlst.toInt());
}




bool newState(){
    //char buf[10];
    bool retVal = false;
  // get amplitude (maximum - or peak value)

for(int i=0;i<10;i++){
float v = analogRead(A0);

   if(v >=1000){
    retVal = true;
    break;
   }else{
    retVal = false;
   }
   //delay(300);
}
//Serial.print("newState is ");
//Serial.println(retVal);
  return retVal;
}


