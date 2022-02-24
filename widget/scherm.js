class Scherm {
  x;
  y;
  snelheid;

  constructor(_x, _y) {
    this.x = _x;
    this.y = _y;
    this.snelheid = 0;
  }

  show(){
     // scherm getekend
  stroke('black');
  fill(237, 185, 198);
  rect(165, 485, 120, 50);
     // snelheid 
  noStroke();
  fill('black');
  textSize(30);
  textStyle(BOLD);
  text(this.snelheid, 180, 520);
  }
}