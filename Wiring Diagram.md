# Piano Sampler Wiring Diagram

<img width="1231" height="745" alt="image" src="https://github.com/user-attachments/assets/b213d30e-a9a8-4763-8047-163fe416e241" />


## 1. SD Card Module (SPI Interface)
| ESP32 Pin | SD Card Pin | Signal Description |
| :--- | :--- | :--- |
| IO33 | CS | Chip Select |
| IO32 | SCK | Serial Clock |
| IO23 | MOSI | Master Out / Slave In |
| IO35 | MISO | Master In / Slave Out |
| 3.3V | VCC | 3.3V Power |
| GND | GND | Ground |

## 2. MAX98357A I2S Amplifier & Speaker
| ESP32 / Power | Amplifier Pin | Signal Description |
| :--- | :--- | :--- |
| 5V | VCC | 5V Power Supply |
| GND | GND | Ground |
| 3.3V | SD | Shutdown / Mode Select |
| GND | GAIN | Gain Control (GND for default) |
| IO25 | DIN | Data Input |
| IO26 | BLCK | Bit Clock |
| IO27 | LRC | Left / Right Clock |
| Speaker + | Output + | 8-Ohm Speaker Positive |
| Speaker - | Output - | 8-Ohm Speaker Negative |

## 3. 1602 LCD Display (I2C Interface)
| ESP32 Pin | LCD Pin | Signal Description |
| :--- | :--- | :--- |
| IO22 | SCL | I2C Clock Line |
| IO21 | SDA | I2C Data Line |
| 5V | VDD | 5V Power Supply |
| GND | GND | Ground |

## 4. Volume Potentiometer
| ESP32 Pin | Potentiometer Pin | Signal Description |
| :--- | :--- | :--- |
| 3.3V | Pin 1 | High Reference Voltage |
| IO34 | Pin 2 (Wiper) | Analog Input |
| GND | Pin 3 | Ground |

## 5. Control Push Buttons
| ESP32 Pin | Button Pin | Function |
| :--- | :--- | :--- |
| GND | Leg 1 (Shared) | Common Ground Rail |
| IO16 | Leg 2 (Button 1) | Next Preset |
| IO17 | Leg 2 (Button 2) | Previous Preset |
| IO18 | Leg 2 (Button 3) | Record |
| IO19 | Leg 2 (Button 4) | Play |

## 6. Capacitive Touch Sensors
| ESP32 Pin | Sensor Pin | Function |
| :--- | :--- | :--- |
| 3.3V | VCC (Shared) | 3.3V Power Rail |
| GND | GND (Shared) | Common Ground Rail |
| IO0 | Sensor 1 | Touch Pad 1 |
| IO2 | Sensor 2 | Touch Pad 2 |
| IO4 | Sensor 3 | Touch Pad 3 |
| IO5 | Sensor 4 | Touch Pad 4 |
| IO12 | Sensor 5 | Touch Pad 5 |
| IO13 | Sensor 6 | Touch Pad 6 |
| IO15 | Sensor 7 | Touch Pad 7 |
