
// globale variabelen
var aantalKnikkersBoven = 0;    // aantal knikkers dat bovenin is binnengekomen
var wachttijd = 15;             // wachttijd voor het poortje in seconden
const UPDATE_INTERVAL = 5000;   // tijd in milliseconden tussen het door widget opvragen van gegevens
var teller;
var wachtijdInput;
var sensor;
var rad;
var scherm;
var led;
var poortje;
var snelheidsmeter;

/**
 * setup
 * de code in deze functie wordt eenmaal uitgevoerd,
 * als p5js wordt gestart
 */
function setup() {
  // Maak het canvas van je widget
  createCanvas(300, 600);

  teller = new Teller (150, 50);

  /*
  poortje = new Poortje (100, 50);
  rad = new Rad (200,200);
  led = new Led (10,10); 
  led2 = new Led2 (10,10);
  scherm = new Scherm (150, 100);
  snelheidsmeter = new Snelheidsmeter (100, 50);
  */


  // om de ... milliseconden wordt 'vraagSensorData' uitgevoerd
  setInterval(vraagSensorData, UPDATE_INTERVAL);
}


/**
 * draw
 * de code in deze functie wordt meerdere keren per seconde
 * uitgevoerd door de p5 library, nadat de setup functie klaar is
 */
function draw() {
  // schrijf hieronder de code van je widget
  // hieronder wordt schematisch een knikkerbaan getekend

  // achtergrond: houtkleur, kies gerust iets anders
  background(71, 71, 70);

  // twee dikke strepen als 'opvangbak'
  stroke(0, 0, 0);
  strokeWeight(10);
  line(50, 20, 135, 60);
  line(250, 20, 165, 60);
  
  // streep naar trechter 
  line(75, 175, 145, 100); 

  // streep naar rad
  line(200, 175, 145, 100);

  // arduino elementen
  teller.show();
  

  //LED 

  //poortje

  //rad

  //trechter
  
}


// stuurt een verzoek aan de server dat alle
// sensordata opvraagt
function vraagSensorData() {
  var request = new XMLHttpRequest();

  // maak een http-verzoek
  request.open('GET', '/api/get/sensordata', true)

  // wat uitvoeren als het antwoord teruggegeven wordt?
  request.onload = function () {
    var data = JSON.parse(request.response);

    if (request.status == 200) {
      console.log("Dit geeft de server terug:" + data);
      teller.aantal = data.aantalKnikkers;
    }
    else {
      console.log("server reageert niet zoals gehoopt");
      console.log(request.response);
    }
  }

  // verstuur het request
  request.send()
}


// stuurt een http-verzoek aan de server met de
// nieuwe instellingen
function stuurNieuweInstellingen() {
  // moet nog worden gemaakt
}