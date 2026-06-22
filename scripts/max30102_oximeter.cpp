#include <Wire.h>
#include "MAX30105.h"

MAX30105 sensor;

void setup() {
  Serial.begin(115200);
  Wire.begin();

  if (!sensor.begin(Wire, I2C_SPEED_STANDARD)) {
    // to make sure the fucking led works
    pinMode(LED_BUILTIN, OUTPUT);
    while (1) {
      digitalWrite(LED_BUILTIN, HIGH);
      delay(200);
      digitalWrite(LED_BUILTIN, LOW);
      delay(200);
    }
  }

  byte ledBrightness = 0xFF;  // ledddddddd fuck you
  byte sampleAverage = 4;
  byte ledMode = 2;           // Red + IR
  int sampleRate = 100;
  int pulseWidth = 411;
  int adcRange = 16384;

  sensor.setup(
    ledBrightness,
    sampleAverage,
    ledMode,
    sampleRate,
    pulseWidth,
    adcRange
  );

  sensor.setPulseAmplitudeRed(0xFF);
  sensor.setPulseAmplitudeIR(0xFF);
  sensor.setPulseAmplitudeGreen(0);

  delay(1000);
}

void loop() {
  long ir = sensor.getIR();
  long red = sensor.getRed();

  // Serial Plotter-compatible format for Arduino 
  Serial.print("IR:");
  Serial.print(ir);
  Serial.print("\t");
  Serial.print("RED:");
  Serial.println(red);

  delay(20);
}