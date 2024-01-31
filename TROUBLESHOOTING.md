# Fehlersuche

## Stellt zunächst sicher, dass es sich in Eurem Fall auch tatsächlich um ein "CYD" handelt!

Sollten Probleme auftreten, ist dies ein guter erster Prüfschritt! 

Die Beispiele und Informationen in diesem Repo beziehen sich nur auf das ESP32-2432S028 Display. Die Modellnummer befindet sich auf der Rückseite des Displays in goldener Schrift neben dem Lautsprecheranschluss.

## Das Display schaltet nicht ein

Wenn Ihr Probleme habt, das Display in Betrieb zu nehmen, würde ich als erstes mit dem [Webflashing eines bestehenden Projekts](/PROJECTS.md#projects-1) versuchen. Bei diesen Projekten handelt es sich um als funktionierenden bekannten Code. Wenn das Display damit funktioniert, deutet das auf ein Problem mit Eurem Code hin, nicht auf ein Hardwareproblem.

### Wenn das Webflash-Projekt etwas auf dem Bildschirm anzeigt

- Stellt sicher, dass Sie die Datei [User_Setup.h](https://github.com/witnessmenow/ESP32-Cheap-Yellow-Display/blob/main/DisplayConfig/User_Setup.h) an der richtigen Stelle platziert habt [wie hier beschrieben](/SETUP.md#library-configuration)
- Pin 21 ist der Pin für die Hintergrundbeleuchtung, stellen Sie sicher, dass Sie ihn nicht für etwas anderes in Ihrem Sketch verwenden.

### Das Webflash-Projekt wird nicht auf dem Bildschirm angezeigt.

- Stellen Sie sicher, dass Sie Pin 21 nicht mit irgendetwas verbinden. Er ist auf dem mit `P3` gekennzeichneten Anschluss herausgeführt.
- Versucht es mit einen anderen USB-Port und/oder einem anderem USB-Kabel
- Wenn das alles nicht funktioniert hat, könnte Euer CYD defekt sein. Kontaktiert den Verkäufer.

## Das Display flackert

- Versucht es mit einen anderen USB-Port und/oder einem anderem USB-Kabel
- Führen Sie die Schritte [Display schaltet sich nicht ein](#display-is-not-turning-on) durch
- Wenn das alles nicht funktioniert hat, könnte Euer CYD defekt sein. Kontaktiert den Verkäufer.
