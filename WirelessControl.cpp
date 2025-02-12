/**
 * @file WirelessControl.cpp
 * @brief Real-time wireless control system for the ESP32 Robot.
 * @details Handles PS4 controller input and maps it to motor control.
 */

#include "WirelessControl.h"
#include <PS4Controller.h>

void WirelessControl::init() {
    // Initialize PS4 controller Bluetooth connection
    Serial.println("Initializing PS4 Controller...");
    PS4.begin("01:02:03:04:05:06"); // Replace with your PS4 controller MAC address
}

void WirelessControl::update() {
    if (PS4.isConnected()) {
        // Read PS4 controller analog stick values
        int leftStickX = PS4.LStickX();  // Left stick X-axis (-128 to 127)
        int leftStickY = PS4.LStickY();  // Left stick Y-axis (-128 to 127)

        // Map stick values to motor speeds
        int motorLeft = leftStickY + leftStickX;  // Combine for differential drive
        int motorRight = leftStickY - leftStickX;

        // Send motor speeds to HAL
        HAL::setMotorSpeed(MOTOR_LEFT, motorLeft);
        HAL::setMotorSpeed(MOTOR_RIGHT, motorRight);

        // Debug output
        Serial.printf("Left Stick: X=%d, Y=%d | Motor Left=%d, Motor Right=%d\n", leftStickX, leftStickY, motorLeft, motorRight);
    }
}
