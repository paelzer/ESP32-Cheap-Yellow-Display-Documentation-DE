# Setup - und Konfigurationsoptionen

Auf dieser Seite geht's umn die Grundlagen zur Einrichtung des CYD

## Hardware Setup

Hier gibt es wirklich nicht kaum was einzurichten - schließt das CYD einfach über ein Micro-USB-Kabel an einen Computer an (ist sogar im Lieferumfang enthalten).

## Software Setup

Der Treiber muß für das Hochladen von Sketchen vorbereitet werden. Das gilt auch für webflashing Projekte. 

### Treiber


Das CYD verwendet den CH340 USB-zu-UART-Chip. Wenn der Treiber für diesen Chip noch nicht installiert ist, müsst Ihr das möglicherweise nachholen. Seht euch dazu einfach [Sparkfuns Installationsanweisungen](https://learn.sparkfun.com/tutorials/how-to-install-ch340-drivers/all) an

## Einrichten der Arduino IDE

Im Folgenden wird erklärt, wie man eigenen Code für das CYD schreibt. 

### Board Definition

Die Arduino IDE muß für die Nutzung des ESP32 eingerichtet werden. [Die Anweisungen dazu findet ihr hier](https://docs.espressif.com/projects/arduino-esp32/en/latest/installing.html).

Grundsätzlich sollte es mit jedem ESP32-Board aus dem Boardmenu funktionieren. Ich wähle hier jedoch für gewöhnlich das "ESP32 Dev Modul". Aber, wie gesagt, es spielt keine Rolle.

Sollten beim Hochladen eines Sketches Fehler auftreten, reduziert mal die Board-Upload-Geschwindigkeit auf `115200` und versucht es nochmal.

### Einrichten der Bibliothek


Das CYD ist zu einer Auswahl verschiedener Bibliotheken kompatibel, aber diejenige, auf die sich dieses Repo konzentriert, heißt [TFT_eSPI](https://github.com/Bodmer/TFT_eSPI). Sie ist eine recht weit verbreitete und sehr beliebte Bibliothek für die Arbeit mit Displays dieser Art und bietet schon sehr viele sehr gute Beispiele, was einem den Einstieg enorm erleichtert.

Sie kann einfach über den Bibliotheksmanager gefunden und installiert werden, indem man im entsprechenden Suchfeld einfach "TFT_eSPI" einträgt.

> Hinweis: Nach der Installation der Bibliothek muss die Datei [User_Setup.h](https://github.com/witnessmenow/ESP32-Cheap-Yellow-Display/blob/main/DisplayConfig/User_Setup.h) in den Bibliotheken-Ordner der Arduino IDE `libraries\TFT_eSPI` kopiert werden. Dadurch wird die "TFT_eSPI" Bibliothek für die Verwendung mit dem CYD eingerichtet.

### Beispiele

Schaut Euch einfach die Beispiele an, die ich [hier](https://github.com/witnessmenow/ESP32-Cheap-Yellow-Display/blob/main/Examples) bereitgestell habe, um ein paar Ideen und Inspirationen zu bekommen, was man mit dem CYD so anstellen kann. 
