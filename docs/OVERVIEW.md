# Hello Buddy — Detailed Documentation

## 1. Introduction

Hello Buddy is a beginner-friendly Arduino project that demonstrates proximity sensing combined with servo motor control to create an interactive, gesture-based greeting device.

## 2. Working Principle

The HC-SR04 ultrasonic sensor works on the principle of **echolocation**:
1. The `Trig` pin sends out a 10µs ultrasonic pulse.
2. This pulse travels through air and reflects off any nearby object.
3. The `Echo` pin receives the reflected pulse.
4. The time taken (`duration`) is used to calculate distance:

```
distance (cm) = duration × 0.034 / 2
```

When this distance falls below the configured threshold (default: 25 cm), the Arduino commands the SG90 servo to sweep between 0° and 90° — simulating a wave.

## 3. Software Architecture

- **Non-blocking design**: Uses `millis()` instead of `delay()` in the main loop for sensor polling, keeping the system responsive.
- **Cooldown logic**: Prevents the wave gesture from re-triggering immediately after it completes.
- **Timeout-protected sensing**: `pulseIn()` uses a 30ms timeout to avoid the program hanging if no echo is received.

## 4. Flow Diagram

```
   [Power On]
        |
        v
 [Initialize Servo & Pins]
        |
        v
 [Measure Distance] <-------+
        |                   |
   Distance < 25cm?         |
    /        \              |
  Yes         No            |
   |           \_____________|
   v
[Trigger Wave Gesture]
   |
   v
[Start Cooldown Timer]
   |
   v
(back to Measure Distance)
```

## 5. Future Improvements

- Add an LCD/OLED display to show live distance readings.
- Add an LED indicator for detection status.
- Support multiple gesture patterns (wave, nod, spin).
- Add sound feedback via a buzzer.

## 6. Troubleshooting

| Issue | Possible Cause | Fix |
|---|---|---|
| Servo doesn't move | Wrong pin / loose wiring | Check Pin 9 connection |
| Distance always -1 | Sensor wiring reversed | Verify Trig/Echo pins |
| Servo jitters | Insufficient power | Use external 5V supply for servo |
| Triggers too often | Distance threshold too high | Lower `TRIGGER_DISTANCE_CM` |
