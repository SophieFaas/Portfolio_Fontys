<?php

/** @var Book $book */

use Sophie\Herkansingoop\Models\Book;

?>
<!DOCTYPE html>
<html>
<head>

</head>
<body>

<h2>Je huidige boek dat je wil aanpassen is: <?= $book->title ?> </h2>

<form action="/books/<?= $book->id ?>" method="post">
    <input type="hidden" name="_method" value="PUT">
    <label for="btitle">Title:</label><br>
    <input type="text" id="btitle" name="title" value="<?= $book->title ?>"><br><br>

    <label for="bauthor">Author:</label><br>
    <input type="text" id="bauthor" name="author" value="<?= $book->author ?>"><br><br>

    <label for="bisbn">ISBN:</label><br>
    <input type="text" id="bisbn" name="isbn" value="<?= $book->isbn ?>"><br><br>

    <label for="ldescription">Description:</label><br>
    <input type="text" id="bdescription" name="description" value="<?= $book->description ?>"><br><br>

    <input type="submit" value="Submit">
</form>
</body>
</html>
