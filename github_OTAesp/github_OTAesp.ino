
#include <WiFi.h>
#include "OtaGitHub.h"


const char * ssid = "TheGreenCityStation";
const char * password = "Southstar2023!";


// IPAddress local_IP(192, 168, 10, 122);//IP esp 122
// IPAddress gateway(192, 168, 10, 1);
// IPAddress subnet(255, 255, 255, 0);

IPAddress ip(192, 168, 10, 110);      // Static IP address
IPAddress gateway(192, 168, 10, 1);   // Gateway IP address
IPAddress subnet(255, 255, 255, 0);   // Subnet mask
IPAddress dns1(192, 168, 10, 1);      // DNS server 1
IPAddress dns2(0, 0, 0, 0);           // DNS server 2 (0.0.0.0 if not used)


void setup() {

  Serial.begin(115200);
  Serial.print("Active firmware version:");
  Serial.println(FirmwareVer);

  connect_wifi();
}
void loop() {

  repeatedCall();
}

void connect_wifi() {
  Serial.println("Waiting for WiFi");
  WiFi.begin(ssid, password);
  //WiFi.config(local_IP, gateway, subnet,dns1, dns2); 
  WiFi.config(ip, gateway, subnet, dns1, dns2);
  //WiFi.config(local_IP);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");

  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  
  Serial.print("Gateway: ");
  Serial.println(WiFi.gatewayIP());
  
  Serial.print("Subnet: ");
  Serial.println(WiFi.subnetMask());

  Serial.print("DNS Server 1: ");
  Serial.println(WiFi.dnsIP(0));
  
  Serial.print("DNS Server 2: ");
  Serial.println(WiFi.dnsIP(1));
}


