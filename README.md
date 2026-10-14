# LDR-Controlled LED with Arduino Nano ESP32

A beginner embedded project that reads ambient light with an LDR (Light-Dependent
Resistor) through the ADC and drives an LED based on the measured value. The raw
ADC reading is also printed over serial.

![Demo](docs/images/demo.jpg)

## Features
- Analog light sensing with an LDR in a voltage divider
- LED output controlled by a light threshold
- Live ADC value printed to the Serial Monitor

## Hardware

| Component              | Qty | Notes                        |
|------------------------|-----|------------------------------|
| Arduino Nano ESP32     | 1   |                              |
| LDR (photoresistor)    | 1   |                              |
| Resistor 1 kΩ          | 1   | Voltage divider with LDR     |
| LED (any color)        | 1   |                              |
| Resistor 120 Ω         | 1   | LED current limiting         |
| Breadboard             | -   |                              |
| Jumper wires           | 5   |                              |

## Schematic

![Schematic](hardware/schematic/ldr-led-schematic.pdf)

## Pin Connections

| Signal        | Nano ESP32 pin |
|---------------|----------------|
| LDR divider   | A0             |
| LED (via 220Ω)| D13            |

## How It Works
The LDR and a fixed resistor form a voltage divider. As light increases, the LDR's
resistance drops and the voltage at A0 changes. The ESP32's 12-bit ADC converts it
to a value from 0 to 4095. When the value crosses a threshold, the LED toggles.

## Getting Started

### Requirements
- Arduino IDE 2.x (or PlatformIO)
- Board package: **Arduino ESP32 Boards**

### Build and upload
1. Clone the repo: `git clone https://github.com/<your-username>/ldr-led-nano-esp32.git`
2. Open `src/main/main.ino`
3. Select **Arduino Nano ESP32** as the board
4. Upload and open the Serial Monitor at 9600 baud

## Example Output
```
ADC: 79
ADC: 72
ADC: 71
```

## Future Improvements
- Add hysteresis to avoid LED flickering near the threshold
- PWM dimming proportional to light level
- Publish readings over Wi-Fi/MQTT

## License
MIT