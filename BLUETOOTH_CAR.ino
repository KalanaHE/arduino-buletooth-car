/*
   Arduino Bluetooth Car
   ----------------
   
   Date: 2017.02.20 @ 2:14 AM

   The circuit
    Front Motor to  L293D Shild M1 Connector
    Back Motor  to  L293D Shild M2 Connector
    Steering Motor to L293D Shild M3 Connector

  Connected to Bluetooth Module

  Arduino     HC-05/06
    5V     -     5V
   GND     -    GND
    RX     -     TX
    TX     -     RX
*/

#include<AFMotor.h>

AF_DCMotor motor1(1); // M1
AF_DCMotor motor2(2); // M2
AF_DCMotor motor3(3); // M3

char val;

void setup() {
  Serial.begin(9600);
  Serial.print("Calculus's Arduino Bluetooth Car\n\n");
  
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor3.setSpeed(190);

  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
}

void loop() {
  if (Serial.available() > 0) {
    val = Serial.read();
    //Serial.println(val);

    //////// Front & Back Motor Part ////////

    if (val == '1') {
      motor1.run(FORWARD);
      motor2.run(FORWARD);
      Serial.println("Forward");
    }
    else if (val == '2') {
      motor1.run(BACKWARD);
      motor2.run(BACKWARD);
      Serial.println("Backward");
    }
    else if (val == '3') {
      motor1.run(RELEASE);
      motor2.run(RELEASE);
      motor3.run(RELEASE);
      Serial.println("stop\n\n");
    }

    //////// Steering Motor Part ////////

    else if (val == '4') {
      motor3.run(FORWARD);
      Serial.println("Right");
    }
    else if (val == '5') {
      motor3.run(BACKWARD);
      Serial.println("Left");
    }
    
  }
}
