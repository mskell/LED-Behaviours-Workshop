#include <LEDFader.h>
#define LED_NUM 2

// 2 leds
LEDFader leds[LED_NUM] = {
  LEDFader(10),
  LEDFader(11),
};

void setup() {
}

void loop() {

  // Update all LEDs and start new fades if any are done
  for (byte i = 0; i < LED_NUM; i++) {
    LEDFader *led = &leds[i];
    led->update();

    // Set new fade
    if (led->is_fading() == false) {
      int duration = random(1000, 3000); // between 1 - 3 seconds

      // Up
      if (led->get_value() == 0) {
        byte color = random(100, 255);
        led->fade(color, duration);
      }
      // Down
      else {
        led->fade(0, duration);
      }
    }
  }
}
