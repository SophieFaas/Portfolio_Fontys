<?php

namespace Sophie\Herkansingoop\Enums;

enum Genre: string
{
    case HORROR = 'Horror';
    case COMEDY = 'Comedy';
    case DRAMA = 'Drama';
    case FANTASY = 'Fantasy';
    case SCIFI = 'Science fiction';
    case ARTHOUSE = 'Art house';

    public static function keys(): array
    {
        return array_column(Genre::cases(), 'name');
    }
}