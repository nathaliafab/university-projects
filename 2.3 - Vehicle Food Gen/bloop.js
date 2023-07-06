// Creature class

// Create a "bloop" creature
class Bloop {
  constructor(l, dna_) {
    this.position = l.copy(); // Location
    this.health = 200; // Life timer
    this.xoff = random(1000); // For perlin noise
    this.yoff = random(1000);
    this.dna = dna_; // DNA
    // DNA will determine size and maxspeed (gene 0)
    // The bigger the bloop, the slower it is
    // gene 1 -> visão do bloop
    this.maxspeed = map(this.dna.genes[0], 0, 1, 15, 0);
    this.r = map(this.dna.genes[0], 0, 1, 10, 50);
    this.vision = map(this.dna.genes[1], 0, 1, 10, 200);
    this.target = null; // Posicao da comida que o bloop vai seguir
    
    // Evita que a visao seja menor que o bloop
    if(this.r > this.vision) {
      let temp = this.r;
      this.r = this.vision;
      this.vision = temp;
    }
  }

  run() {  
    this.update();
    this.borders();
    this.display();
  }

  // A bloop can find food and eat it
  eat(f) {
    let food = f.getFood();
    // Are we touching any food objects?
    for (let i = food.length - 1; i >= 0; i--) {
      let foodLocation = food[i];
      
      let d = p5.Vector.dist(this.position, foodLocation);

      if (d < this.vision / 2) {
        this.target = foodLocation;
        this.update();
        
        if (d < this.r / 2) {
          this.health += 100;
          food.splice(i, 1);
        }
        
        this.target = null;
      }
    }
  }

  reproduce(bloops) {
    // Sexual reproduction
    if (random(1) < 0.0010) {
      let matingPool = this.findMatingPartner(bloops);

      if (matingPool.length > 0) {
        let partner = random(matingPool);

        // Crossover
        let childGenes = [];

        for (let i = 0; i < this.dna.genes.length; i++) {
          let gene = random() < 0.5 ? this.dna.genes[i] : partner.dna.genes[i];

          childGenes[i] = gene;
        }

        let childDNA = new DNA(childGenes);
        childDNA.mutate(0.01);

        return new Bloop(this.position, childDNA);
      }
    }
    
    else
      return null;
  }

  
  findMatingPartner(bloops) {
    let matingPool = [];

    for (let i = 0; i < bloops.length; i++) {
      let other = bloops[i];

      let distance = p5.Vector.dist(this.position, other.position);

      if (distance > 0 && distance < this.vision)
        matingPool.push(other);
    }

    return matingPool;
  }

  // Method to update position
  update() {
    let vx = map(noise(this.xoff), 0, 1, -this.maxspeed, this.maxspeed);
    let vy = map(noise(this.yoff), 0, 1, -this.maxspeed, this.maxspeed);
    let velocity = createVector(vx, vy);
    this.xoff += 0.01;
    this.yoff += 0.01;
    
    if (this.target !== null) {      
      // Se ele tem um target definido (avistou uma comida), ele vai atras
      let desired = p5.Vector.sub(this.target, this.position);

      desired.normalize();
      desired.mult(this.maxspeed);

      let steer = p5.Vector.sub(desired, velocity);
      steer.limit(this.maxspeed);
      this.position.add(steer);

    } else {
      // Sem target, usa a movimentacao padrao (perlin noise)
      this.position.add(velocity);
    }

    this.health -= 0.2;
  }
  
  // Wraparound
  borders() {
    if (this.position.x < -this.r/2) this.position.x = width+this.r/2;
    if (this.position.y < this.r/2) this.position.y = height+this.r/2;
    if (this.position.x > width+this.r/2) this.position.x = -this.r/2;
    if (this.position.y > height+this.r/2) this.position.y = -this.r/2;
  }

  // Method to display
  display() {
    ellipseMode(CENTER);
    stroke(0, this.health);
    fill(0, this.health);
    ellipse(this.position.x, this.position.y, this.r, this.r);
  
    let c = color('rgba(252, 252, 3, 0.2)');
    
    stroke(0, 0);
    fill(c);
    circle (this.position.x, this.position.y, this.vision);
  }

  // Death
  dead() {
    if (this.health < 0.0) {
      return true;
    } else {
      return false;
    }
  }
}
