let confetti = [];

function setup() {
    createCanvas(400, 400); // Maak een canvas van 400x400 pixels
    for (let i = 0; i < 100; i++) {
        confetti[i] = new Confetti(); // Maak 100 confetti-objecten en voeg ze toe aan de array
    }
}

function draw() {
    background(220); // Wis het canvas en vul het met een grijze achtergrondkleur

    // Loop door de confetti-array en laat elk stukje confetti zien en laten vallen
    for (let i = 0; i < confetti.length; i++) {
        confetti[i].display();
        confetti[i].fall();
    }
}

class Confetti {
    constructor() {
        this.x = random(width);
        this.y = random(height);
        this.size = random(10, 20);
        this.color = color(random(255), random(255), random(255));
        this.speed = random(1, 5);
    }

    display() {
        fill(this.color); // Stel de vulkleur in op de willekeurige kleur
        noStroke();
        rect(this.x, this.y, this.size, this.size); // Teken het confettistukje als een rechthoek
    }

    fall() {
        this.y += this.speed; // Laat het confettistukje naar beneden vallen op basis van de snelheid
        if (this.y > height) {
            this.y = 0; // Als het confettistukje de onderkant bereikt, plaats het dan terug naar boven
        }
    }
}