#include <Servo.h>

// Servos
Servo servo_one;
Servo servo_two;

// Motor A (Left)
const int AIN1 = 22;
const int AIN2 = 23;
const int PWMA = 9;   // CHANGED to real PWM pin

// Motor B (Right)
const int BIN1 = 28;
const int BIN2 = 29;
const int PWMB = 10;  // CHANGED to real PWM pin

// Speed value
long int motorSpeed = 200;

// ==================== MOTOR CONTROL FUNCTIONS ====================

long int angle_output(int angle_input){
  int range = 1023 * (angle_input/180);
  return  map(range, 0, 1023,0, 1);
  
}
void forward() {
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  analogWrite(PWMA, motorSpeed);

  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
  analogWrite(PWMB, motorSpeed);
}

void backward() {
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  analogWrite(PWMA, motorSpeed);

  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
  analogWrite(PWMB, motorSpeed);
}

void stopMotors() {
  analogWrite(PWMA, 0);
  analogWrite(PWMB, 0);
}

void move_servo_one(){
  for(int pos = angle_output(0); pos < angle_output(180); pos++){
      servo_one.write(pos);
      delay(10);
  }
}

// ==================== SERVO FUNCTION ====================

// void move_servo_two()
// {
//   // old sweep code commented out by you:
//   // for (int pos = 0; pos <= 180; pos++) {
//   //   servo_two.write(pos);
//   //   delay(15);  // smoother than 20
//   // }
//   // delay(500);

//   // for (int range = 0; range < 1023; range++)
//   // {
//   //   int angle = map(range, 0, 1023, 0, 185);
//   //   servo_two.write(angle);
//   //   delay(10);
//   // }

//   // for (int range = 1023; range >= 0; range--)
//   // {
//   //   int angle = map(range, 0, 1023, 0, 185);
//   //   servo_two.write(angle);
//   //   delay(7);
//   // }

//   for(int angle = 0; angle < 185; angle++)
//   {
//     servo_two.write(angle);
//     delay(15);
//   }
// }  // <-- needed to close move_servo_two()

// ==================== SETUP ====================

void setup() {
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWMA, OUTPUT);

  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(PWMB, OUTPUT);

  servo_one.attach(4);
  servo_two.attach(5);

  servo_two.write(angle_output(90));   // Start at known position
  // servo_one.write(angle_output(0));
  // delay(10);
  servo_one.write(angle_output(180)); 
  delay(500);

  stopMotors();   // Safe start
}

// ==================== LOOP ====================

void loop() {

  // Comment these out if you just want servo testing:
  // forward();
  // delay(3000);
  // stopMotors();
  // delay(500);

  move_servo_one();
}
