<?php /** @var array $books */

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

        tr:nth-child(even) {
            background-color: #dddddd;
        }

        body {
            background: url(https://images.unsplash.com/photo-1491841573634-28140fc7ced7?ixlib=rb-4.0.3&ixid=MnwxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHx8&auto=format&fit=crop&w=870&q=80) no-repeat center center fixed;;

            -webkit-background-size: cover;
            -moz-background-size: cover;
            -o-background-size: cover;
            background-size: cover;
        }  /* optional, center the image */
    </style>
</head>
<body>

<a href="/books/create" style="float: right;"><button>new book</button></a>
<table>
    <tr>
        <th>Title</th>
        <th>Author</th>
        <th>ISBN</th>
        <th>Description</th>
        <th>Actions</th>
    </tr>
    <?php

    /** @var Book $book */
    foreach ($books as $book) {
        ?>
        <tr>
            <td><?= $book->title ?></td>
            <td><?= $book->author ?></td>
            <td><?= $book->isbn ?></td>
            <td><?= $book->description ?></td>
            <td>
                <a href="/books/<?= $book->id ?>/edit"><button>edit</button></a>
                <form action="/books/<?= $book->id ?>" method="post" style="display: inline-block">
                    <input type="hidden" name="_method" value="DELETE"/>
                    <input type="submit" name="delete" value="delete"/>
                </form>
            </td>
        </tr>
    <?php } ?>
</table>
<a href="/" style="display: block; text-align: center;">home</a>
</body>
</html>
