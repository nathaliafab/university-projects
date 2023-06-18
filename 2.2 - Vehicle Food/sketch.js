// https://editor.p5js.org/nathaliafab/full/lT7A1PUDn

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

  // Adicionei essa função:
  vehicle.search();
  
  let vision = 400; // botei enorme pq senão demora muito
  
  sameArea = dist(vehicle.pos.x, vehicle.pos.y, target.x, target.y) < vision + 16;
  // +16 porque quero que ele perceba o target assim que ele cruza o campo de visão (o raio do target é 16)
  
  c = color('rgba(252, 252, 3, 0.2)');
  fill(c);
  circle (vehicle.pos.x, vehicle.pos.y, vision*2); // raio = vision

  if(sameArea) {
    vehicle.seek(target);
  }
  
  vehicle.update();
  vehicle.show();
}
