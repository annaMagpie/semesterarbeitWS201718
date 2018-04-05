# semesterarbeitWS201718
Media center 

###################
 Vorbereitung:
###################

Dieses Projekt stellt eine Mediathek dar, in welcher verschiedene Filme gelistet sind. Diese Filme haben folgende Childelemente: Genre, Titel, Story, Regisseur, Erscheinungsjahr und Spielzeit. Diese Informationen sind in der XML Datei enthalten. Die TXT Datei habe ich mit Angaben über den Preis der verschiedenen Ausführungen (DVD oder Blu-ray) sowie der jeweiligen Anzahl ausgestattet. Durch die IDs können später im Programm die Preise beispielsweise zusammen gerechnet oder den Bestand von DVDs ermittelt werden. In einem realistischen Szenario könnte über das Programm evtl. sogar eine Wunschliste erstellt werden.


###################
 Durchführung:
###################
Zunächst habe ich die Parser für die xml und die txt Dateien eingefügt bzw. erstellt.
Diese Dateien werden sofort nach Ausführung des Programms gelesen und in die dafür vorgesehenen Objekte gespeichert. Nun kann der User eine der aufgelisteten Optionen 
wählen, indem er den entsprechenden Buchstaben / Befehl dafür eingibt.

________________________
-Text Datei ausgeben:

Es wird in die Library der Textdatei verwiesen, wo der Inhalt mithilfe der Druckfunktion ausgegeben wird.
________________________
-Neue Datei exportieren:

Wählt der User diese Option, wird er nach dem gewünschten Namen der Datei gefragt. Dieser wird zusammen mit dem Text-Objekt als Parameter an die Druckfunktion der xml Datei übergeben. Hier wird eine neue Datei mit dem Wunschnamen des Users erstellt und mit den zu Beginn gespeicherten Inhalten gefüllt. Dies geschieht solange, bis es keine Kind- bzw. Geschwisterelemente mehr gibt. Die neue Datei erscheint im build-Ordner. Nach dem Vorgang wird die Datei geschlossen.
________________________
-Suche: (NOCH AUSKOMMENTIERT, DA IN BEARBEITUNG)

Nachdem der User die Suche wählt, wird er aufgefordert die gesuchte Kategorie und danach den Inhalt als Suchbegriff einzugeben. Diese werden in Variablen gespeichert und sollen  als Parameter in die Druckunktion übergeben werden.
________________________

Nach jedem erfolgreichen Abschluss der gewählten Operation, wird der User gefragt, ob er in das Menü zurückkehren möchte. Mit der vorgegebenen Eingabe wird er dorthin zurückkehren. Mit einer abweichenden Eingabe wird das Programm beendet.

Innerhalb des Codes befinden sich ebenfalls Anmerkungen zu meinem Vorgehen.
________________________
- Inspiration und Referenzen:

Ofstream:
https://www.fbi.h-da.de/fileadmin/personal/b.reuschling/Datei-IO.pdf

While Loop:
https://www.youtube.com/watch?v=1XoBCmu57XQ

Parsing:
http://hki.uni-koeln.de/wintersemester-2017-2018/?lvid=162577

Außerdem:
Wolf, J.: Grundkurs C++. 3., aktualisierte und erweiterte Aufl. Bonn: Rheinwerk Verl. 2016.
Mueller, P./Jeff Cogswell. C++ für Dummies: Alles-in-einem-Band. 1. Aufl. Weinheim: Wiley-Vch Verl. 2016.
