const express = require('express');
const http = require('http');
const Database = require('better-sqlite3');
const path = require('path');
const app = express();
const port = 3000;

// een paar instellingen voor de server
var db = new Database('./database/database.db', { verbose: console.log });
app.use(express.static(path.join(__dirname, '/widget')));


// definieer startpunten voor de server
app.get('/', geefWidget);
app.get('/api/echo', echoRequest);
app.get('/api/set/nieuwerun', creeerNieuweRun);
app.get('/api/set/sensordata', setSensorData);
app.get('/api/get/sensordata', getSensorData);
app.get('/api/set/instellingen', setInstellingen);
app.get('/api/get/instellingen', getInstellingen);

// start de server
app.listen(port, serverIsGestart);

// ---------------------------------------------------------------------------

// wordt uitgevoerd als de server is opgestart
function serverIsGestart() {
  var url = process.env.GITPOD_WORKSPACE_URL;
  console.log(`De server is opgestart en is bereikbaar op ${url}:${port}`);
}


// stuurt het html-bestand van de widget
function geefWidget(request, response) {
  response.redirect('index.html');
}


// stuurt de variabelen uit het request
// terug naar de browser en in de console
function echoRequest(request, response) {
  response.status(200).send(request.query);
}


// maakt een nieuwe run aan in de database
// en geeft een oké terug
function creeerNieuweRun(request, response) {
  // insert een nieuwe regel in de tabel 'runs'
  // waarin we alleen de huidige tijd (timestamp) meegeven
  db.prepare("INSERT INTO runs (stamp) VALUES (CURRENT_TIMESTAMP)").run();
  response.status(200).send();
}


// geeft laatste sensordata van de run terug 
function getSensorData(request, response) {
  var huidigeRunID = geefHoogsteRunID();
  var stmt = db.prepare('SELECT aantalKnikkers FROM sensorData WHERE run = ? ORDER BY stamp DESC');
  var data = stmt.get(huidigeRunID);
  response.status(200).send(data);
}


// slaat doorgegeven data op in de database
function setSensorData(request, response) {
  var aantalNieuweKnikkers = request.query.knikkers;
  var huidigeRunID = geefHoogsteRunID();
  var SQL = `INSERT INTO sensorData (run, stamp, aantalKnikkers)
             VALUES (?, CURRENT_TIMESTAMP, ?)`
  db.prepare(SQL).run(huidigeRunID, aantalNieuweKnikkers);
  response.status(200).send();
}


// geeft de laatst ingevoerde instellingen terug
function getInstellingen(request, response) {
  // moet nog gemaakt worden
}


// slaat doorgegeven instellingen op in de database
function setInstellingen(request, response) {
  // moet nog gemaakt worden
}


// geeft de hoogste id uit de runs tabel
// dit is een hulpfunctie voor gebruik in andere queries
function geefHoogsteRunID() {
  var data = db.prepare("SELECT max(id) as id FROM runs").get();
  return data.id;
}