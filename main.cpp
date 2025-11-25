  #include <Servo.h>

  Servo servo_one;
  Servo servo_two;

  const int AIN1 = 22;
  const int AIN2 = 23;
  const int PWMA = 2;

  const int BIN1 = 28;
  const int BIN2 = 29;
  const int PWMB = 3;

  int motorSpeed = 200;

  void forward(int time) {
    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, LOW);
    analogWrite(PWMA, motorSpeed);

    digitalWrite(BIN1, HIGH);
    digitalWrite(BIN2, LOW);
    analogWrite(PWMB, motorSpeed);
    delay(time);
  }

  void backward(int time) {
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, HIGH);
    analogWrite(PWMA, motorSpeed);

    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, HIGH);
    analogWrite(PWMB, motorSpeed);
    delay(time);
  }

  void stopMotors(int time) {
    analogWrite(PWMA, 0);
    analogWrite(PWMB, 0);

    delay(time);
  }
  int clampAngle(int angle) {
    if (angle < 0)  return 0;
    if (angle > 180) return 180;
    return angle;
  }
  void move_servo_one(int initial_angle, int final_angle) {
    int start = clampAngle(initial_angle);
    int end   = clampAngle(final_angle);
    if (start < end) {
      for (int pos = start; pos <= end; pos++) {
        servo_one.write(pos);
        delay(10);
      }
    } else {
      for (int pos = start; pos >= end; pos--) {
        servo_one.write(pos);
        delay(10);
      }
    }

    delay(500);
  }

  void move_servo_two(int initial_angle, int final_angle) {
    int start = clampAngle(initial_angle);
    int end   = clampAngle(final_angle);
    if (start < end) {
      for (int pos = start; pos <= end; pos++) {
        servo_two.write(pos);
        delay(10);
      }
    } else {
      for (int pos = start; pos >= end; pos--) {
        servo_two.write(pos);
        delay(10);
      }
    }
    delay(5000);
  }

  void f_dropB(int initial_angle, int final_angle){
    int start = clampAngle(initial_angle);
    int end   = clampAngle(final_angle);
    while(start>=end){
      servo_two.write(start);
      start--;
      delay(15);
    }
  }

  void setup() {
    pinMode(AIN1, OUTPUT);
    pinMode(AIN2, OUTPUT);
    pinMode(PWMA, OUTPUT);

    pinMode(BIN1, OUTPUT);
    pinMode(BIN2, OUTPUT);
    pinMode(PWMB, OUTPUT);

    servo_one.attach(4);
    servo_two.attach(5);

    stopMotors(1000);
    servo_one.write(180);
    delay(400);
    servo_two.write(90);
    delay(2000);
    
  }

  void loop() {
    stopMotors(1000);
    backward(4000);
    //delay(2000);
    stopMotors(1000);
    
    move_servo_two(90, 150);   // pick up

    move_servo_one(180, 0);    // lift or move

    servo_one.write(1);
    move_servo_two(150, 60);   // swing back


    forward(2000);
    stopMotors(500);

    f_dropB(60, 0);     // drop
    stopMotors(10000);

  }
