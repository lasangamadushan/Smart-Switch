#include <ESP8266WiFi.h> 
#include <ESP8266WebServer.h> 

const char* ssid = "Dialog 4G";
const char* password = "*******";

ESP8266WebServer server(80);

void handleRoot() {
  server.send(200, "text/html", "<html><head></head><body> <h1>Web LED Switch</h1><a href=\"/1\"><button style=\"background:#f12f2f; font-size: 500%; border:4px double\">LED on</button></a><a href=\"/0\"><button style=\"background:#57eb06; font-size: 500%; border:4px double\">LED off</button></a></body></html>");
  delay(100);
}

void ledOn() {
    server.send(200, "text/html", "<html><head></head><body> <h1>Web LED Switch</h1><a href=\"/1\"><button style=\"background:#f12f2f; font-size: 500%; border:4px double\">LED on</button></a><a href=\"/0\"><button style=\"background:#57eb06; font-size: 500%; border:4px double\">LED off</button></a></body></html>");
  digitalWrite(2, HIGH);
}

void ledOff() {
    server.send(200, "text/html", "<html><head></head><body> <h1>Web LED Switch</h1><a href=\"/1\"><button style=\"background:#f12f2f; font-size: 500%; border:4px double\">LED on</button></a><a href=\"/0\"><button style=\"background:#57eb06; font-size: 500%; border:4px double\">LED off</button></a></body></html>");
  digitalWrite(2, LOW);
}

void setup() {
  pinMode(2, OUTPUT);
  Serial.begin(115200);
  Serial.print("Connecting to network");
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);   // Connect to WiFi network

  while (WiFi.status() != WL_CONNECTED) {    // Wait for connection
    delay(500);
    Serial.print(".");
  }

  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.on("/0", ledOff);
  server.on("/1", ledOn);

  server.begin();
  Serial.println("HTTP server started");
}

void loop()
{
  server.handleClient();
}

