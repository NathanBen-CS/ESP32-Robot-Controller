/**
 * @file HAL.cpp
 * @brief Hardware Abstraction Layer for the ESP32 Robot.
 * @details Provides a modular interface for motor and sensor control.
 */

#include "HAL.h"

// Motor pins (replace with your actual pin numbers)
#define MOTOR_LEFT_PIN1 25
#define MOTOR_LEFT_PIN2 26
#define MOTOR_RIGHT_PIN1 27
#define MOTOR_RIGHT_PIN2 14

void HAL::init() {
    Serial.println("Initializing Hardware Abstraction Layer...");

    // Set motor pins as outputs
    pinMode(MOTOR_LEFT_PIN1, OUTPUT);
    pinMode(MOTOR_LEFT_PIN2, OUTPUT);
    pinMode(MOTOR_RIGHT_PIN1, OUTPUT);
    pinMode(MOTOR_RIGHT_PIN2, OUTPUT);
}

void HAL::setMotorSpeed(Motor motor, int speed) {
    // Map speed (-128 to 127) to PWM (0 to 255)
    int pwm = map(abs(speed), 0, 127, 0, 255);

    // Set motor direction and speed
    if (motor == MOTOR_LEFT) {
        digitalWrite(MOTOR_LEFT_PIN1, speed > 0 ? HIGH : LOW);
        digitalWrite(MOTOR_LEFT_PIN2, speed > 0 ? LOW : HIGH);
        analogWrite(MOTOR_LEFT_PIN1, pwm);
    } else if (motor == MOTOR_RIGHT) {
        digitalWrite(MOTOR_RIGHT_PIN1, speed > 0 ? HIGH : LOW);
        digitalWrite(MOTOR_RIGHT_PIN2, speed > 0 ? LOW : HIGH);
        analogWrite(MOTOR_RIGHT_PIN1, pwm);
    }
}

void HAL::limitMotorPower(int percent) {
    // Example: Limit motor power (not implemented in this example)
    Serial.printf("Motor Power Limited to %d%%\n", percent);
}
