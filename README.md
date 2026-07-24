# Smart Automated Garage System

This project involves the development of a fully automated, bidirectional smart gate system utilizing an Arduino microcontroller[cite: 2]. By implementing a dual-sensor system, the gate functions completely hands-free, seamlessly detecting and adapting to both entering and exiting vehicles to provide realistic and smooth automation[cite: 2].

## Features
* **Bidirectional Detection:** Utilizes two ultrasonic sensors to monitor both the outside approach and the inside exit of the garage[cite: 2].
* **Smooth Gate Actuation:** Custom functions gradually rotate the servo motor (15 milliseconds per degree) to simulate a realistic, heavy gate movement[cite: 1].
* **Auto-Close Logic:** The system continuously monitors the vehicle's presence and safely closes the gate after the area is clear[cite: 1].

## Bill of Materials (BOM)
To build this project, you will need the following components[cite: 2]:
* Arduino Uno (R3)[cite: 2]
* Ultrasonic Sensor (HC-SR04) (X2)[cite: 2]
* Servo Motor (SG90) (X1)[cite: 2]
* Breadboard (X1)[cite: 2]
* Jumper Wires (X20)[cite: 2]
* USB Cable[cite: 2]

## System Workflow
1. **Entry Process:** One ultrasonic sensor is placed on the outside of the garage to detect the presence of a vehicle approaching from the outside road[cite: 2].
2. **Exit Process:** A second ultrasonic sensor is positioned inside the garage, facing the exit, to detect when a vehicle is moving towards the closed gate to leave[cite: 2].
3. **Trigger Mechanism:** The code is configured with distance thresholds of 30 cm for the outside sensor and 20 cm for the inside sensor[cite: 1]. If a vehicle is detected within these ranges, a signal is instantly sent to the Arduino[cite: 1, 2].
4. **Gate Operation:** The Arduino triggers the Servo Motor to rotate 90 degrees smoothly, lifting the barrier[cite: 1, 2]. The gate remains open, and once the vehicle clears the area, it automatically closes back to its original position after a set delay[cite: 1, 2].

## Circuit Diagram & Connections

![Circuit Diagram](Circuit_Diagram.jpg)

### Power Distribution
* Connect the Arduino 5V pin to the bottom Red (+) rail of the breadboard[cite: 2].
* Connect the Arduino GND pin to the bottom Blue/Black (-) rail of the breadboard[cite: 2].
* Jump a wire from the bottom rails to the top rails to ensure both sides of the breadboard have power[cite: 2].

### Outside Ultrasonic Sensor
* **VCC:** Breadboard Positive (+) line[cite: 2]
* **Trig:** Arduino Digital Pin D2[cite: 2]
* **Echo:** Arduino Digital Pin D3[cite: 2]
* **GND:** Breadboard Negative (-) line[cite: 2]

### Inside Ultrasonic Sensor
* **VCC:** Breadboard Positive (+) line[cite: 2]
* **Trig:** Arduino Digital Pin D4[cite: 2]
* **Echo:** Arduino Digital Pin D5[cite: 2]
* **GND:** Breadboard Negative (-) line[cite: 2]

### SG90 Servo Motor
* **GND (Brown/Black):** Breadboard Negative (-) line[cite: 2]
* **VCC (Red):** Breadboard Positive (+) line[cite: 2]
* **Signal (Orange/Yellow):** Arduino Digital Pin D9[cite: 2]

## How to Run
1. Assemble the hardware on a breadboard exactly as described in the wiring section and circuit diagram[cite: 2].
2. Connect the Arduino Uno to your computer via USB[cite: 2].
3. Open the `.ino` file in the Arduino IDE.
4. Go to **Tools > Board** and select "Arduino Uno".
5. Go to **Tools > Port** and select your active COM port.
6. Click **Upload** to flash the code to the microcontroller[cite: 2].
7. Open the Serial Monitor (baud rate 9600) to view system status logs[cite: 1].
