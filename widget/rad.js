class Rad {
  x;
  y;

  constructor(_x, _y) {
    this.x = _x;
    this.y = _y;
  
  }

  show() {
      // rad getekend
  stroke(0,0,0); 
  strokeWeight(7);
  line(220, 250, 270, 240); // rechts
  line(220, 250, 220, 200); // top
  line(220, 250, 170, 240); // links
  line(220, 250, 255, 300); // rechts onder
  line(220, 250, 185, 300); // links onder
    
  }
}