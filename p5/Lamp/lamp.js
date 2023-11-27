function setup() {
    createCanvas(400, 400);
    drawLavaLamp();
}

function drawLavaLamp() {
    background(0);

    // Teken de basis van de Mathmos Astro lavalamp
    fill(100, 100, 100); // Grijs
    stroke(0);
    strokeWeight(2);
    beginShape();
    vertex(150, 300);
    bezierVertex(125, 175, 275, 175, 250, 300);
    endShape(CLOSE);

    // Teken de glazen lamp van de lavalamp
    fill(100, 100, 250); // Blauw
    noStroke();
    ellipse(200, 150, 200, 100);
}










