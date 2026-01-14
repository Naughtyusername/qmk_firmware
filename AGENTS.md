# QMK Firmware Agent Guidelines

This file contains guidelines and commands for AI agents working in the QMK firmware repository.

## Quick Reference Commands

### Building and Compilation
```bash
# Build a specific keyboard/keymap
make keyboard:keymap
qmk compile -kb keyboard -km keymap

# Flash to device
qmk flash -kb keyboard -km keymap

# Clean build artifacts
make clean
```

### Testing
```bash
# Run all unit tests
make test:all

# Run specific test by name
make test:substring

# Run tests with debug output
DEBUG=1 make test:all

# Run Python tests
qmk pytest
```

### Code Quality
```bash
# Format C code (core and keyboards)
qmk format-c --core-only -a
qmk format-c -a

# Format Python code
qmk format-python -a

# Lint keyboard configuration
qmk lint --keyboard keyboard

# Run all quality checks
make format-core
qmk format-python -a
```

### Information and Discovery
```bash
# List available keyboards
qmk list-keyboards

# List keymaps for a keyboard
qmk list-keymaps keyboard

# Get detailed keyboard info
qmk info -l --keyboard keyboard
```

## Code Style Guidelines

### C Code (Primary Language)
- **Standard**: GNU C11 (`-std=gnu11`)
- **Formatting**: Google style (4 spaces, no tabs)
- **Line Length**: 1000 characters (intentionally long for embedded)
- **Pointers**: Right-aligned (`int *ptr`)
- **Headers**: Use `#pragma once` instead of include guards
- **License**: GPL2+ header required on all `.c` and `.h` files

### File Organization
```
keyboards/name/
├── info.json          # Data-driven config (preferred)
├── config.h           # Hardware configuration
├── rules.mk           # Build options
├── name.c            # Keyboard-specific code
├── name.h            # Keyboard declarations
└── keymaps/
    └── default/
        ├── keymap.c
        ├── config.h
        └── rules.mk
```

### Naming Conventions
- **Files**: Lowercase with underscores (`my_keyboard.c`)
- **Functions**: snake_case (`my_function`)
- **Variables**: snake_case (`my_variable`)
- **Constants**: UPPER_CASE (`MY_CONSTANT`)
- **Macros**: UPPER_CASE (`MY_MACRO`)

### Python Code (QMK CLI)
- **Standard**: Python 3.8+
- **Line Length**: 200 characters
- **Tools**: flake8, pep8-naming, pyflakes, yapf
- **Dependencies**: Managed via `requirements.txt` and `requirements-dev.txt`

## Development Patterns

### QMK Abstractions
Always use QMK abstractions instead of direct hardware access:
- **Timing**: `wait_ms()`, `timer_read()`, `timer_read32()`
- **GPIO**: Use QMK GPIO functions
- **I2C/SPI**: Use QMK driver interfaces

### Function Patterns
- **Weak Symbols**: Use `__attribute__((weak))` for overridable functions
- **Callbacks**: Follow `_kb()` and `_user()` function patterns
- **Feature Flags**: Use `#define` for feature enabling/disabling

### Memory Management
- **Embedded Constraints**: Memory is limited, use carefully
- **Static Allocation**: Prefer over dynamic allocation
- **Stack Usage**: Minimize stack usage in interrupt handlers

## Testing Guidelines

### Unit Tests
- **Framework**: Google Test (gtest) and Google Mock
- **Language**: C++ (even for testing C code)
- **Location**: `tests/` directory with feature-specific subdirectories
- **Structure**: Each test has `test.mk`, `config.h`, and `.cpp` files

### Test Structure
```
tests/feature_name/
├── test.mk           # Test configuration
├── config.h         # Test configuration
└── feature_name.cpp # Test implementation
```

### Writing Tests
1. Create test in appropriate `tests/` subdirectory
2. Add `test.mk` with required source files
3. Implement test cases using gtest framework
4. Run with `make test:feature_name`

## Build System

### Makefile Structure
- **Main Makefile**: Root directory with common targets
- **builddefs/**: Build system definitions and utilities
- **rules.mk**: Per-keyboard/keymap build options
- **Indentation**: Tabs (required by Make)

### QMK CLI
- **Preferred Interface**: Use `qmk` commands over raw Makefiles
- **Python-based**: Extensible command-line interface
- **Configuration**: Uses `qmk.ini` for user preferences

### Data-Driven Configuration
- **Preferred Method**: Use `info.json` for keyboard configuration
- **Schema**: Defined in `data/schemas/`
- **Validation**: Automatic validation in CI

## Quality Assurance

### Pre-commit Requirements
1. **Format Code**: Run formatters on all changes
2. **Add Tests**: Unit tests for new features
3. **Update Docs**: Documentation for user-facing changes
4. **Check License**: Ensure GPL2+ headers on new files

### CI/CD Pipeline
- **Format Checking**: `.github/workflows/format.yml`
- **Linting**: `.github/workflows/lint.yml`
- **Unit Testing**: `.github/workflows/unit_test.yml`
- **Build Testing**: Multiple workflows for different platforms

### Common Issues
- **Formatting**: Always run formatters before committing
- **Memory**: Watch stack usage in embedded code
- **Timing**: Use QMK timing functions, not raw delays
- **Platform**: Ensure code works across supported platforms

## Key Directories

### Core Directories
- `quantum/`: Core QMK functionality
- `keyboards/`: Keyboard definitions (1000+ keyboards)
- `tmk_core/`: TMK keyboard core (base framework)
- `platforms/`: Platform-specific code (AVR, ChibiOS, etc.)
- `drivers/`: Hardware drivers
- `tests/`: Unit tests
- `lib/`: External libraries and QMK CLI

### User Directories
- `users/`: Userspace code
- `util/`: Utility scripts
- `docs/`: Documentation
- `data/`: Data files, schemas, templates

## Important Notes

### Embedded Development
- **Resource Constraints**: Memory and processing power are limited
- **Real-time Requirements**: Keyboard code must be responsive
- **Power Management**: Consider power consumption in design

### Community Standards
- **Inclusive Language**: Use inclusive terminology
- **Documentation**: Maintain clear documentation
- **Backward Compatibility**: Avoid breaking existing keyboards

### Platform Support
- **AVR/LUFA**: Classic AVR microcontrollers
- **ChibiOS**: ARM Cortex-M microcontrollers
- **VUSB**: Software USB for AVR

## Debugging

### Debug Builds
```bash
# Enable debug output
DEBUG=1 make keyboard:keymap

# Verbose build
VERBOSE=1 make keyboard:keymap
```

### Common Debug Tools
- **Console Output**: Use `console_print()` for debug output
- **Timer Analysis**: Use timing functions for performance analysis
- **Unit Tests**: Write tests to isolate issues

## Resources

### Documentation
- `docs/pr_checklist.md`: Comprehensive PR guidelines
- `docs/unit_testing.md`: Testing framework documentation
- `docs/understanding_qmk.md`: High-level architecture explanation
- `docs/newbs*.md`: Beginner guides and tutorials

### Community
- **Discord**: QMK Discord server for community support
- **GitHub**: Issues and discussions for technical support
- **Reddit**: r/olkb for community discussion