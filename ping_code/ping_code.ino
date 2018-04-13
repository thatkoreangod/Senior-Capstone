#include <Servo.h>

#define wheel_1_PIN     1
#define wheel_2_PIN     2
#define ping_servo_PIN  3
#define PING_IN         7
#define PING_OUT        8

using std::pair;
  
Servo wheel_1, wheel_2, ping_servo;

typedef long length;
typedef short pos;

pos left_pos = 0;
pos right_pos = 0;
pos ping_servo_pos = 0;
int count = 0;

const long measurements[400];

void setup() {
  pinMode(PING_OUT, OUTPUT);
  pinMode(PING_IN, INPUT);
  
  wheel_1.attach(wheel_1_PIN);
  wheel_2.attach(wheel_2_PIN);
  ping_servo.attach(ping_servo_PIN);
}

void loop() {
  wheel_1.write(left_pos = (left_pos + 1) % 180);
  wheel_2.write(right_pos = (right_pos + 1) % 180);
  
  ping_servo_pos = (ping_servo_pos + (400 / 360)) % 360;
  ping_servo.write(ping_servo_pos);
  
  digitalWrite(PING_OUT, LOW);
  delayMicroseconds(2);
  digitalWrite(PING_OUT, HIGH);
  delayMicroseconds(5);
  digitalWrite(PING_OUT, LOW);

  measurements[count] = microsecondsToCentimeters(pulseIn(PING_IN, HIGH));
  count = (count + 1) % 400;
  
  delay(100);
}

long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}
