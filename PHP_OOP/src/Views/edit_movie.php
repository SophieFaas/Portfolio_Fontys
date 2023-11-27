<?php ///** @var array $data */

/** @var Movie $movie */
//$movie = $data['movie'];

use Sophie\Herkansingoop\Enums\Genre;
use Sophie\Herkansingoop\Models\Movie;

?>
<!DOCTYPE html>
<html>
<head>

</head>
<body>

<h2>Je huidige film dat je wil aanpassen is: <?= $movie->title ?> </h2>

<form action="/movies/<?= $movie->id ?>" method="post">
    <input type="hidden" name="_method" value="PUT">
    <label for="mtitle">Title:</label><br>
    <input type="text" id="mtitle" name="title" value="<?= $movie->title ?>"><br><br>

    <label for="mgenre">Genre:</label><br>
    <select id="mgenre" name="genre">
        <?php
        foreach (Genre::cases() as $genre) {
            ?>
            <option
            <?php

            if ($genre === $movie->genre) {
                ?> selected <?php
            }
            ?>
            value="<?= $genre->value ?>"
            >
            <?= $genre->value ?>
            </option>
        <?php } ?>
    </select><br><br>
    <label for="mdirector">Director:</label><br>
    <input type="text" id="mdirector" name="director" value="<?= $movie->director ?>"><br><br>

    <label for="mdescription">Description:</label><br>
    <input type="text" id="mdescription" name="description" value="<?= $movie->description ?>"><br><br>

    <input type="submit" value="Submit">
</form>
</body>
</html>
