## This explanation is not yet done so the widget will probably not work for you without further code adjustments! Will be finished soon.

# Slider Widget Demo

![SliderDemo screenshot](https://github.com/paelzer/ESP32-Cheap-Yellow-Display-Documentation-DE/assets/16374477/2f9de09b-6127-4f73-bd65-67253e01c142)

To get this working I used "XPT2046_Calibrated_Touchscreen" library (https://github.com/basvijfwinkel/XPT2046_Calibrated_Touchscreen), which is a fork of the one of Paul Stoffregen (https://github.com/PaulStoffregen/XPT2046_Touchscreen). 

It has a calibration routine for the touch screen implemented which makes it easy to get the real pixel coordinates of the TFT it is attached to.

This repo is not available in the Arduino library so you need to download it via the Github link and add it with the "Add ZIP library" function.

The calibration sketch must be run first to get the calibration values for the TFT.

## This explanation is not yet done so the widget will probably not work for you without further code adjustments! Will be finished soon.
