# Wiring Guide

## Connection Table

### SG90 Servo Motor → Arduino Uno
| Servo Wire | Color (typical) | Arduino Pin |
|---|---|---|
| Signal | Orange / Yellow | Digital Pin 9 |
| VCC | Red | 5V |
| GND | Brown / Black | GND |

### HC-SR04 Ultrasonic Sensor → Arduino Uno
| Sensor Pin | Arduino Pin |
|---|---|
| VCC | 5V |
| Trig | Digital Pin 7 |
| Echo | Digital Pin 6 |
| GND | GND |

## Schematic (Text Representation)

```
                 ┌─────────────────┐
                 │   Arduino Uno   │
                 │                 │
   HC-SR04       │                 │        SG90 Servo
  ┌────────┐     │                 │       ┌──────────┐
  │  VCC   ├─────┤ 5V              │       │          │
  │  Trig  ├─────┤ D7          D9  ├───────┤ Signal   │
  │  Echo  ├─────┤ D6              │       │          │
  │  GND   ├─────┤ GND         5V  ├───────┤ VCC      │
  └────────┘     │             GND ├───────┤ GND      │
                 └─────────────────┘       └──────────┘
```

## ⚠️ Important Notes

1. **Power supply**: If using multiple servos or the servo jitters, power it from an external 5V source instead of the Arduino's 5V pin, and connect grounds together.
2. **Sensor orientation**: Mount the HC-SR04 facing the direction you want to detect hand movement from.
3. **Double-check polarity**: Reversed VCC/GND can damage the sensor or servo.

## Photos / Diagrams

Add your actual circuit photos and Fritzing diagrams to this folder (e.g., `circuit_diagram.png`, `breadboard_photo.jpg`).
