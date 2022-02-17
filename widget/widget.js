
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
  
  // streep naar trechter --- wss weg 
  line(85, 175, 145, 100); 
  
  /*
  // strepen naar trechter 
  line(45, 140, 145, 100);
  line(10, 140, 50, 180); 
  */

  // streep naar rad ------- wss weg 
  line(200, 175, 145, 100);

  /*
  // strepen naar rad
  line(235, 135, 145, 100);
  line(275, 140, 240, 185);
  */

  // strepen bij rad
  line(90, 385, 280, 300); // streep onder het rad
  line(280, 300, 280, 200); // streep naast het rad

  // strepen bij trechter 
  line(25, 375, 125, 435); // streep direct onder
  line(180, 445, 75, 500); 
  line(15, 505, 130, 580); 

  // scherm 
  rect(165, 485, 120, 50);

  // trechter 
  line(25, 200, 25, 300); // wanden
  line(100, 200, 100, 300); 
  line(25, 300, 50, 325); // inlopende delen
  line(100, 300, 75, 325); 
  line(50, 325, 50, 350);
  line(75, 325, 75, 350);

  stroke(0, 0, 0);
  strokeWeight(2);
  line(15, 215, 115, 235); // stukjes erdoorheen 
  line(15, 255, 115, 245);
  line(15, 265, 115, 295);

  // rad 
  stroke(0,0,0); 
  strokeWeight(8);
  line(220, 250, 270, 240); // rechts
  line(220, 250, 220, 200); // top
  line(220, 250, 170, 240); // links
  line(220, 250, 255, 300); // rechts onder
  line(220, 250, 185, 300); // links onder

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