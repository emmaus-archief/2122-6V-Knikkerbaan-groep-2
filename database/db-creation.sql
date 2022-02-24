/* Beschrijf de tabellen die je nodig hebt*/

CREATE TABLE runs (
  id INTEGER PRIMARY KEY AUTOINCREMENT,
  stamp DATETIME NOT NULL
);

CREATE TABLE sensorData (
  id INTEGER PRIMARY KEY AUTOINCREMENT,
  run INTEGER NOT NULL,
  stamp DATETIME NOT NULL,
  aantalKnikkers INTEGER,
  knikkerSpeed INTEGER,
  portStatus INTEGER,
  radSpeed INTEGER
);

CREATE TABLE instellingen (
  id INTEGER PRIMARY KEY AUTOINCREMENT,
  run INTEGER NOT NULL,
  stamp DATETIME NOT NULL,
  wachttijdPoort INTEGER NOT NULL,
  radBeginsnelheid INTEGER
);

/* Indien je standaard wat gegevens in de database wilt,
   voeg hieronder dan INSERT regels to */
INSERT INTO runs (stamp) VALUES (CURRENT_TIMESTAMP);
INSERT INTO sensorData (run, stamp, aantalKnikkers, knikkerSpeed, portStatus, radSpeed) VALUES (1, CURRENT_TIMESTAMP, 3, 5, 1, 20);
INSERT INTO instellingen (run, stamp, wachttijdPoort, radBeginsnelheid) VALUES (1, CURRENT_TIMESTAMP, 15, 80);
