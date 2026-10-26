# Piano Sampler

A standalone sampler built with an ESP32. Touch a pad and it plays a sound from an SD card.

<img width="1182" height="882" alt="image" src="https://github.com/user-attachments/assets/4d185c69-89ae-44e0-93a0-4e89ef57a1f6" />

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

## CAD Model

Enclosure designed in Onshape: [View Onshape Model](https://cad.onshape.com/documents/551233cc762d0b86e6aad035/w/fb25114a87d42144b650da94/e/d1c483ae397747764a2a6bec)

---

## Wiring

- **Schematic:** [Piano Sampler.kicad_sch](https://github.com/Shashvat1333/Piano-Sampler/blob/main/Piano%20Sampler.kicad_sch)
- **Full wiring:** [Wiring Diagram.md](https://github.com/Shashvat1333/Piano-Sampler/blob/main/Wiring%20Diagram.md)

<img width="1231" height="745" alt="image" src="https://github.com/user-attachments/assets/3d34e765-1810-4f9a-b2bb-7769f75a543c" />

---

## Firmware

- **Code:** [FIRMWARE.ino](https://github.com/Shashvat1333/Piano-Sampler/blob/main/firmware.ino)
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
