# Piano Sampler

A standalone sampler built with an ESP32. Touch a pad and it plays a sound from an SD card.

<img width="616" height="752" alt="Piano Sampler Project" src="PASTE_YOUR_IMAGE_LINK_HERE" />

## Table of Contents
- [What It Does](#what-it-does)
- [Repository Structure](#repository-structure)
- [CAD Model](#cad-model)
- [Wiring](#wiring)
- [Firmware](#firmware)
- [Getting Started](#getting-started)
- [Bill of Materials (BOM)](#bill-of-materials-bom)
- [License](#license)

## What It Does

- **7 touch pads:** Touch a pad to play a sound.
- **5 instrument presets:** Acoustic Piano, Banjo, Guitar, Percussion, and Saxophone.
- **Record and play:** Record your own audio and play it back.
- **Volume knob and LCD:** Adjust the volume and see the current preset.

---

## Repository Structure

```
Piano-Sampler/
├── FIRMWARE.ino
├── Piano Sampler.kicad_sch
├── Wiring Diagram.md
├── CAD/
├── images/
├── BOM.md
├── LICENSE.md
└── README.md
```

---

## CAD Model

Enclosure designed in Onshape: [View Onshape Model](PASTE_YOUR_ONSHAPE_LINK_HERE)

---

## Wiring

- **Schematic:** [Piano Sampler.kicad_sch](https://github.com/Shashvat1333/Piano-Sampler/blob/main/Piano%20Sampler.kicad_sch)
- **Full wiring:** [Wiring Diagram.md](https://github.com/Shashvat1333/Piano-Sampler/blob/main/Wiring%20Diagram.md)

| Component | ESP32 GPIO | Power (+) | Ground (–) |
|---|---|---|---|
| SD Card CS | GPIO 33 | 3.3V | GND |
| SD Card SCK | GPIO 32 | 3.3V | GND |
| SD Card MOSI | GPIO 23 | 3.3V | GND |
| SD Card MISO | GPIO 35 | 3.3V | GND |
| I2S DIN (Amp) | GPIO 25 | 5V / VIN | GND |
| I2S BCLK (Amp) | GPIO 26 | 5V / VIN | GND |
| I2S LRC (Amp) | GPIO 27 | 5V / VIN | GND |
| LCD SCL (I2C) | GPIO 22 | 5V / VIN | GND |
| LCD SDA (I2C) | GPIO 21 | 5V / VIN | GND |
| Volume Wiper | GPIO 34 (ADC) | 3.3V | GND |
| Next Preset Button | GPIO 16 | Internal Pullup | GND Rail |
| Prev Preset Button | GPIO 17 | Internal Pullup | GND Rail |
| Record Button | GPIO 18 | Internal Pullup | GND Rail |
| Play Button | GPIO 19 | Internal Pullup | GND Rail |
| Touch Pads 1–7 | GPIO 0, 2, 4, 5, 12, 13, 15 | 3.3V | GND Rail |

<img width="675" height="537" alt="Wiring Schematic" src="PASTE_YOUR_WIRING_IMAGE_LINK_HERE" />

---

## Firmware

- **Code:** [FIRMWARE.ino](https://github.com/Shashvat1333/Piano-Sampler/blob/main/FIRMWARE.ino)
- **Libraries:** `SD`, `SPI`, `Wire`, `LiquidCrystal_I2C`, `driver/i2s.h`
- **Board:** ESP32 Dev Module

---

## Getting Started

1. **Prepare the SD card:** Format it as FAT32 and add one folder per instrument, each with `1.wav` to `7.wav`:
   ```text
   /Acoustic Piano/
   /Banjo/
   /Guitar/
   /Percussion/
   /Saxophone/
   ```
2. **Assemble the hardware:** Melt the heat-set inserts into the printed frame, mount the components, and solder the connections using the wiring table.
3. **Upload the code:** Open `FIRMWARE.ino` in the Arduino IDE, install the libraries, select **ESP32 Dev Module**, and upload.
4. **Power and play:** Insert the SD card, power the board over USB or an external supply, and start touching pads.

---

## Bill of Materials (BOM)

| Item | Qty | Supplier | Cost/item | Total Cost | Link |
|------|-----|----------|-----------|------------|------|
| Mini Speaker | 1 | AliExpress | $4.84 | $4.84 | [Link](https://www.aliexpress.com/item/1005009465850637.html) |
| ESP32-32D Kit | 1 | AliExpress | $14.03 | $14.03 | [Link](https://www.aliexpress.com/item/1005007820190456.html) |
| Touch Button Module | 1 | AliExpress | $3.85 | $3.85 | [Link](https://www.aliexpress.com/item/1005006246380749.html) |
| MAX98357 Amplifier | 1 | AliExpress | $3.19 | $3.19 | [Link](https://www.aliexpress.com/item/1005007629020891.html) |
| 10k Potentiometer | 1 | AliExpress | $3.40 | $3.40 | [Link](https://www.aliexpress.com/item/4001274951434.html) |
| Jumper Wires | 1 | AliExpress | $6.60 | $6.60 | [Link](https://www.aliexpress.com/item/1005005956620164.html) |
| Micro SD Card Module | 1 | AliExpress | $1.87 | $1.87 | [Link](https://www.aliexpress.com/item/1005006457603056.html) |
| **Total** | | | | **$37.78** | |

---

## License

This project is licensed under the terms in [LICENSE.md](https://github.com/Shashvat1333/Piano-Sampler/blob/main/LICENSE.md).
