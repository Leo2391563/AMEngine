#include <FastLED.h>

void start(byte _data = 3, byte _leds = 256, byte _bright = 32)
{
    CRGB leds[_leds];
    FastLED.addLeds<NEOPIXEL, _data>(leds, _leds);
    FastLED.setBrightness(_bright);
    FastLED.clear();
    light(0, 0, CRGB::Blue, 1);
    light(0, 1, CRGB::Green, 1);
    light(1, 0, CRGB::Red, 1);
    FastLED.show();
}
void light(byte x, byte y, CRGB Color, bool shower) {
    byte index = y % 2 == 1 ? y * width + (width - 1 - x) : y * width + x;
    leds[index] = Color;
    if (shower) FastLED.show();
}

void rectangle(byte x1, byte y1, byte x2, byte y2, CRGB Color) {
    for (byte x = x1; x <= x2; x++) for (byte y = y1; y <= y2; y++) light(x, y, Color, false);
    FastLED.show();
}

void line(int x1, int y1, int x2, int y2, CRGB color)
{
    int dx = x2 - x1;
    int dy = y2 - y1;
    float ky = (float)(y2 - y1) / (x2 - x1);
    if (abs(dx) >= abs(dy))
    {
        int yn;
        for (int x = x1; x != x2; x += dx / abs(dx))
        {
            yn = y2 + abs(x * dy / dx);
            light(x, yn, color, 1);
            Serial.println(x);
            Serial.println(yn);
        }
        light(x2, y2 + x2 * dy / dx, color, 1);
    }
}

void loop() {}
