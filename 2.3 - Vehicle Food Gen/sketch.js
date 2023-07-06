// https://editor.p5js.org/nathaliafab/full/hskSkxtk4

let world;
let bloopCount;
let foodCount;

function setup() {
  createCanvas(windowWidth, windowHeight);
  world = new World(14);
  bloopCount = createP();
  foodCount = createP();
  bloopCount.position(10, 10); // Posição do contador de bloops
  foodCount.position(10, 30); // Posição do contador de comida
}

function draw() {
  background(175);
  world.run();

  // Atualizar a contagem de bloops e comida
  bloopCount.html('Bloops: ' + world.bloops.length);
  foodCount.html('Food: ' + world.food.getFood().length);
}

function mousePressed() {
  world.born(mouseX, mouseY);
}

function mouseDragged() {
  world.born(mouseX, mouseY);
}
