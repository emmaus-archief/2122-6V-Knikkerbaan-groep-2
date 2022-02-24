# Verslag eindopdracht 6V
### gemaakt door Jimmy, Helke, Luna, Caitlin 

---

## Inleiding


## wat hebben we nodig?
  - Rad 
  - Trechter 
  - 2 leds
  - 5 sensoren
  - Scherm
  - Poortje
  - Ong 25 plankjes  

## Features
Beschrijf hier de eigenschappen van jullie knikkerbaan (gebruik gerust plaatjes) kijk in map fotos naar KnikkerBaan.png . De eerste paar zijn voorgegeven:

### feature 1: Opvangen van knikkers (+teller)
  De knikkerbaan kan knikkers bovenin correct opvangen. De binnenkomende knikkers worden geteld d.m.v. de teller en een poortje bepaalt of knikkers doorrollen of worden tegengehouden.

### feature 2: Doorgeven van gegevens aan server
  De knikkerbaan zendt de hoeveelheid getelde knikkers naar een server die de gegevens opslaat in een database. Deze server kan per 'run' (d.w.z. een nieuwe keer aangaan) gegevens bijhouden.

### feature 3: Widget wisselt info uit met knikkerbaan
  In de browser kan met een URL een widget worden geladen. Deze geeft de knikkerbaan schematisch weer in een frame van 800x400px. De getelde knikkers en duur dat de poort openstaat worden hierin getoond. De duur dat de poort openstaat kan hierin worden veranderd. De knikkerbaan kan deze wachttijd van de server ontvangen en zijn werking erop aanpassen.

### feature 4: Sensor LED's
  Er is per 'weg' die de knikker kan nemen een sensor die een LED kan laten knipperen wanneer er een knikker langs de sensor komt. 

### feature 5: Trechter
  In het linker pad van onze knikkerbaan bevindt zich een trechter met houten stokjes. Het doel van deze trechter is om de afgelegde weg van de knikker te veranderen en daarmee dus ook de snelheid. 

### feature 6: Wiel
  In het rechter pad is een wiel die op een random snelheid ronddraait d.m.v. een servomotor en daardoor, net als de trechter, de snelheid van de knikker verandert. 

### feature 7: Snelheid van knikkers wordt opgenomen
  Er wordt van de knikkers die het rechter pad nemen de snelheid opgenomen. Dit doen wij door eerst de afgelegde afstand te bepalen en daarna vast te leggen hoe lang de knikker over die weg deed, met deze twee gegevens kunnen wij dan de snelheid berekenen. De tijd die de knikker over het pad doet kunnen wij opmeten aan de hand van de 'snelheidssensor' die na het wiel zit (groene lijn op onze tekening).

### feature 8: Info wordt op scherm weergegeven
  Op het LCD-scherm wordt de gemeten snelheid weergegeven. 

### feature 9: Sensor poortje
  Onder aan de trechter zit een sensor die dus weergeeft wanneer een knikker er langs komt. Wanneer er dan een knikker de sensor passeert opent dit het poortje (blauwe lijn genaamd 'sensor poortje' op onze tekening). 

### feature 10: poortje
  Na het wiel en de snelheidsmeter zit een poortje die door een servomotor bestuurd wordt (roze/magenta lijn genaamd 'poortje' op onze tekening). Dit poortje gaat open wanneer er door de sensor onder aan de trechter een knikker wordt waargenomen. 



## Evaluaties van scrumplanningen:

### week 43
  - Opmaak ontwerp en ideeen.
  - visual knikkerbaan (Helke)

### week 44
  - Behandelen uitlegfilmpjes op de ELO. 

### week 45
  TOETSWEEK

### week 46
  Restweek van de toetsweek.

### week 47
  - Code sensor opstellen (jimmy en luna)
  - de uitlegfilmpjes behandelen (iedereen)
  - Code uit filmpjes overgenomen in code (Jimmy)
  - Code opzetten server (Helke en Caitlin), als dit voldaan is beginnen we met SQL.

### week 48 
  - afspraak ht voor bouw knikkerbaan (Helke en Caitlin)
  - Code opzetten server (Helke en Caitlin), als dit voldaan is beginnen we met SQL.

### week 49 
  Helke ziek
  de rest?

### week 50
  Helke ziek
  de rest?

### week 51
  LOCKDOWN

### week 52 
  VAKANTIE

### week 1
  VAKANTIE

### week 2 
  Code voor rad en poortje toegevoegd (jimmy)

### week 3
  TOETSWEEK

### week 4
  TOETSWEEK

### week 5 
  - onderdelen op het bord zetten (iedereen)
  - aan code werken Jimmy(voortgang code & poortje) en Luna(LED's))
  - veranderingen aan code poortje(jimmy)

### week 6 
  - aan code werken (Jimmy(servo's en ir sensors)) en Luna(LCD-scherm))
  - code voor rad en poort afgemaakt(jimmy)
  - niet oop based code gemaakt voor IR sensors(jimmy)
  - bord schilderen en extra's (Helke)
  - verslag updaten (Helke)
  - begin widget (Helke)
  - widget technisch (Helke en Jimmy)

### week 7 
  - extras op het bord en finishing touches (Helke)
  - functionele onderdelen op het bord (Helke)
  - aan code werken (Luna (LCD scherm))
  - widget basis layout knikkerbord (Helke)
  - LED code werkend gemaakt(jimmy)
  - IR sensors voor poort, LEDS en snelheid afgemaakt en werkend(jimmy)
  - code voor snelheidsberekening afgemaakt en werkend (jimmy)
  - aan de server verbonden en teller.ino en knikkerpoort.ino werkend gemaakt (jimmy)
  - algemene code cleaning(pins, ints, blanks) (jimmy)
  - begonnen data toevoegen voor widget (jimmy)
  - begonnen integratie testcode met echte code(jimmy)

### week 8 
  - knop op widget om poort te openen (Helke)
  - laatste wijzigingen en updates aan bord (Helke)
  - LED's verlengen voor het boord (Helke)
  - code integreren en gitpod cleanen (Jimmy)
  - aan verslag (Helke, Jimmy en Luna)
  - aan code (Luna(LCD)
  - Arduino delen op het bord (Helke en Jimmy)
  - arduino data verstuurbaar gemaakt naar server-app.js (Jimmy)
  - gegenereerde data op server opgeslagen in SQL-database overbodige code SQL verwijderd (Jimmy)
  - comments bij code (Jimmy)
  - info van widget via server naar arduino van poortje (Helke)
  - widget versturen naar server (Jimmy en Helke)
  - classes kloppend maken bij widget (Caitlin)



## Technische verantwoording

De Arduino werkt op de volgende manier:

De knikkerbaan en de widget wisselen de volgende data met elkaar uit:
De knikkerbaan stuurt naar de widget hoeveel knikkers deze telt d.m.v. de sensors. De widget stuurt naar de knikkerbaan een opdracht om het poortje te openen. 
- 

We hebben dat op deze manier genormaliseerd in een database opgenomen (neem een strokendiagram op). De reden dat we voor ... kiezen is...

Uitdagingen die we tegenkwamen:


## Reflectie op opdracht
#### Helke
  *(50 - 100 woorden. Geef o.a. wat je tijdens deze opdracht beter onder de knie hebt gekregen en welk leerpunt je voor jezelf meeneemt)*

#### Jimmy


#### Luna


#### Caitlin


---


## Slot
