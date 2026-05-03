#include <WiFi.h>
#include <PubSubClient.h>

// ===== WIFI =====
const char* ssid = "SEU_WIFI";
const char* password = "SENHA_WIFI";

// ===== MQTT =====
const char* mqtt_server = "13.233.174.162";

WiFiClient espClient;
PubSubClient client(espClient);

// ===== PINOS =====
#define MQ135_PIN 34
#define LED_PIN 2
#define BUTTON_PIN 4

// ===== VARIÁVEIS =====
int lastButtonState = HIGH;

// ===== WIFI =====
void setup_wifi() {
  delay(10);
  Serial.println("Conectando ao WiFi...");
  
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi conectado!");
}

// ===== MQTT CALLBACK =====
void callback(char* topic, byte* payload, unsigned int length) {
  String message = "";

  for (int i = 0; i < length; i++) {
    message += (char)payload[i];
  }

  Serial.print("Mensagem recebida: ");
  Serial.println(message);

  if (String(topic) == "controle/led") {
    if (message == "ON") {
      digitalWrite(LED_PIN, HIGH);
    } else if (message == "OFF") {
      digitalWrite(LED_PIN, LOW);
    }
  }
}

// ===== MQTT RECONNECT =====
void reconnect() {
  while (!client.connected()) {
    Serial.print("Conectando ao MQTT...");

    if (client.connect("ESP32Client")) {
      Serial.println("Conectado!");
      client.subscribe("controle/led");
    } else {
      Serial.print("Erro, rc=");
      Serial.print(client.state());
      delay(2000);
    }
  }
}

// ===== SETUP =====
void setup() {
  Serial.begin(115200);

  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  setup_wifi();

  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

// ===== LOOP =====
void loop() {

  if (!client.connected()) {
    reconnect();
  }

  client.loop();

  // ===== SENSOR MQ135 =====
  int sensorValue = analogRead(MQ135_PIN);

  char msg[10];
  sprintf(msg, "%d", sensorValue);

  client.publish("sensor/gas", msg);
  Serial.print("MQ135: ");
  Serial.println(sensorValue);

  // ===== BOTÃO =====
  int buttonState = digitalRead(BUTTON_PIN);

  if (buttonState == LOW && lastButtonState == HIGH) {
    client.publish("sensor/botao", "pressionado");
    Serial.println("Botão pressionado!");
    delay(300);
  }

  lastButtonState = buttonState;

  delay(2000);
}
