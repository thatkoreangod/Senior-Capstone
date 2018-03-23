#include <IRremote.h>
const int RECV_PIN = 6;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  irrecv.blink13(true);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);

}
void setup() {
  if (irrecv.decode(&results)) {
    String s = "" + results.value;
    if(s == "AD2"){
      digitalWrite(13, 0);
    }
    if(s == "AD9"){
      digitalWrite(13, 1);
    }
    if(s == "AE2"){
      digitalWrite(12, 0);
    }
    if(s == "AE9"){
      digitalWrite(12, 1);
    }
    if(s == "AF2"){
      digitalWrite(11, 0);
    }
    if(s == "AF9"){
      digitalWrite(11, 1);
    }
    delay(100);
    irrecv.resume(); 
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
