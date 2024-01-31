# Pins

Auf dieser Seite geht es um die Pins des CYD.

## Welche Pins sind auf dem CYD verfügbar?

Es gibt 3 einfach zugängliche GPIO-Pins

|Pin|Location|Note|
|---|---|----|
|IO35|**P3** JST connector|Nur als Input Pin nutzbar, kein interner Pull-up Widerstand verfügbar|
|IO22|**P3** and **CN1** JST connector||
|IO27|**CN1** JST connector||

Sollten Euch diese 3 Pins nicht genügen, müsst Ihr weitere Pins von anderen Funktionen nehmen. Ein kleines Breakout Board für den SD-Kartenleser, wie er in den [Add-ons](/ADDONS.md) erwähnt wird, ist wahrscheinlich die einfachste Lösung.
Sollte dies immer noch nicht genügen, müsst ihr wohl etwas auslöten!

## Herausgeführte Pins

Es sind drei 4P 1.25mm JST Anschlüsse auf dem Board

### P3
|Pin|Use|Note|
|---|---|----|
|GND|||
|IO35||Nur als Input Pin nutzbar, kein interner Pull-up Widerstand verfügbar|
|IO22||Also on the **CN1** connector|
|IO21||Used for the TFT Backlight, so not really usable|

### CN1
Dieser Anschluss is ein guter Kandidat für I2C Geräte

|Pin|Use|Note|
|---|---|----|
|GND|||
|IO22||Also on **P3** connector|
|IO27|||
|3.3V|||

### P1
|Pin|Use|Note|
|---|---|----|
|VIN|||
|IO1(?)|TX|Eventuell als GPIO nutzbar?|
|IO3(?)|RX|Eventuell als GPIO nutzbar?|
|GND|||


## Buttons

Das CYD hat zwei Taster, reset und boot.

|Pin|Use|Note|
|---|---|----|
|IO0|BOOT|Kann als Input Pin verwendet werden|

## Speaker

Der Lautsprecheranschluss ist ein 2P 1.25mm JST Stecker, der mit dem Verstärker verbunden ist, also nicht als GPIO am Lautsprecheranschluss verwendbar.

|Pin|Use|Note|
|---|---|----|
|IO26|Connected to amp|`i2s_set_dac_mode(I2S_DAC_CHANNEL_LEFT_EN);`|

## RGB LED


Wenn Euer Projekt zusätzliche Pins benötigt, die sonstwo nicht verfügbar sind, ist dies ein guter Kandidat für ein Opfer.

Note: LEDs sind "active low", bedeutet HIGH == aus, LOW == an

|Pin|Use|Note|
|---|---|----|
|IO4|Red LED||
|IO16|Green LED||
|IO17|Blue LED||

## SD Card
Verwendet den VSPI
Die Pin Namen sind vordefiniert in SPI.h

|Pin|Use|Note|
|---|---|----|
|IO5|SS||
|IO18|SCK||
|IO19|MISO||
|IO23|MOSI||

## Touch Screen

|Pin|Use|Note|
|---|---|----|
|IO25|XPT2046_CLK||
|IO32|XPT2046_MOSI||
|IO33|XPT2046_CS||
|IO36|XPT2046_IRQ||
|IO39|XPT2046_MISO||

## LDR (Light Sensor)

|Pin|Use|Note|
|---|---|----|
|IO34|||

## Display
Verwendet den HSPI

|Pin|Use|Note|
|---|---|----|
|IO2|TFT_RS|AKA: TFT_DC|
|IO12|TFT_SDO|AKA: TFT_MISO|
|IO13|TFT_SDI|AKA: TFT_MOSI|
|IO14|TFT_SCK||
|IO15|TFT_CS||
|IO21|TFT_BL|Also on P3 connector, for some reason|

## Test points
|Pad|Use|Note|
|---|---|----|
|S1|GND|near USB-SERIAL|
|S2|3.3v|for ESP32|
|S3|5v|near USB-SERIAL|
|S4|GND|for ESP32|
|S5|3.3v|for TFT|
|JP0 (pad nearest USB socket)|5v|TFT LDO|
|JP0|3.3v|TFT LDO|
|JP3 (pad nearest USB socket)|5v|ESP32 LDO|
|JP3|3.3v|ESP32 LDO|
