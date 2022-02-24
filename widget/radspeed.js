class Radspeed {
  x;
  y;
  snelheid;

  constructor(_x, _y) {
    this.x = _x;
    this.y = _y;
    this.snelheid = 0;
  }

  show() {
    noStroke();               // geen rand
    fill(255, 255, 255);      // zwart
    textSize(14);
    // print laatste radsnelheid
    text(this.snelheid, this.x, this.y);
  }
}