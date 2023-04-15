#include <Servo.h>

Servo s; // create servo object to control a servo
int flag=0;

// LEFT MOTOR connections
int enA = 9;
int in1 = 8;
int in2 = 7;

// RIGHT MOTOR connections
int enB = 3;
int in3 = 5;
int in4 = 4;

void setup() {
  Serial.begin(9600);
//  Servo s;
//  s.attach(9); // attaches the servo on pin 9 to the servo object
  pinMode(enA, OUTPUT);
    pinMode(enB, OUTPUT);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
  
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
}

void loop() {
  if(Serial.available()>0){
    String message = Serial.readString();
//    Serial.print(message);

//    s.write(0);
//    s.write(180);
    //backwards
    if(message=="backwards"){
      analogWrite(enA, 255);
      analogWrite(enB, 255);
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      delay(500); // Wait for 5 seconds
      
      // Stop both motors
      analogWrite(enA, 0);
      analogWrite(enB, 0);
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);
      delay(500); 
          
    }
    //forwards
    if(message=="forwards"){
      analogWrite(enA, 255);
      analogWrite(enB, 255);
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
      delay(500);
      analogWrite(enA, 0);
      analogWrite(enB, 0);
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);
      delay(500); // Wait for 2 seconds
          
    }
    //left
    if(message=="left"){
      analogWrite(enA, 255);
      analogWrite(enB, 255);
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
      delay(1000); // Wait for 3 seconds
      
      // Stop both motors
      analogWrite(enA, 0);
      analogWrite(enB, 0);
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);
      delay(500); // Wait for 2 seconds
          
    }
    //right
    if(message=="right"){
      analogWrite(enA, 255);
      analogWrite(enB, 255);
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);
      delay(1000); // Wait for 4 seconds
      
      // Stop both motors
      analogWrite(enA, 0);
      analogWrite(enB, 0);
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);
      delay(500);  // Wait for 2 seconds
          
    }
    //stop
    if(message=="stop"){
      analogWrite(enA, 0);
      analogWrite(enB, 0);
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);
      delay(500); // Wait for 2 seconds
          
    }

//    Serial.println(Serial.available());
//for(int i=0;i<180;i++)
//  {
//   s.write(i*20);
//   delay(100);
//  }
  
}
}
