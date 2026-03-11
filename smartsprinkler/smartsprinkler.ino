#define BLYNK_TEMPLATE_ID "TMPL6rrNCI5Me"
#define BLYNK_TEMPLATE_NAME "car fun"
#define BLYNK_AUTH_TOKEN "bdO8UR4U-O1NpGhZ-0gRt8AQTQQIyBDs"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

// WiFi
char ssid[] = "victor";
char pass[] = "12345678";

// Motor pins
const int in1 = 26;
const int in2 = 25;
const int in3 = 33;
const int in4 = 32;

// Relay pin for water pump
const int pumpRelay = 27;

void setup()
{
  Serial.begin(115200);

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  pinMode(pumpRelay, OUTPUT);

  digitalWrite(pumpRelay, LOW);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop()
{
  Blynk.run();
}

// FORWARD
BLYNK_WRITE(V0)
{
  if (param.asInt() > 0) {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
  } else {
    stopCar();
  }
}

// BACKWARD
BLYNK_WRITE(V1)
{
  if (param.asInt() > 0) {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  } else {
    stopCar();
  }
}

// LEFT
BLYNK_WRITE(V2)
{
  if (param.asInt() > 0) {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
  } else {
    stopCar();
  }
}

// RIGHT
BLYNK_WRITE(V3)
{
  if (param.asInt() > 0) {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  } else {
    stopCar();
  }
}

// WATER PUMP SWITCH
BLYNK_WRITE(V4)
{
  int pumpState = param.asInt();

  if (pumpState > 0) {
    digitalWrite(pumpRelay, HIGH);
  } else {
    digitalWrite(pumpRelay, LOW);
  }
}

void stopCar()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}