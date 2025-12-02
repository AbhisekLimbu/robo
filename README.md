![Uploading robo.jpeg…]()


# Arduino Grab & Drop Robot

This project controls a robot with:

* 2 DC motors
* 2 servo motors
* An Arduino controller

It moves a ball from one place to another using a simple sequence:
**move → grab → lift → move → drop**.

## Hardware

* Arduino
* Motor driver
* 2 DC motors
* 2 servo motors
* External 5–6V power supply

## Pin Setup

**Motors**

* AIN1 → 22
* AIN2 → 23
* PWMA → 2
* BIN1 → 28
* BIN2 → 29
* PWMB → 3

**Servos**

* Servo 1 → 4
* Servo 2 → 5

## Notes

* Servos must use an external power supply.
* Ground must be shared with Arduino.
* Adjust servo angles based on your arm design.

Project designed and built by **ME Teams**. Software developed by **Abhisek & Matt**.

