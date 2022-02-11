/* Beschrijf de tabellen die je nodig hebt*/

CREATE TABLE runs (
  id INTEGER PRIMARY KEY AUTOINCREMENT,
  stamp DATETIME NOT NULL
);

CREATE TABLE sensorData (
  id INTEGER PRIMARY KEY AUTOINCREMENT,
  run INTEGER NOT NULL,
  stamp DATETIME NOT NULL,
  aantalKnikkers INTEGER
);

CREATE TABLE instellingen (
  id INTEGER PRIMARY KEY AUTOINCREMENT,
  run INTEGER NOT NULL,
  stamp DATETIME NOT NULL,
  wachttijdPoort INTEGER NOT NULL
);

CREATE TABLE teller (
  id INTEGER PRIMARY KEY AUTOINCREMENT,
  run INTEGER NOT NULL,
  stamp DATETIME NOT NULL,
  aantalKnikkers INTEGER
);

CREATE TABLE snelheidMeter (
  id INTEGER PRIMARY KEY AUTOINCREMENT,
  run INTEGER NOT NULL,
  stamp1 DATETIME NOT NULL,
  stamp2 DATETIME NOT NULL,
  snelheid INTEGER
);

CREATE TABLE sensorLED (
  id INTEGER PRIMARY KEY AUTOINCREMENT,
  aantalKnikkers INTEGER     -- het ledje brandt 
);

CREATE TABLE scherm (
  id INTEGER PRIMARY KEY AUTOINCREMENT,
  snelheid INTEGER     -- scherm laat snelheid zien
);

/* Indien je standaard wat gegevens in de database wilt,
   voeg hieronder dan INSERT regels to */
INSERT INTO runs (stamp) VALUES (CURRENT_TIMESTAMP);
INSERT INTO sensorData (run, stamp, aantalKnikkers) VALUES (1, CURRENT_TIMESTAMP, 3);
INSERT INTO instellingen (run, stamp, wachttijdPoort) VALUES (1, CURRENT_TIMESTAMP, 15);
INSERT INTO teller (run, stamp, aantalKnikkers) VALUES (1, CURRENT_TIMESTAMP, 3);
INSERT INTO snelheidMeter (run, stamp1, stamp2) VALUES (1, CURRENT_TIMESTAMP, CURRENT_TIMESTAMP, (stamp2 - stamp1 / afstand));
INSERT INTO sensorLED (aantalKnikkers) VALUES (3);
INSERT INTO scherm (aantalKnikkers) VALUES (2);