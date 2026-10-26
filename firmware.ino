#include <SPI.h>
#include <SD.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "driver/i2s.h"

const int SD_CS_PIN = 33;
const int SD_SCK_PIN = 32;
const int SD_MOSI_PIN = 23;
const int SD_MISO_PIN = 35;

const int I2S_BCLK = 26;
const int I2S_LRC = 27;
const int I2S_DIN = 25;

const int LCD_SDA = 21;
const int LCD_SCL = 22;

const int POT_PIN = 34;

const int NEXT_BTN_PIN = 16;
const int PREV_BTN_PIN = 17;
const int REC_BTN_PIN = 18;
const int PLAY_BTN_PIN = 19;

const int TOUCH_PINS[7] = {0, 2, 4, 5, 12, 13, 15};

LiquidCrystal_I2C lcd(0x27, 16, 2);

const char* presetFolders[] = {
  "/Acoustic Piano",
  "/Banjo",
  "/Guitar",
  "/Percussion",
  "/Saxophone"
};

int activePreset = 0;
int totalPresets = 5;
bool isRecording = false;
File recordingFile;

void setup() {
  Serial.begin(115200);
  
  pinMode(NEXT_BTN_PIN, INPUT_PULLUP);
  pinMode(PREV_BTN_PIN, INPUT_PULLUP);
  pinMode(REC_BTN_PIN, INPUT_PULLUP);
  pinMode(PLAY_BTN_PIN, INPUT_PULLUP);

  Wire.begin(LCD_SDA, LCD_SCL);
  lcd.init();
  lcd.backlight();

  SPI.begin(SD_SCK_PIN, SD_MISO_PIN, SD_MOSI_PIN, SD_CS_PIN);
  if (!SD.begin(SD_CS_PIN)) {
    lcd.setCursor(0, 0);
    lcd.print("SD Error!");
    return;
  }

  setupI2S();
  updateDisplay();
}

void loop() {
  handleButtons();
  handleTouchPads();
}

void setupI2S() {
  i2s_config_t i2s_config = {
    .mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_TX),
    .sample_rate = 44100,
    .bits_per_sample = I2S_BITS_PER_SAMPLE_16BIT,
    .channel_format = I2S_CHANNEL_FMT_RIGHT_LEFT,
    .communication_format = I2S_COMM_FORMAT_STAND_I2S,
    .intr_alloc_flags = ESP_INTR_FLAG_LEVEL1,
    .dma_buf_count = 8,
    .dma_buf_len = 64,
    .use_apll = false,
    .tx_desc_auto_clear = true
  };

  i2s_pin_config_t pin_config = {
    .bck_io_num = I2S_BCLK,
    .ws_io_num = I2S_LRC,
    .data_out_num = I2S_DIN,
    .data_in_num = I2S_PIN_NO_CHANGE
  };

  i2s_driver_install(I2S_NUM_0, &i2s_config, 0, NULL);
  i2s_set_pin(I2S_NUM_0, &pin_config);
}

void handleButtons() {
  static unsigned long lastDebounce = 0;
  if (millis() - lastDebounce < 200) return;

  if (digitalRead(NEXT_BTN_PIN) == LOW) {
    activePreset = (activePreset + 1) % totalPresets;
    updateDisplay();
    lastDebounce = millis();
  }

  if (digitalRead(PREV_BTN_PIN) == LOW) {
    activePreset = (activePreset - 1 + totalPresets) % totalPresets;
    updateDisplay();
    lastDebounce = millis();
  }

  if (digitalRead(REC_BTN_PIN) == LOW) {
    toggleRecording();
    lastDebounce = millis();
  }

  if (digitalRead(PLAY_BTN_PIN) == LOW) {
    playRecording();
    lastDebounce = millis();
  }
}

void handleTouchPads() {
  for (int i = 0; i < 7; i++) {
    int touchValue = touchRead(TOUCH_PINS[i]);
    if (touchValue < 30) {
      playSample(i + 1);
      delay(150);
    }
  }
}

void playSample(int sampleNumber) {
  String filePath = String(presetFolders[activePreset]) + "/" + String(sampleNumber) + ".wav";
  File audioFile = SD.open(filePath.c0_str());
  if (!audioFile) return;

  if (audioFile.seek(44)) {
    int volume = analogRead(POT_PIN);
    float volumeScale = (float)volume / 4095.0;

    uint8_t buffer[512];
    size_t bytesRead = 0;
    while (audioFile.available()) {
      bytesRead = audioFile.read(buffer, sizeof(buffer));
      
      for (int i = 0; i < bytesRead; i += 2) {
        int16_t sample = (buffer[i + 1] << 8) | buffer[i];
        sample = (int16_t)((float)sample * volumeScale);
        buffer[i] = sample & 0xFF;
        buffer[i + 1] = (sample >> 8) & 0xFF;
      }

      size_t bytesWritten = 0;
      i2s_write(I2S_NUM_0, buffer, bytesRead, &bytesWritten, portMAX_DELAY);
    }
  }
  audioFile.close();
}

void toggleRecording() {
  if (!isRecording) {
    if (SD.exists("/rec.wav")) {
      SD.remove("/rec.wav");
    }
    recordingFile = SD.open("/rec.wav", FILE_WRITE);
    isRecording = true;
    lcd.setCursor(0, 1);
    lcd.print("Rec: Active     ");
  } else {
    if (recordingFile) {
      recordingFile.close();
    }
    isRecording = false;
    updateDisplay();
  }
}

void playRecording() {
  File recFile = SD.open("/rec.wav", FILE_READ);
  if (!recFile) return;

  uint8_t buffer[512];
  size_t bytesRead = 0;
  while (recFile.available()) {
    bytesRead = recFile.read(buffer, sizeof(buffer));
    size_t bytesWritten = 0;
    i2s_write(I2S_NUM_0, buffer, bytesRead, &bytesWritten, portMAX_DELAY);
  }
  recFile.close();
}

void updateDisplay() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Preset:");
  lcd.setCursor(0, 1);
  lcd.print(presetFolders[activePreset]);
}
