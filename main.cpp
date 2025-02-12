/**
 * @file main.cpp
 * @brief Entry point for the ESP32 Robot Project.
 * @details Initializes all subsystems and runs the main control loop.
 */

#include <PS4Controller.h>
#include "WirelessControl.h"
#include "PowerManagement.h"
#include "HAL.h"
#include "CommunicationProtocol.h"
#include "Utils/MemoryOptimization.h"

void setup() {
    // Initialize serial communication for debugging
    Serial.begin(115200);
    Serial.println("ESP32 Robot Initializing...");

    // Initialize subsystems
    WirelessControl::init();
    PowerManagement::init();
    HAL::init();
    CommunicationProtocol::init();

    Serial.println("ESP32 Robot Ready!");
}

void loop() {
    // Main control loop
    if (PS4.isConnected()) {
        WirelessControl::update();       // Handle PS4 controller input
        PowerManagement::optimize();    // Optimize power distribution
        HAL::update();                   // Update motor states
        CommunicationProtocol::checkConnection(); // Ensure stable connection
    } else {
        Serial.println("PS4 Controller Disconnected!");
    }

    // Add a small delay to prevent CPU overuse
    delay(10);
}
