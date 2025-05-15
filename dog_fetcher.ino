#include <Arduino.h>

//Define global variables

//Assign pins
int motor1 = 15;
int motor2 = 16;
int infrared_sensor = 4;
int led = 2;
int speed = 255;

//define boolean to determine whether object is sensed
bool SENSE_OBJECT = false;

void ultrasonic_sense(){
  //this function senses the distance to the ball - if the ball is in the tube it will sense things
  if(digitalRead(infrared_sensor) == true){
    SENSE_OBJECT = true;
  }else{
    SENSE_OBJECT = false;
  }
}

void reaction_to_object(){
  if(SENSE_OBJECT == true){
    digitalWrite(led, 1);
  }else{
    digitalWrite(led, 0);
  }
}

void setup() {
  //determine whether pins are outputs or inputs
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  pinMode(infrared_sensor, INPUT);
  pinMode(led, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  while(1){
    analogWrite(motor1, speed);
    analogWrite(motor2, speed);
    ultrasonic_sense();
    reaction_to_object();
  }

}
