#include <Servo.h>
Servo servo;
int number = 0;
int trigg = 2, echo = 4;
const float speed_sound = 0.034373;

void setup() {
  pinMode(trigg, OUTPUT);
  pinMode(echo, INPUT);
  servo.attach(3);
  Serial.begin(9600);
}

float distance() {
  unsigned long duration;
  float n_distance;
  digitalWrite(trigg, LOW);
  delayMicroseconds(20);
  digitalWrite(trigg, OUTPUT);
  delayMicroseconds(20);
  digitalWrite(trigg, LOW);
  duration = pulseIn(echo, HIGH);
  n_distance = (duration * speed_sound) / 2;
  return (n_distance);
}

void loop() {
  String nb;
  int angulo;
  float dist;
  for (angulo = 0; angulo <= 180; angulo++) {
    servo.write(angulo);
    dist = distance();
    Serial.print(angulo);
    Serial.print(";");
    Serial.println(dist);
    delay(75);
  }
  for (angulo = 180; angulo >= 0; angulo--) {
    servo.write(angulo);
    dist = distance();
    Serial.print(angulo);
    Serial.print(";");
    Serial.println(dist);
    delay(75);
  }
}
