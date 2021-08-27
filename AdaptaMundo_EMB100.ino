/*********
  AdaptaMundo
  EMB100
  
  ESP8266 AP mode
  Webserial
  EEPROM
  OTA
*********/

//---------------------------------------------------------------------------
// Bibliotecas
//---------------------------------------------------------------------------

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>

#include <WebSerial.h>

#include <EEPROM.h>

//---------------------------------------------------------------------------
// Constantes
//---------------------------------------------------------------------------

const char* ssid = "ESP8266_EMB";     // SSID
const char* password = "12345678";    // Password

IPAddress local_ip(192,168,1,1);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);

uint8_t input_clutch_advance = D3;    // GPIO0
uint8_t input_gear_rear = D4;         // GPIO2
//uint8_t input_gear_neutral =
//uint8_t input_clutch_disengaged =
uint8_t output_enable = D6;           // GPIO12
uint8_t output_direction = D7;        // GPIO13
uint8_t output_velocidade = D5;       // GPIO14
uint8_t output_status = D0;           // GPIO16    
uint8_t output_advance = D1;          // GPIO5
uint8_t output_return_fast = D2;      // GPIO4              
uint8_t output_return_slow = D8;      // GPIO15

AsyncWebServer server(80);

int EEPROM_address_freq = 0;
int EEPROM_address_engage = 1;
int EEPROM_address_disengage = 2;

byte value_freq;
byte value_engage;
byte value_disengage;

String d;


void recvMsg(uint8_t *data, size_t len){
  //WebSerial.println("Received Data...");
  d = "";
  //for(int i=0; i < len; i++){
  // d += char(data[i]);
  //}
  WebSerial.print(d);
}

//---------------------------------------------------------------------------
// Setup
//---------------------------------------------------------------------------


void setup() {
  Serial.begin(115200);                                   // Inicializa Serial
  EEPROM.begin(512);                                      // inicializa EEPROM

    pinMode(input_clutch_advance, INPUT);                   
    pinMode(input_gear_rear, INPUT);
    
    pinMode(output_enable, OUTPUT);
    pinMode(output_direction, OUTPUT);
    pinMode(output_velocidade, OUTPUT);
    pinMode(output_status, OUTPUT);
    pinMode(output_advance, OUTPUT);
    pinMode(output_return_fast, OUTPUT);
    pinMode(output_return_slow, OUTPUT);

  WiFi.softAP(ssid, password);
  WiFi.softAPConfig(local_ip, gateway, subnet);
  delay(100);
  
  value_freq = EEPROM.read(EEPROM_address_freq);
  value_engage = EEPROM.read(EEPROM_address_engage);
  value_disengage = EEPROM.read(EEPROM_address_disengage);
  
  
  WebSerial.begin(&server);                               // WebSerial is accessible at "<IP Address>/webserial" in browser
  WebSerial.msgCallback(recvMsg);
    
  server.begin();
  
}

//---------------------------------------------------------------------------
// Main Loop
//---------------------------------------------------------------------------

void loop() {
WebSerial.print("= 123");
}
