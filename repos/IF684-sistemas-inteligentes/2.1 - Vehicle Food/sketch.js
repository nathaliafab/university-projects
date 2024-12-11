// https://editor.p5js.org/nathaliafab/full/fI5Bcf_Ah?authuser=1

let vehicle;
let target;
let foodCounter = 0;

function setup() {
  createCanvas(windowWidth, windowHeight);

  vehicle = new Vehicle(windowWidth / 2, windowHeight / 2);

  targetPosX = random(width);
  targetPosY = random(height);
}

function draw() {
  background(0);
  
  fill(255, 0, 0);
  noStroke();
  target = createVector(targetPosX, targetPosY);
  circle(target.x, target.y, 32);
  
  collision = dist(vehicle.pos.x, vehicle.pos.y, target.x, target.y) < 30;
  
  if (collision) {
    targetPosX = random(width);
    targetPosY = random(height);

    foodCounter++;
  }
  
  textSize(32);
  fill(0, 102, 153);
  text(foodCounter, 10, 30);

  vehicle.seek(target);
  vehicle.update();
  vehicle.show();
}
