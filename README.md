# ESP32-Cheap-Yellow-Display

Es gibt einen ESP32 Microcontroller mit einem eingebauten 2,8" 320x240 LCD mit Touchscreen und der Bezeichnung "ESP32-2432S028R". Da dies ein doch recht umständlicher Name ist, schlage ich vor,es einfach in "Cheap Yellow Display" oder kurz CYD umzubenennen. Dieses Display kostet nur etwa $15 und ist daher meiner Meinung nach sehr preiswert.

![image](https://github.com/witnessmenow/ESP32-Cheap-Yellow-Display/assets/1562562/76c3d481-2523-4b6f-881c-2e29f9368cd0)

## Austattung

Das CYD verfügt über die folgende technische Ausstattung:

- ESP32 (mit Wifi and Bluetooth)
- 320 x 240 LCD Display (2.8 Zoll)
- Touch Screen (Resistive)
- USB für Spannungsversorgung und Programmierung
- SD Card Slot, LED und einige Weitere herausgeführte herausgeführte pins

## Für wen ist das CYD interessant?

Ich halte es für die folgenden Personengruppen für interessant:

- **Leute, die gerade erst begonnen haben, mit Hardware zu arbeiten/experimentieren** - da alles bereits angeschlossen ist, sind keine Lötarbeiten oder zusätzliche Komponenten erforderlich
- **Menschen, die zwar mit der Arbeit mit Hardware vertraut, aber faul sind** - (so wie ich). Manchmal möchte man einfach ein mal ein Projekt umsetzen, ohne zuerst noch Hardware zusammenbauen zu müssen oder Lötarbeiten ausführen.
- **Menschen, die nicht unbedingt darauf abzielen, etwas zu lernen, sondern einfach nur ein paar coole Sachen bauen wollen**
- Dazu später mehr.

## Wozu diese Webseite?

Es handelt sich also um eine recht nettes Stück Hardware zu einem günstigen Preis, aber die Softwareanleitungen bzw. der Support dazu sind recht dürftig. Nur ein einfacher Link zu einer Zip-Datei auf einer irgendeiner Website.

Vor ein paar Jahren habe ich das [ESP32 Trinity](https://github.com/witnessmenow/ESP32-Trinity), veröffentlicht, ein Open Source ESP32 Board zur Steuerung von Matrix-Panels. Ich denke, der Hauptnutzen, den die Leute aus meiner Arbeit mit dem Trinty ziehen, ist nicht die Hardware, sondern die Dokumentation, der Beispielcode und die fertig entwickelten Projekte.

Heutzutage stelle ich keine Hardware-Produkte mehr her, aber ich glaube, es wäre interessant, wenn wir die gleiche Art von Community rund um dieses Display aufbauen könnten, in der die Leute Beispiele und Projekte, die speziell für dieses Display erstellt wurden, austauschen können.

## Wo kann man es kaufen?

Kauft es einfach dort, wo Ihr es am günstigsten findet:

- [Aliexpress\*](https://s.click.aliexpress.com/e/_DkSpIjB)
- [Aliexpress\*](https://s.click.aliexpress.com/e/_DkcmuCh)
- [Aliexpress](https://www.aliexpress.com/item/1005004502250619.html)
- [Makerfabs](https://www.makerfabs.com/sunton-esp32-2-8-inch-tft-with-touch.html) - Scheint bereits mit einer 16GB SD card ausgelieftert zu werden. Makerfabs führt auch mein [ESP32 Trinity](https://github.com/witnessmenow/ESP32-Trinity)
- (HINWEIS: in der EU fallen Importgebühren an)

\* = Affiliate Link

## Erste Schritte mit dem CYD

Einzelheiten zu den ersten Schritten mit dem CYD findet Ihr auf der Seite [Setup und Configuration](/SETUP.md).

## Code Beispiele

### Die Basics

Eine Sammlung von Beispielen, die zeigen, wie die verschiedenen Funktionen des CYD genutzt werden können, ist ein guter Ausgangspunkt für den Einstieg. [Schaut's Euch hier an.](https://github.com/witnessmenow/ESP32-Cheap-Yellow-Display/blob/main/Examples/Basics)

### Alternative Display Bibliotheken

Die einfachen Beispiele basieren zwar auf der TFT_eSPI Display-Bibliothek, aber das CYD funktioniert trotzdem auch mit anderen Display-Bibliotheken. Hier findet Ihr einige Beispielcodes, falls Ihr es vorziehen solltet, eine alternative Arduino-Bibliothek zu verwenden, um loszulegen. [Findet ihr hier.](https://github.com/witnessmenow/ESP32-Cheap-Yellow-Display/blob/main/Examples/AlternativeLibraries)

### ESPHome

Ein paar Beispiele für die Verwendung des CYD in ESPHome [findet ihr hier.](/Examples/ESPHome)

## Weitere Infos und Links

### Discord

Nehmt am Info-Austausch zum CYD in [meinem Discord-Kanal teil](https://discord.gg/nnezpvq)

### 3D - Druck

Einige Beispiele für 3D-gedruckte Ständer und Gehäuse [könnt ihr euch hier ansehen.](/3dModels)

### Pin Infos

[Hier findet ihr](/PINS.md) Infos zu den Pins des CYDs. Sowohl über jene, die bereits für die grundsätzlichen Funktionen des CYD belegt sind, als auch über freie Pins, die für eigene Zwecke genutzt werden können.

### Erweiterungen

[Diese Seite](/ADDONS.md) enthält zusätzliche Hardware Vorschläge, mit denen die Funktionalität des CYDs noch etwas erweitert werden kann.

### Tipps zur Fehlerbehebung

[Hier](/TROUBLESHOOTING.md) findet ihr hilfreiche Vorschläge um Probleme zu lösen, denen Ihr beim arbeiten mit dem CYD evtentuell begegnet.

### Hardware Mods

[Diese Seite](/Mods/README.md) beinhaltet Informationen über Hardware-Modifikationen, die am CYD vorgenommen werden können, um einige seiner Funktionen zu verbessern oder zu verändern.

### Medien and Video Erwähnungen

[Diese Seite](https://github.com/witnessmenow/ESP32-Cheap-Yellow-Display/blob/main/Mods/README.md) listet auf, wann das CYD-Projekt irgendwo erwähnt wurde!

## Lizens Information

Dieses Projekt steht unter der MIT-Lizenz gemäß der [Lizenzdatei](https://github.com/witnessmenow/ESP32-Cheap-Yellow-Display/blob/main/LICENSE)

Die einzige Ausnahme ist der Ordner [OriginalDocumentation](https://github.com/witnessmenow/ESP32-Cheap-Yellow-Display/blob/main/OriginalDocumentation), für den ich keine Lizenz habe.

## Weitere Sprachen

Einige Mitglieder der Community haben Teile der hier verfügbaren Informationen in andere Sprachen portiert!

Bitte beachten: Ich kann keine Garantie für die Richtigkeit der Übersetzung, die Aktualität oder den Inhalt im Allgemeinen übernehmen.

- [French / Française](https://github.com/usini/ESP32-Cheap-Yellow-Display-Documentation-FR)
- [German / Deutsch](https://github.com/paelzer/ESP32-Cheap-Yellow-Display-Documentation-DE)

Wenn Ihr eine Übersetzung beisteuern möchtet, benennt das Repo bitte mit dem Namen der Sprache oder dem Code im Repo-Namen und verlinkt es dann hier.

## Unterstützt mich in dem, was ich tue!

[Wenn Euch meine Arbeit gefällt, zieht bitte in Erwägung, ein Github-Sponsor zu werden](https://github.com/sponsors/witnessmenow/)
