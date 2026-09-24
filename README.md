![Hello Buddy Banner](docs/images/Hello%20Buddy%20Project.png)

# 👋 Hello Buddy — Arduino Interactive Robotic Hand Prototype

An Arduino-based interactive project where a servo motor waves "hello" automatically when it detects your hand (or any object) nearby — no touch required!

![Status](https://img.shields.io/badge/status-active-brightgreen)
![Platform](https://img.shields.io/badge/platform-Arduino-teal)
![License](https://img.shields.io/badge/license-MIT-blue)

## 📋 Overview

**Hello Buddy** uses an ultrasonic distance sensor (HC-SR04) to detect proximity. When an object comes within range, an SG90 servo motor performs a friendly waving gesture — like a little robot greeting you.

## 📁 Repository Structure

```
Hello-Buddy-Project/
├── docs/
│   ├── images/          # Photos, banner & screenshots
│   └── OVERVIEW.md      # Detailed documentation
├── firmware/
│   └── Hello_Buddy/     # Main Arduino sketch (.ino)
├── hardware/
│   ├── components/      # Bill of materials & component datasheets
│   └── wiring/          # Circuit diagrams & wiring guide
├── src/                 # Additional source/helper code
├── video/               # Demo video / link
├── CHANGELOG.md
├── CITATION.cff
├── CODE_OF_CONDUCT.md
├── CONTRIBUTING.md
├── LICENSE
├── README.md
└── SECURITY.md
```

## 🛠️ Components Required

| Component | Quantity |
|---|---|
| Arduino Uno | 1 |
| SG90 Micro Servo Motor | 1 |
| HC-SR04 Ultrasonic Sensor | 1 |
| Jumper Wires | As needed |
| Breadboard (optional) | 1 |
| USB Cable (for Arduino) | 1 |

See [`hardware/components/BOM.md`](hardware/components/BOM.md) for full details and datasheets.

## 🔌 Circuit Connections

**Servo (SG90):**
| Servo Pin | Arduino Pin |
|---|---|
| Signal (Orange/Yellow) | Pin 9 |
| VCC (Red) | 5V |
| GND (Brown/Black) | GND |

**Ultrasonic Sensor (HC-SR04):**
| Sensor Pin | Arduino Pin |
|---|---|
| VCC | 5V |
| Trig | Pin 7 |
| Echo | Pin 6 |
| GND | GND |

Full wiring diagram: [`hardware/wiring/`](hardware/wiring/)

## ⚙️ How It Works

1. The HC-SR04 sensor continuously measures distance to the nearest object.
2. When an object is detected within **25 cm**, the servo triggers a wave gesture.
3. A cooldown period prevents the servo from re-triggering immediately.
4. The system uses non-blocking timing (`millis()`), so it stays responsive at all times.

## 🚀 Getting Started

1. Wire the components as per the connection table above.
2. Install the **Servo** library (usually pre-installed with Arduino IDE).
3. Open [`firmware/Hello_Buddy/Hello_Buddy.ino`](firmware/Hello_Buddy/Hello_Buddy.ino) in Arduino IDE.
4. Select **Board: Arduino Uno** and the correct **Port**.
5. Upload the sketch.
6. Open the Serial Monitor (9600 baud) to see live distance readings.
7. Wave your hand within 25 cm of the sensor and watch Hello Buddy greet you!

## 🔧 Customization

You can tweak these constants in the code to change behavior:

| Constant | Description | Default |
|---|---|---|
| `TRIGGER_DISTANCE_CM` | Detection range | 25 cm |
| `WAVE_ANGLE` | Servo wave angle | 90° |
| `WAVE_REPEAT_COUNT` | Number of wave cycles | 2 |
| `COOLDOWN_MS` | Delay before re-triggering | 2000 ms |

## 📸 Demo

See [`docs/images/`](docs/images/) for photos and [`video/`](video/) for a demo clip.

## 🤝 Contributing

Contributions are welcome! Please read [CONTRIBUTING.md](CONTRIBUTING.md) before submitting a pull request.

## 🔒 Security

For reporting vulnerabilities, see [SECURITY.md](SECURITY.md).

## 📜 Code of Conduct

This project follows the guidelines in [CODE_OF_CONDUCT.md](CODE_OF_CONDUCT.md).

## 📄 License

This project is licensed under the MIT License — see [LICENSE](LICENSE) for details.

## 🙌 Author

Made with ❤️ using Arduino
