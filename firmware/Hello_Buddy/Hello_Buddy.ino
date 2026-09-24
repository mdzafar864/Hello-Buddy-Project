/*
 * Project: Hello Buddy
 * Description: Ultrasonic sensor detects hand/object proximity and triggers
 *              a servo motor to perform a waving gesture.
 * Components: Arduino Uno, SG90 Servo, HC-SR04 Ultrasonic Sensor
 * Author: [Your Name]
 * Date: [Date]
 */

#include <Servo.h>

// ---------- Pin Definitions ----------
const uint8_t SERVO_PIN     = 9;
const uint8_t TRIG_PIN      = 7;
const uint8_t ECHO_PIN      = 6;

// ---------- Configuration Constants ----------
const int   TRIGGER_DISTANCE_CM = 25;    // Distance threshold to detect hand (25cm range)
const int   REST_ANGLE          = 0;     // Servo resting position
const int   WAVE_ANGLE          = 90;    // Servo wave position
const int   WAVE_STEP_DELAY_MS  = 300;   // Delay between wave movements
const int   WAVE_REPEAT_COUNT   = 2;     // Number of wave cycles
const unsigned long COOLDOWN_MS = 2000;  // Prevent retrigger for this duration
const unsigned long SENSOR_INTERVAL_MS = 50; // Sensor polling rate (faster response)

// ---------- Global Objects & Variables ----------
Servo helloServo;

unsigned long lastTriggerTime = 0;
unsigned long lastSensorRead  = 0;

// ---------- Function Prototypes ----------
int   measureDistanceCM();
void  performHelloWave();
bool  isCooldownActive();

// ==================================================
//                     SETUP
// ==================================================
void setup() {
  Serial.begin(9600);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  helloServo.attach(SERVO_PIN);
  helloServo.write(REST_ANGLE);

  Serial.println(F("Hello Buddy Initialized. Waiting for hand detection..."));
}

// ==================================================
//                     MAIN LOOP
// ==================================================
void loop() {
  unsigned long currentTime = millis();

  // Non-blocking sensor polling
  if (currentTime - lastSensorRead >= SENSOR_INTERVAL_MS) {
    lastSensorRead = currentTime;

    int distance = measureDistanceCM();

    if (distance > 0 && distance < TRIGGER_DISTANCE_CM && !isCooldownActive()) {
      Serial.print(F("Object detected at "));
      Serial.print(distance);
      Serial.println(F(" cm. Triggering wave."));

      performHelloWave();
      lastTriggerTime = currentTime;
    }
  }
}

// ==================================================
//               FUNCTION DEFINITIONS
// ==================================================

/**
 * Measures distance using the HC-SR04 ultrasonic sensor.
 * Returns distance in centimeters, or -1 if no valid echo received.
 */
int measureDistanceCM() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH, 30000); // 30ms timeout

  if (duration == 0) {
    return -1; // No echo received (out of range or error)
  }

  return duration * 0.034 / 2; // Convert to cm
}

/**
 * Performs a waving gesture using the servo motor.
 */
void performHelloWave() {
  for (int i = 0; i < WAVE_REPEAT_COUNT; i++) {
    helloServo.write(WAVE_ANGLE);
    delay(WAVE_STEP_DELAY_MS);
    helloServo.write(REST_ANGLE);
    delay(WAVE_STEP_DELAY_MS);
  }
}

/**
 * Checks whether the system is within its cooldown period
 * to prevent rapid re-triggering.
 */
bool isCooldownActive() {
  return (millis() - lastTriggerTime) < COOLDOWN_MS;
}
