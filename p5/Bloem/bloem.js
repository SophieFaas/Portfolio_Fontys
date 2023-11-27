let numPetals = 10;
let petals = [];
let angle = 0;

function setup() {
    createCanvas(400, 400);
    let petalColor = color(random(255), random(255), random(255));

    // Maak de bloemblaadjes
    for (let i = 0; i < numPetals; i++) {
        let petalAngle = TWO_PI / numPetals * i;
        petals[i] = new Petal(width / 2, height / 2, petalAngle, petalColor);
    }
}

function draw() {
    background(220);

    // Bereken de sinwaarde van de hoek om de bloemblaadjes te laten draaien
    let rotation = sin(angle);

    // Update en toon de bloemblaadjes
    for (let i = 0; i < petals.length; i++) {
        petals[i].update(rotation);
        petals[i].display();
    }

    // Verhoog de hoek om de animatie door te laten gaan
    angle += 0.02;
}

// Klasse voor de bloemblaadjes
class Petal {
    constructor(x, y, angle, color) {
        this.x = x;
        this.y = y;
        this.size = 30;
        this.angle = angle;
        this.color = color;
    }

    update(rotation) {
        // Pas de rotatie van het bloemblad aan op basis van de rotation-waarde
        this.angle += rotation * 0.1;
    }

    display() {
        // Teken het bloemblad
        push();
        translate(this.x, this.y);
        rotate(this.angle);
        fill(this.color);
        stroke(0);
        strokeWeight(2);
        ellipse(0, 0, this.size, this.size * 2);
        pop();
    }
}


