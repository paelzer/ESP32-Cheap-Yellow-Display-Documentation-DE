# Add-Ons

Hier ist eine Liste mit Hardware-Erweiterungen, mit denen der Funktionsumfang des CYD Funktionalität erweitert werden kann. 

## SD Card Breakout

Wenn die Pins der SD-Karte für etwas anderes verwendet werden sollen, lässt sich das am besten mit einem „SD-Karten-Breakout“ machen, das einfach in den SD-Kartensteckplatz eingesteckt wird und .  Dies ist besonders nützlich für SPI-Geräte.

## Pin-out of the Sniffer board

| Sniffer Board Label | ESP32 Pin | SPI Use   |
| ------------------- | --------- | --------- |
| DAT2                | -         | -         |
| CD                  | IO5       | CS        |
| CMD                 | IO23      | DI / MOSI |
| GND                 | GND       | -         |
| VCC                 | 3.3V      | -         |
| CLK                 | IO18      | SCLK      |
| DAT0                | IO19      | DO / MISO |
| DAT1                | -         | -         |

### Links

- [Micro SD Card Sniffer - Aliexpress\*](https://s.click.aliexpress.com/e/_Ddwcy9h)

## Nintendo Wii Nunchuck

A Nunchuck controller from a Nintendo Wii is a great input device for CYD projects as they are inexpensive and, since they use i2c for communication, they only require 2 GPIO pins to connect them up.

For these two pins you get:

- An analog stick
- 2 Buttons
- An accelerometer

### Hardware Required

#### Nunchuck controllers

Official Nintendo ones are generally better (maybe try second-hand options), but third-party ones also work fine.

- [Amazon.co.uk Search\*](https://amzn.to/3nQrXcE)
- [Amazon.com Search\*](https://amzn.to/3nRJTUd)
- [Aliexpress (Third Party)\*](https://s.click.aliexpress.com/e/_AaQbXh)

#### Nunchuck Adaptors

There are many different options available for these, even the cheap ones from Aliexpress work perfectly.

- [Aliexpress](https://s.click.aliexpress.com/e/_AEEtc3)
- [My Open source one from Oshpark](https://oshpark.com/shared_projects/RcIxSx2D)
- [Adafaruit](https://www.adafruit.com/product/4836)

### Wiring

The easiest way to wire this up is to use the wire that came with the CYD and the **CN1** JST connector (the one closest to the Micro SD card slot)

Connect the wire to your breakout board as follows:

| CYD CN1 | Adapter     | Note               |
| ------- | ----------- | ------------------ |
| GND     | - (AKA GND) | Black wire for me  |
| 3.3V    | + (AKA 3V)  | Red wire for me    |
| IO22    | d (AKA SDA) | Blue wire for me   |
| IO27    | c (AKA SCL) | Yellow wire for me |

Note: I have found pull-ups resistors are not required on SDA and SCL

### Example

Check out the [NunchuckTest](/Examples/InputTests/NunchuckTest) example for code how to use it.

## Speakers

A speaker can be attached to the display with a 1.25mm JST connector to the connector labeled "SPEAK" (or soldered)

Check out the [HelloRadio](/Examples/Basics/7-HelloRadio) example for the code on how to use it.

Most small 8 Ohm speakers should work. Maybe worth adding a 1.25mm JST connector to it to make it easy to add remove.

### Links

- [Speaker with 1.25mm JST connector (2pcs) - Aliexpress\*](https://s.click.aliexpress.com/e/_DBOJoh7) - Tested, works right out of the package.
- [2pin 1.25mm JST connectors - Aliexpress\*](https://s.click.aliexpress.com/e/_DlbPkWH) - Not purchased by me, but should work

\* = Affiliate Link - It doesn't cost you any extra but I receive a small portion of the sale.
