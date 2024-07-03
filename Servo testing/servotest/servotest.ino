#include <Servo.h>
#define right_servo_pin 10
#define left_servo_pin 9
Servo myservoright;
Servo myservoleft;


void setup() {
  
myservoleft.attach(left_servo_pin);
myservoright.attach(right_servo_pin);

  // put your setup code here, to run once:
  pinMode(right_servo_pin, OUTPUT);
  pinMode(left_servo_pin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  myservoleft.write(5);//Bucket down pos
  myservoright.write(170);
  delay(1000);
  myservoleft.write(47);//Bucket up pos
  myservoright.write(120);
  delay(1000);
  // delay(1000);
  // myservoleft.write(100);
  // myservoright.write(180-100);
  // delay(1000);

}


// void Setservo(int angle)
// {

//   myservoleft.write(angle);
//   myservoright.write(180-angle);
// }