/* Final Year Project 
 * Title: Establish the temperature control strategy with temperature sensor in supermarket
 * Name: Ng Sin Ue 
 * Student number: 20013999S
 * Arduino Code for connecting Arduino UNO 
 * with DHT-11 Temperature Sensor
 */

#include "DHT.h"
#include <SPI.h>
#include <Ethernet.h>
//Setting MAC Address
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED }; 

#define DHTPIN 2

#define DHTTYPE DHT11

DHT dht(DHTPIN,DHTTYPE);

float temperatureData;

char server[] = "192.168.1.102";
IPAddress ip(192.168.0.177); 
EthernetClient client; 

/* Setup for Ethernet and RFID */

void setup() {
  Serial.begin(9600);
  dht.begin();
  if (Ethernet.begin(mac) == 0) {
  Serial.println("Failed to configure Ethernet using DHCP");
  Ethernet.begin(mac, ip);
  }
  delay(1000);
}
//------------------------------------------------------------------------------


/* Infinite Loop */
void loop(){
  temperatureData = dht.readTemperature(); 
  Sending_To_phpmyadmindatabase(); 
  delay(30000); // interval
}

  //Connecting wtih MySQL
  void Sending_To_phpmyadmindatabase()  
 {
   if (client.connect(server, 80)) {
    Serial.println("connected");
    // Make a HTTP request:
    Serial.print("GET /testcode/dht.php?temperature=");
    client.print("GET /testcode/dht.php?temperature=");     
    client.print(temperatureData);
    Serial.println(temperatureData);
    client.print(" ");      
    client.print("HTTP/1.1");
    client.println();
    client.println("Host:192.168.1.102");
    client.println("Connection: close");
    client.println();
  } else {
    // if you didn't get a connection to the server:
    Serial.println("connection failed");
  }
 }
#include "DHT.h"
#include <SPI.h>
#include <Ethernet.h>
//Setting MAC Address
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED }; 

#define DHTPIN 2

#define DHTTYPE DHT11

DHT dht(DHTPIN,DHTTYPE);

float temperatureData;

char server[] = "192.168.1.102";
IPAddress ip(192.168.0.177); 
EthernetClient client; 

/* Setup for Ethernet and RFID */

void setup() {
  Serial.begin(9600);
  dht.begin();
  if (Ethernet.begin(mac) == 0) {
  Serial.println("Failed to configure Ethernet using DHCP");
  Ethernet.begin(mac, ip);
  }
  delay(1000);
}
//------------------------------------------------------------------------------


/* Infinite Loop */
void loop(){
  temperatureData = dht.readTemperature(); 
  Sending_To_phpmyadmindatabase(); 
  delay(30000); // interval
}

  //CONNECTING WITH MYSQL
  void Sending_To_phpmyadmindatabase()   
 {
   if (client.connect(server, 80)) {
    Serial.println("connected");
    // Make a HTTP request:
    Serial.print("GET /testcode/dht.php?temperature=");
    client.print("GET /testcode/dht.php?temperature=");    
    client.print(temperatureData);
    Serial.println(temperatureData);
    client.print(" ");      //SPACE BEFORE HTTP/1.1
    client.print("HTTP/1.1");
    client.println();
    client.println("Host:192.168.1.102");
    client.println("Connection: close");
    client.println();
  } else {
    // if you didn't get a connection to the server:
    Serial.println("connection failed");
  }
 }
