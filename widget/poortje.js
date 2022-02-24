class Poortje {
  x;
  y;
  aantal;

  constructor(_x, _y) {
    this.x = _x;
    this.y = _y;
    
  }

  show() {
    // poortje getekend
    stroke(141, 72, 171); 
    line(145, 315, 145, 355);
  }
}