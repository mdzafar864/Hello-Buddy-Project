# Contributing to Hello Buddy

Thank you for considering contributing to Hello Buddy! 🎉

## How to Contribute

### Reporting Bugs
- Check existing [Issues](../../issues) first to avoid duplicates.
- Include your Arduino board type, sensor/servo model, and steps to reproduce.
- Attach Serial Monitor logs if relevant.

### Suggesting Features
- Open an issue describing the feature and its use case.
- Explain why it would benefit the project.

### Submitting Pull Requests

1. Fork the repository.
2. Create a new branch:
   ```bash
   git checkout -b feature/your-feature-name
   ```
3. Make your changes, following the existing code style (clear comments,
   constants at the top, modular functions).
4. Test your changes on actual hardware if possible.
5. Commit with a clear message:
   ```bash
   git commit -m "Add: brief description of change"
   ```
6. Push to your fork and open a Pull Request against `main`.

## Code Style Guidelines

- Use `UPPER_CASE` for constants, `camelCase` for variables and functions.
- Keep `loop()` non-blocking — avoid long `delay()` calls where possible.
- Add comments explaining *why*, not just *what*.
- Update `CHANGELOG.md` for any user-facing change.

## Documentation Contributions

Improvements to `README.md`, `docs/`, and wiring guides are always welcome —
especially diagrams, photos, and clearer explanations.

## Questions?

Feel free to open a [Discussion](../../discussions) or Issue.
