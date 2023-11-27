<?php /** @var array $movies */

use Sophie\Herkansingoop\Models\Book;

?>
<!DOCTYPE html>
<html>
<head>
    <style>
        table {
            font-family: arial, sans-serif;
            border-collapse: collapse;
            width: 100%;
        }

        td, th {
            border: 1px solid #dddddd;
            text-align: left;
            padding: 8px;
        }

        tr:nth-child(odd) {
            background-color: rgba(0, 0, 0, 0.5);
            color: white;
        }

        tr:nth-child(even) {
            background-color: rgba(221, 221, 221, 0.5);
        }
        body {
            background: url(https://images.unsplash.com/photo-1505686994434-e3cc5abf1330?ixlib=rb-4.0.3&ixid=MnwxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHx8&auto=format&fit=crop&w=1920&q=100) no-repeat center center fixed;;

            -webkit-background-size: cover;
            -moz-background-size: cover;
            -o-background-size: cover;
            background-size: cover;
        }  /* optional, center the image */

    </style>
</head>
<body>

<a href="/movies/create" style="float: right;"><button>new movie</button></a>

<table>
    <tr>
        <th>Title</th>
        <th>Genre</th>
        <th>Director</th>
        <th>Description</th>
        <th>Actions</th>
    </tr>
    <?php

    /** @var \Sophie\Herkansingoop\Models\Movie $movie */
    foreach ($movies as $movie) {
        ?>
        <tr>
            <td><?= $movie->title ?></td>
            <td><?= $movie->genre->value ?></td>
            <td><?= $movie->director ?></td>
            <td><?= $movie->description ?></td>
            <td>
                <a href="/movies/<?= $movie->id ?>/edit"><button>edit</button></a>
                <form action="/movies/<?= $movie->id ?>" method="post" style="display: inline-block">
                    <input type="hidden" name="_method" value="DELETE"/>
                    <input type="submit" value="delete" />
                </form>
            </td>
        </tr>
    <?php } ?>
</table>
<a href="/" style="display: block; text-align: center;">home</a>
</body>
</html>
