// Button widget demo, requires SPI display with touch screen

// Requires widget library here:
// https://github.com/Bodmer/TFT_eWidget

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

#include "Free_Fonts.h"   // Include the header file attached to this sketch
#include <TFT_eSPI.h>     // Hardware-specific library
#include <TFT_eWidget.h>  // Widget library
#include <XPT2046_Touchscreen.h>  // https://github.com/basvijfwinkel/XPT2046_Calibrated_Touchscreen
XPT2046_Touchscreen ts(XPT2046_CS, XPT2046_IRQ);

SPIClass mySpi = SPIClass(VSPI);
TFT_eSPI tft = TFT_eSPI();  // Invoke custom library

ButtonWidget btnL = ButtonWidget(&tft);
ButtonWidget btnR = ButtonWidget(&tft);

#define BUTTON_W 100
#define BUTTON_H 50

// Create an array of button instances to use in for() loops
// This is more useful where large numbers of buttons are employed
ButtonWidget* btn[] = { &btnL, &btnR };
;
uint8_t buttonCount = sizeof(btn) / sizeof(btn[0]);

void btnL_pressAction(void) {
  if (btnL.justPressed()) {
    Serial.println("Left button just pressed");
    btnL.drawSmoothButton(true);
  }
}

void btnL_releaseAction(void) {
  static uint32_t waitTime = 1000;
  if (btnL.justReleased()) {
    Serial.println("Left button just released");
    btnL.drawSmoothButton(false);
    btnL.setReleaseTime(millis());
    waitTime = 10000;
  } else {
    if (millis() - btnL.getReleaseTime() >= waitTime) {
      waitTime = 1000;
      btnL.setReleaseTime(millis());
      btnL.drawSmoothButton(!btnL.getState());
    }
  }
}

void btnR_pressAction(void) {
  if (btnR.justPressed()) {
    btnR.drawSmoothButton(!btnR.getState(), 3, TFT_BLACK, btnR.getState() ? "OFF" : "ON");
    Serial.print("Button toggled: ");
    if (btnR.getState()) Serial.println("ON");
    else Serial.println("OFF");
    btnR.setPressTime(millis());
  }

  // if button pressed for more than 1 sec...
  if (millis() - btnR.getPressTime() >= 1000) {
    Serial.println("Stop pressing my buttton.......");
  } else Serial.println("Right button is being pressed");
}

void btnR_releaseAction(void) {
  // Not action
}

void initButtons() {
  uint16_t x = (tft.width() - BUTTON_W) / 2;
  uint16_t y = tft.height() / 2 - BUTTON_H - 10;
  btnL.initButtonUL(x, y, BUTTON_W, BUTTON_H, TFT_WHITE, TFT_RED, TFT_BLACK, "Button", 1);
  btnL.setPressAction(btnL_pressAction);
  btnL.setReleaseAction(btnL_releaseAction);
  btnL.drawSmoothButton(false, 3, TFT_BLACK);  // 3 is outline width, TFT_BLACK is the surrounding background colour for anti-aliasing

  y = tft.height() / 2 + 10;
  btnR.initButtonUL(x, y, BUTTON_W, BUTTON_H, TFT_WHITE, TFT_BLACK, TFT_GREEN, "OFF", 1);
  btnR.setPressAction(btnR_pressAction);
  //btnR.setReleaseAction(btnR_releaseAction);
  btnR.drawSmoothButton(false, 3, TFT_BLACK);  // 3 is outline width, TFT_BLACK is the surrounding background colour for anti-aliasing
}

void setup() {
  Serial.begin(115200);
  ts.setCalibration(210, 3626, 344, 3835, 320, 240, 0);
  mySpi.begin(XPT2046_CLK, XPT2046_MISO, XPT2046_MOSI, XPT2046_CS);
  ts.begin(mySpi);
  ts.setRotation(0);
  tft.begin();
  tft.setRotation(0);
  tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF18);

  initButtons();
}

void loop() {
  static uint32_t scanTime = millis();
  //uint16_t t_x = 9999, t_y = 9999; // To store the touch coordinates

  // Scan keys every 50ms at most
  if (millis() - scanTime >= 50) {
    // Pressed will be set true if there is a valid touch on the screen
    bool pressed = (ts.tirqTouched() && ts.touched());
    TS_Point p = ts.getPoint(false);
    int X_Coord = p.calx;
    int Y_Coord = p.caly;
    scanTime = millis();
    for (uint8_t b = 0; b < buttonCount; b++) {
      if (pressed) {
        if (btn[b]->contains(X_Coord, Y_Coord)) {
          btn[b]->press(true);
          btn[b]->pressAction();
        }
      } else {
        btn[b]->press(false);
        btn[b]->releaseAction();
      }
    }
  }
}
