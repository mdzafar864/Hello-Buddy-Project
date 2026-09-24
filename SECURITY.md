# Security Policy

## Supported Versions

| Version | Supported          |
| ------- | ------------------ |
| 1.0.x   | ✅ Yes              |
| < 1.0   | ❌ No               |

## Reporting a Vulnerability

This is a hobbyist Arduino hardware project, so "security" mainly concerns:

- Safe electrical/hardware practices (avoiding short circuits, overcurrent, etc.)
- Any issues in code that could cause unintended hardware behavior (e.g.,
  servo damage from incorrect angle values, sensor misreads causing unsafe
  motion in a physical setup)

If you discover such an issue:

1. Do **not** open a public issue with exploit-style details.
2. Instead, contact the maintainer directly via GitHub (see profile) or email.
3. Include a clear description and, if possible, steps to reproduce.

We'll aim to acknowledge reports within a few days and release a fix or
mitigation guidance as soon as possible.

## Scope

This policy covers the firmware and documentation in this repository. It does
not cover third-party libraries (e.g., the Arduino `Servo` library) — please
report issues in those directly to their respective maintainers.
