// Slider widget demo, requires display with touch screen

// Requires widget library here:
// https://github.com/Bodmer/TFT_eWidget

#include <TFT_eSPI.h>
#include <SPI.h>
#include "FS.h"
#include <XPT2046_Touchscreen.h>  // https://github.com/basvijfwinkel/XPT2046_Calibrated_Touchscreen
#include "Free_Fonts.h"           // Include the header file attached to this sketch
#include <TFT_eWidget.h>          // Widget library

// ----------------------------
// Touch Screen pins
// ----------------------------

// The CYD touch uses some non default
// SPI pins

#define XPT2046_IRQ 36
#define XPT2046_MOSI 32
#define XPT2046_MISO 39
#define XPT2046_CLK 25
#define XPT2046_CS 33

// ----------------------------

SPIClass mySpi = SPIClass(VSPI);
TFT_eSPI tft = TFT_eSPI();

XPT2046_Touchscreen ts(XPT2046_CS, XPT2046_IRQ);

TFT_eSprite knob = TFT_eSprite(&tft);  // Sprite for the slide knob

SliderWidget s1 = SliderWidget(&tft, &knob);  // Slider 1 widget
SliderWidget s2 = SliderWidget(&tft, &knob);  // Slider 2 widget


void setup() {
  Serial.begin(115200);

  // get these values from https://github.com/basvijfwinkel/XPT2046_Calibrated_Touchscreen/blob/main/examples/TouchCalibrate/TouchCalibrate.ino
  ts.setCalibration(210, 3626, 344, 3835, 320, 240, 0);
  
  mySpi.begin(XPT2046_CLK, XPT2046_MISO, XPT2046_MOSI, XPT2046_CS);
  ts.begin(mySpi);
  ts.setRotation(0);
  tft.begin();
  tft.setRotation(0);
  tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF18);

  // Create a parameter set for the slider
  slider_t param;

  // Slider slot parameters
  param.slotWidth = 9;            // Note: ends of slot will be rounded and anti-aliased
  param.slotLength = 200;         // Length includes rounded ends
  param.slotColor = TFT_BLUE;     // Slot colour
  param.slotBgColor = TFT_BLACK;  // Slot background colour for anti-aliasing
  param.orientation = H_SLIDER;   // sets it "true" for horizontal

  // Slider control knob parameters (smooth rounded rectangle)
  param.knobWidth = 15;           // Always along x axis
  param.knobHeight = 25;          // Always along y axis
  param.knobRadius = 5;           // Corner radius
  param.knobColor = TFT_WHITE;    // Anti-aliased with slot backgound colour
  param.knobLineColor = TFT_RED;  // Colour of marker line (set to same as knobColor for no line)

  // Slider range and movement speed
  param.sliderLT = 0;        // Left side for horizontal, top for vertical slider
  param.sliderRB = 100;      // Right side for horizontal, bottom for vertical slider
  param.startPosition = 50;  // Start position for control knob
  param.sliderDelay = 0;     // Microseconds per pixel movement delay (0 = no delay)

  // Create slider using parameters and plot at 0,0
  s1.drawSlider(0, 0, param);

  // Show bounding box (1 pixel outside slider working area)
  int16_t x, y;                            // x and y can be negative
  uint16_t w, h;                           // Width and height
  s1.getBoundingRect(&x, &y, &w, &h);      // Update x,y,w,h with bounding box
  tft.drawRect(x, y, w, h, TFT_DARKGREY);  // Draw rectangle outline
                                           /*
  // Alternative discrete fns to create/modify same slider - but fn sequence is important...
  s1.createSlider(9, 200, TFT_BLUE, TFT_BLACK, H_SLIDER);
  s1.createKnob(15, 25, 5, TFT_WHITE, TFT_RED);
  s1.setSliderScale(0, 100);
  s1.drawSlider(0, 0);
*/
  delay(1000);
  s1.setSliderPosition(50);
  delay(1000);
  s1.setSliderPosition(100);

  // Update any parameters that are different for slider 2
  param.slotWidth = 4;
  param.orientation = V_SLIDER;  // sets it "false" for vertical

  param.knobWidth = 19;
  param.knobHeight = 19;
  param.knobRadius = 19 / 2;  // Half w and h so creates a circle

  param.sliderLT = 200;      // Top for vertical slider
  param.sliderRB = 0;        // Bottom for vertical slider
  param.sliderDelay = 2000;  // 2ms per pixel movement delay (movement is blocking until complete)

  s2.drawSlider(0, 50, param);

  s2.getBoundingRect(&x, &y, &w, &h);
  tft.drawRect(x, y, w, h, TFT_DARKGREY);
  /*
  // Alternative discrete fns to create/modify same slider - but fn sequence is important...
  s2.createSlider(4, 200, TFT_BLUE, TFT_BLACK, V_SLIDER);
  s2.createKnob(19, 19, 9, TFT_WHITE, TFT_RED);
  s2.setSliderScale(200, 0, 2000);
  s2.drawSlider(0, 50);
*/
  // Move slider under software control
  delay(1000);
  s2.setSliderPosition(50);
  delay(1000);
  s2.setSliderPosition(100);
}

void loop() {
  static uint32_t scanTime = millis();
  //uint16_t t_x = 9999, t_y = 9999;  // To store the touch coordinates

  // Scan for touch every 50ms
  if (millis() - scanTime >= 20) {
    // Pressed will be set true if there is a valid touch on the screen
    if (ts.tirqTouched() && ts.touched()) {
      TS_Point p = ts.getPoint(false);
      int X_Coord = p.calx;
      int Y_Coord = p.caly;
      if (s1.checkTouch(X_Coord, Y_Coord)) {
        Serial.print("Slider 1 = ");
        Serial.println(s1.getSliderPosition());
      }
      if (s2.checkTouch(X_Coord, Y_Coord)) {
        Serial.print("Slider 2 = ");
        Serial.println(s2.getSliderPosition());
      }
    }
    scanTime = millis();
  }
}
