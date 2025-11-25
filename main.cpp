#include <Servo.h>

// Servos
Servo servo_one;
Servo servo_two;

// Motor A (Left)

// Speed value
int motorSpeed = 200;

// ==================== HELPER ====================

// Just make sure the angle is between 0 and 185
int angle_output(int angle_input) {
  if (angle_input < 0)  angle_input = 0;
  if (angle_input > 185) angle_input = 185;
  return angle_input;
}

// ==================== MOTOR CONTROL FUNCTIONS ====================



// ==================== SERVO ONE ====================

void move_servo_one(int angle1, angle2) {
  // Sweep back from 180° to 0°
  for (int pos = angle_output(angle1); pos >= angle_output(angle2); pos--) {
    servo_one.write(pos);
    delay(10);
  }
  delay(500);
}

// ==================== SERVO TWO HELPERS ====================

// open / raise
void o_move_servo_two(int angle1, angle2) {
  for (int pos = angle_output(angle1); pos <= angle_output(angle2); pos++) {
    servo_two.write(pos);   
    delay(10);
  }
}

// swing back
void s_move_servo_two() {
  for (int pos = angle_output(150); pos >= angle_output(60); pos--) {
    servo_two.write(pos);   
    delay(10);
  }
}

// drop / lower a bit
void drop_b_servo_two() {
  for (int pos = angle_output(60); pos >= angle_output(0); pos--) {
    servo_two.write(pos);   
    delay(20);
  }
}

// main action for servo_two used in loop()
void move_servo_two() {
  o_move_servo_two();
}

void setup() {

  servo_one.attach(4);
  servo_two.attach(5);

  // Start positions
  servo_one.write(angle_output(180));
  delay(200);
  servo_two.write(angle_output(90));
  delay(500);
}

// ==================== LOOP ====================

void loop() {
  move_servo_two(90,120);
  move_servo_one(15, 0);

}
