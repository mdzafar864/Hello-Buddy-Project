# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [1.0.0] - 2026-09-24

### Added
- Initial release of Hello Buddy.
- Ultrasonic sensor (HC-SR04) based hand/object detection.
- SG90 servo motor waving gesture on detection.
- Non-blocking sensor polling using `millis()`.
- Cooldown mechanism to prevent rapid re-triggering.
- Configurable detection distance (default: 25 cm).
- Serial Monitor debug output for live distance readings.
- Full project documentation, wiring guide, and BOM.

### Changed
- Detection range increased from 15 cm to 25 cm for earlier trigger.
- Sensor polling interval reduced from 100ms to 50ms for faster response.

## [Unreleased]

### Planned
- LCD/OLED status display support.
- LED indicator for detection events.
- Multiple gesture patterns.
