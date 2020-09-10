
#include <ESP32Servo.h>

int incomingPulseWidth = 0;
int incomingPin = 0;
int state = 0;

Servo leftMotor;

void setup()
{
  Serial.begin(9600);
  
  delay(500);
  Serial.print("Please enter a pin number: ");
  state = 0;
}

void loop()
{
  
  if(Serial.available()>0)
  {
    int output = Serial.parseInt();
    Serial.read();
    Serial.println(output);

    if (state == 0){
      incomingPin = output;
      Serial.print("Please enter a PulseWidth (us): ");
      state = 1;
    }else if (state == 1){
      incomingPulseWidth = output;
      Serial.print("Setting pin ");
      Serial.print(incomingPin);
      Serial.print(" to a width of ");
      Serial.print(incomingPulseWidth);
      Serial.println(" us.");


      leftMotor.attach(incomingPin, 1000, 2000);
      leftMotor.writeMicroseconds(incomingPulseWidth);
      
      Serial.print("Please enter a pin number: ");
      state = 0;
    }

  }
}
