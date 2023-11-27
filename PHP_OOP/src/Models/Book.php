<?php

namespace Sophie\Herkansingoop\Models;

class Book extends Multimedia
{
    public static string $table = 'books';
    public string $author;
    public string $isbn;
}