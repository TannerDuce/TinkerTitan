#include <Ultrasonic.h>

#include <Servo.h>
#define right_servo_pin 10
#define left_servo_pin 9
Servo myservoright;
Servo myservoleft;


//each motor is controled by two pins,(plus an enable pin) and depening on what combination of values
//you set the pins to you can get it to move in the desired direction
#define left_motor_sleep 16
#define left_motor_a 5
#define left_motor_b 6
#define left_motor_weight 1 //the final value sent to the motor will be multipled by this. set it between -1 and 1
//weight is usefull for tweeking un-ballenced motors, incase one is naturaly faster than the other. this feature is also handy
//if you discover your motors are backwards. simply make the value negitive
#define right_motor_sleep 2
#define right_motor_a 3
#define right_motor_b 11
#define right_motor_weight 1 //the final value sent to the motor will be multipled by this. set it between 0 and 1
//===========code varibles===========
Ultrasonic ultrasonic(A1, A0);
int distance;
int SUMOSTATE = 0;

//===========================================USER VARIBLES==================================================
#define trigger_distance 50 // distance(cm) before robot will trigger. set this to the ring diametre for best results
#define grace_period 5000 //the number in (ms) before the robot will begin searching for other bots.

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Initializing");
  pinMode(left_motor_sleep, OUTPUT);
  pinMode(left_motor_a, OUTPUT);
  pinMode(left_motor_b, OUTPUT);
  pinMode(right_motor_sleep, OUTPUT);
  pinMode(right_motor_a, OUTPUT);
  pinMode(right_motor_b, OUTPUT);

  //turn on the motor drivers
  digitalWrite(left_motor_sleep, HIGH);
  digitalWrite(right_motor_sleep, HIGH);
  myservoleft.attach(left_servo_pin);
  myservoright.attach(right_servo_pin);
  pinMode(right_servo_pin, OUTPUT);
  pinMode(left_servo_pin, OUTPUT);
  //after initializing everything, wait for the grace period to end. this gives time to plug in the robot,
  //and get it properly positioned in the circle before the match begins
  delay(grace_period);
  myservoleft.write(90);//Bucket down pos
  myservoright.write(90);




}

void loop() {
  // put your main code here, to run repeatedly:
  //We are going to run a state machine here. We start the program in state 0.
  //STATE ZERO CONDIDIONS:
  //    We are in state ZERO, meaning we have succsessfuly pushed someone out of the ring, or we have just started the program
  //    here, we check for if,
  //    A, The color sensor does not see the outer ring line AND
  //    B, The ultrasonic sensor does not see a value less than (trigger_distance). <-- make this the diameter of the ring
  //    if A becomes false, enter state ONE
  //    if B becomes false, enter state TWO
  //    if both remain true, we continue slowly rotating right in search of an opponent
  //STATE ONE CONDITIONS
  //    We have entered state one, meaning we are on the line. We proceed by backing up the robot and turning around.
  //    after this, we return to state ZERO
  //STATE TWO CONDITIONS
  //    we have entered state TWO, meaning an opponent has been located, and now we must attempt to push them out of the circle.
  //    We start by calling a Drive(9,9), and then check the line sensor
  //    The only way to leave this state is if a line is seen. theirfore in this state,
  //    we check the line sensor every loop. if the line sensor is triggered, we enter STATE ONE
  distance = ultrasonic.read();
  Serial.println(distance);
  Serial.print("state of machine is...");
  Serial.println(SUMOSTATE);
  delay(30); //this shouldnt be here, but the ultrasonic cant keep up, so it is
  if(SUMOSTATE == 0)
  {
    if((analogRead(6))>500)   //use < if the ring is black with a white line and > for vice versa
    {
      //if this code runs, that means we have seen a line!
      SUMOSTATE = 1;
    }

    else if(distance < trigger_distance)
    {
      if(distance != 0)
      {
        //if this code runs, that means we have seen a robot!
        Serial.println("ultrisonic trigger");
        SUMOSTATE = 2;
        delay(100);
      }
    
      //if this code runs, that means we have seen a robot!
      // Serial.println("ultrisonic trigger");
      // SUMOSTATE = 2;
    }

    else
    {
      //neither exit condition was met, so we slowly turn to the left and keep searching
      drive(6,-6);
    }

  }

  else if(SUMOSTATE == 1)
  {
    //we have seen a line. back up and turn around:
    drive(5,5);
    delay(1000);
    drive(6,-6);
    delay(500);
    coast();
    SUMOSTATE = 0;

  }

  else if(SUMOSTATE == 2)
  {
    //we see a robot, time to push it out of the circle!
    drive(-9,-9);
    if(distance>333 || distance<5)
    {
      
        Serial.println("welp, im here");
        myservoleft.write(0);//Bucket up pos
        myservoright.write(180);
        if((analogRead(6))>500)
        {
          // after setting the motors to almost full speed, we continuiosly check if we have seen the line. if so,
          applyBrake();
          SUMOSTATE = 1;
        }
        delay(200);
        myservoleft.write(90);//Bucket down pos
        myservoright.write(90);
        delay(40);
      
    }
    if((analogRead(6))>500)
    {
      // after setting the motors to almost full speed, we continuiosly check if we have seen the line. if so,
      applyBrake();
      SUMOSTATE = 1;
    }

  }

}

//===========================================================FUNCTIONS============================================================
void drive(int left_track_speed,int right_track_speed)
{
  //drive Forwards by setting a=1 and b=0. to get different speeds, we PWM one of the pins.
  //The parameters passed in have a value from -10 to 10, of which negitive speeds will drive backwards.
  //Motors will contuniously spin untill either the applyBrake() or coast() functions are called.

  //code for left motor:
  if(left_track_speed>0)
  {
  digitalWrite(left_motor_a, LOW);
  analogWrite(left_motor_b, round(left_track_speed*25*left_motor_weight));
  }
  else
  {
    analogWrite(left_motor_a, round(left_track_speed*(-25)*left_motor_weight));
    digitalWrite(left_motor_b, LOW);
  }

  //code for right motor:
  if(right_track_speed>0)
  {
  digitalWrite(right_motor_a, LOW);
  analogWrite(right_motor_b, round(right_track_speed*25*right_motor_weight));
  }
  else
  {
    analogWrite(right_motor_a, round(right_track_speed*(-25)*right_motor_weight));
    digitalWrite(right_motor_b, LOW);
  }

}


void applyBrake()
{
  //sets both bits high, which electricaly connects the motor to itself so that
  //when a rotational force is applied, the motor creates an opposing force acting as brakes
  digitalWrite(left_motor_a, HIGH);
  digitalWrite(left_motor_b, HIGH);
  digitalWrite(right_motor_a, HIGH);
  digitalWrite(right_motor_b, HIGH);
}

void coast()
{
  //sets both pins low, leaving the motor to stop spinning on its own
  digitalWrite(right_motor_a, LOW);
  digitalWrite(right_motor_b, LOW);
  digitalWrite(left_motor_a, LOW);
  digitalWrite(left_motor_b, LOW);
}

void smash()
{
  delay(100);
  drive(-8,-8);
  delay(1500);
  drive(8,8);
  delay(1500);
}
