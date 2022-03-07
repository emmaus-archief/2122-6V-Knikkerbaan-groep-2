class Poortje {
  x;
  y;
  status;

  constructor(_x, _y) {
    this.x = _x;
    this.y = _y;
    
  }

  show() {
    // poortje getekend
    stroke(141, 72, 171); 
    line(145, 315, 145, 355);

    stroke(141, 72, 171); 
    line(130, 60, 170, 60);

    noStroke();               // geen rand
    fill(255, 255, 255);      // wit
    textSize(14);
    // print portstatus
    text(this.status, this.x, this.y);

  }
}