<?php

namespace Sophie\Herkansingoop\Models;

use Sophie\Herkansingoop\Enums\Genre;

class Movie extends Multimedia
{
    public static string $table = 'movies';
    public Genre $genre;
    public string $director;

    public function __construct()
    {
        // unset it for lazy initialization (PDO will call __set method instead)
        unset($this->genre);
    }

    public function __set(string $name, $value): void
    {
        if ($name === 'genre') {
            $this->genre = Genre::from($value);
        }
    }
}