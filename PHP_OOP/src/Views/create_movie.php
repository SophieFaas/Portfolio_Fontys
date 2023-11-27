<?php

/** @var Movie $movie */

use Sophie\Herkansingoop\Enums\Genre;
use Sophie\Herkansingoop\Models\Movie;


?>
<!DOCTYPE html>
<html>
<head>

</head>
<body>

<h2>Je gaat nu een film aanmaken.</h2>

<form action="/movies" method="post">

    <label for="mtitle">Title:</label><br>
    <input type="text" id="mtitle" name="title"><br><br>

    <label for="mgenre">Genre:</label><br>
    <select id="mgenre" name="genre">
        <?php
        foreach (Genre::cases() as $genre) {
        ?>
        <option value="<?= $genre->value ?>"><?= $genre->value ?></option>
      <?php } ?>
    </select><br><br>
    <label for="mdirector">Director:</label><br>
    <input type="text" id="mdirector" name="director"><br><br>

    <label for="mdescription">Description:</label><br>
    <input type="text" id="mdescription" name="description"><br><br>

    <input type="submit" value="Submit">
</form>
</body>
</html>
