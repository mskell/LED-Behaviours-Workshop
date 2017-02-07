#include <Adafruit_NeoPixel.h>
#define PIN 5
Adafruit_NeoPixel strip = Adafruit_NeoPixel(52, PIN, NEO_GRB + NEO_KHZ800);

int potPin = A0;
int val = 0;
int colorVal = 0;
int reading = 0;
int prevVal = 0;

int history[] = {52, 48, 44, 40, 27, 31, 35, 39, 26, 22, 18, 14, 1, 5, 9, 13}; 
int age = 0;
int pixelIndex;

const int numReadings = 10;
int readings[numReadings];      // the readings from the analog input
int readIndex = 0;              // the index of the current reading
int total = 0;                  // the running total
int average = 0;                // the average


void setup() {
  //  Serial.begin(9600);
  strip.begin();
  strip.show();

    for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readings[thisReading] = 0;
  }
  

}



void loop() {
  // put your main code here, to run repeatedly:
  
  // subtract the last reading:
  total = total - readings[readIndex];
  // read from the sensor:
  readings[readIndex] = 900-analogRead(potPin);
  // add the reading to the total:
  total = total + readings[readIndex];
  // advance to the next position in the array:
  readIndex = readIndex + 1;

  // if we're at the end of the array...
  if (readIndex >= numReadings) {
    // ...wrap around to the beginning:
    readIndex = 0;
  }

  // calculate the average:
  average = total / numReadings;
  
  //reading = 900-analogRead(potPin);
//  Serial.println(reading);
  val = (average/1024.0) * 52;
  colorVal = (average/1024.0) * 255;
  
  // Neopixel LED number code
  strip.setBrightness(30);
  for ( age = 0; age < 16; age++) {
    pixelIndex = history[age]-1;
    if (age < val) {
      strip.setPixelColor(pixelIndex,160,160,255);
    } else {
      strip.setPixelColor(pixelIndex,0,0,0);
    }
  }
  strip.show();
}
