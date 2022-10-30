#include <Arduino.h>
#include <ESP8266WiFi.h> // Include the Wi-Fi library
#include <ESP8266Ping.h> // Include a library for ping

const char *ssid = "xxx";     // The SSID (name) of the Wi-Fi network you want to connect to
const char *password = "xxx"; // The password of the Wi-Fi network

WiFiClient clientWIFI;

const IPAddress remote_ip(1, 1, 1, 1);

const unsigned int interval = 5000;

void setup()
{
  Serial.begin(9600); // Start the Serial communication to send messages to the computer
  delay(10);
  Serial.println('\n');

  WiFi.begin(ssid, password); // Connect to the network

  Serial.print("Connecting to ");
  Serial.print(ssid);
  Serial.println(" ...");

  while (WiFi.status() != WL_CONNECTED)
  { // Wait for the Wi-Fi to connect
    delay(1000);
    Serial.print('.');
  }

  Serial.println('\n');
  Serial.println("Connection established!");
  Serial.print("IP address:\t");
  Serial.println(WiFi.localIP()); // Send the IP address of the ESP8266 to the computer
}

void loop()
{
  if (Ping.ping(remote_ip))
  {
    float avg_time_ms = Ping.averageTime();
    Serial.printf("Ping to %s was successful in %0.0fms!\n", remote_ip.toString().c_str(), avg_time_ms);
  }
  else
  {
    Serial.println("Error :(");
  }
  delay(interval);
}