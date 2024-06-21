//each motor is controled by two pins,(plus an enable pin) and depening on what combination of values
//you set the pins to you can get it to move in the desired direction
#define left_motor_sleep 16
#define left_motor_a 5
#define left_motor_b 6
#define left_motor_weight 1 //the final value sent to the motor will be multipled by this. set it between 0 and 1


#define right_motor_sleep 2
#define right_motor_a 3
#define right_motor_b 11
#define right_motor_weight 0.87 //the final value sent to the motor will be multipled by this. set it between 0 and 1






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
  pinMode(A7, INPUT);

  //turn on the motor drivers
  digitalWrite(left_motor_sleep, HIGH);
  digitalWrite(right_motor_sleep, HIGH);




}

void loop() {
  // put your main code here, to run repeatedly:
  if((analogRead(6))>500)
  {
    drive(5,0);
  }
  else
  {
    drive(0,5);
  }


}


void drive(int left_track_speed,int right_track_speed)
{
  //drive Forwards by setting a=1 and b=0. to get different speeds, we PWM one of the pins.
  //The parameters passed in have a value from -10 to 10, of which negitive speeds will drive backwards.
  //Motors will contuniously spin untill either the applyBrake() or coast() functions are called.

  //code for left motor:
  if(left_track_speed>0)
  {
  digitalWrite(left_motor_a, LOW);
  analogWrite(left_motor_b, (left_track_speed*25*left_motor_weight));
  }
  else
  {
    analogWrite(left_motor_a, (left_track_speed*(-25)*left_motor_weight));
    digitalWrite(left_motor_b, LOW);
  }

  //code for right motor:
  if(right_track_speed>0)
  {
  digitalWrite(right_motor_a, LOW);
  analogWrite(right_motor_b, (right_track_speed*25*right_motor_weight));
  }
  else
  {
    analogWrite(right_motor_a, (right_track_speed*(-25)*right_motor_weight));
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
