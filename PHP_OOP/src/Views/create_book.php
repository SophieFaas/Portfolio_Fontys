<?php

/** @var Book $book */

use Sophie\Herkansingoop\Models\Book;

?>
<!DOCTYPE html>
<html>
<head>

</head>
<body>

<h2>Je kan hier je nieuwe boek aanmaken.</h2>

<form action="/action_page.php">
    <label for="ltitle">Title:</label><br>
    <input type="text" id="ltitle" name="ltitle"><br><br>

    <label for="lauthor">Author:</label><br>
    <input type="text" id="bookauthor" name="bookauthor"><br><br>

    <label for="lisbn">ISBN:</label><br>
    <input type="text" id="bookisbn" name="bookisbn"><br><br>

    <label for="ldescription">Description:</label><br>
    <input type="text" id="bookdescription" name="bookdescription"><br><br>

    <input type="submit" value="Submit">
</form>
</body>
</html>
