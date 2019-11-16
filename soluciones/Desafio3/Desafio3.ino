/*
 Basic ESP8266 MQTT example

*/

#include <ESP8266WiFi.h>
#include <PubSubClient.h>

// Update these with values suitable for your network.

const char* ssid = "MotoSDE2";
const char* password = "0498665304";
const char* mqtt_server = "broker.mqtt-dashboard.com";

WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;
char msg[50];
int value = 0;

// Create a random client ID
String clientId = "";

void setup_wifi() {

  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  randomSeed(micros());

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();

  // Switch on the LED if an 1 was received as first character
  if (String(topic) == "/north-hackerspace/onOff") {
    if ((char)payload[0] == '1') {
      digitalWrite(D8, HIGH);   
    } else {
      digitalWrite(D8, LOW);  // Turn the LED off by making the voltage HIGH
    }
  }

}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect(clientId.c_str())) {
      Serial.println("connected");
      // Once connected, publish an announcement...
      String message = clientId + " connecting to MQTT...";
      client.publish("/north-hackerspace/messages", message.c_str());
      // ... and resubscribe
      client.subscribe("/north-hackerspace/onOff");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void setup() {
  pinMode(D8, OUTPUT);     // Initialize the D8 pin as an output
  pinMode(D8, HIGH);
  Serial.begin(115200);
  setup_wifi();
  clientId = "ESP8266Client-" + String(random(0xffff), HEX);
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void loop() {

  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  long now = millis();
  if (now - lastMsg > 5000) {
    lastMsg = now;
    ++value;
    snprintf (msg, 50, "%s ping #%ld", clientId.c_str(), value);
    Serial.print("Publish message: ");
    Serial.println(msg);
    client.publish("/north-hackerspace/messages", msg);
  }
}
