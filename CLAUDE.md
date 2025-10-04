# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

This is an Arduino project for controlling RGB LEDs with blinking patterns. The project is designed to run on Arduino-compatible microcontrollers.

## Development Commands

### Using Arduino CLI

Compile sketch:
```bash
arduino-cli compile --fqbn arduino:avr:uno arduino-rgb-blink
```

Upload to board:
```bash
arduino-cli upload -p COM3 --fqbn arduino:avr:uno arduino-rgb-blink
```

Verify without uploading:
```bash
arduino-cli compile --verify arduino-rgb-blink
```

### Using Arduino IDE

- Open the `.ino` file in Arduino IDE
- Select board: Tools → Board → [your board type]
- Select port: Tools → Port → [your COM port]
- Click "Verify" (checkmark) to compile
- Click "Upload" (arrow) to compile and upload

## Project Structure

Arduino sketches follow this structure:
- `arduino-rgb-blink.ino` - Main sketch file (setup and loop functions)
- Supporting `.cpp` and `.h` files for additional classes/functions (if needed)
- `libraries/` - Custom libraries specific to this project (if any)

## Board Configuration

Common boards for RGB LED projects:
- Arduino Uno: `arduino:avr:uno`
- Arduino Nano: `arduino:avr:nano`
- Arduino Mega: `arduino:avr:mega`
- ESP32: `esp32:esp32:esp32`
- ESP8266: `esp8266:esp8266:nodemcu`

To list available boards:
```bash
arduino-cli board list
```

To install a board platform:
```bash
arduino-cli core install arduino:avr
```

## Library Management

Install libraries:
```bash
arduino-cli lib install "Adafruit NeoPixel"
```

Search for libraries:
```bash
arduino-cli lib search rgb
```

List installed libraries:
```bash
arduino-cli lib list
```

## RGB LED Specifics

This project likely uses one of these approaches:
- **Common Cathode/Anode RGB LEDs**: Direct PWM control on 3 pins (R, G, B)
- **WS2812/NeoPixel**: Addressable LED strips using data protocol
- **APA102/DotStar**: Addressable LEDs with clock and data lines

PWM pins are required for analog RGB control. Check board documentation for PWM-capable pins (usually marked with ~).

## Serial Debugging

Monitor serial output:
```bash
arduino-cli monitor -p COM3 -c baudrate=9600
```

Or use Arduino IDE's Serial Monitor (Tools → Serial Monitor).
