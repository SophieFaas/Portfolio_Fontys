let books = [];
let hoverBook = -1;
let originalPositions = [];

function setup() {
    createCanvas(400, 400);
    for (let i = 0; i < 5; i++) {
        let x = width / 2 - 50;
        let y = height - 50 - i * 10;
        originalPositions.push({ x, y });
        books.push({ x, y, w: 100, h: 10, title: "Boek " + i });
    }
}

function draw() {
    background(220);

    for (let i = 0; i < books.length; i++) {
        let book = books[i];
        let originalPos = originalPositions[i];

        if (i === hoverBook) {
            book.y = lerp(book.y, mouseY - 5, 0.1);
        } else {
            book.y = lerp(book.y, originalPos.y, 0.1);
        }

        fill(255);
        stroke(0);
        rect(book.x, book.y, book.w, book.h);

        fill(0);
        textSize(10);
        textAlign(CENTER, CENTER);
        text(book.title, book.x + book.w / 2, book.y + book.h / 2);
    }
}

function mouseMoved() {
    hoverBook = -1;
    for (let i = books.length - 1; i >= 0; i--) {
        let book = books[i];
        if (mouseX > book.x && mouseX < book.x + book.w && mouseY > book.y && mouseY < book.y + book.h) {
            hoverBook = i;
            break;
        }
    }
}
