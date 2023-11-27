<?php

namespace Sophie\Herkansingoop\Enums;

enum StatusCode: int
{
    case SUCCESS = 200;
    case NOT_FOUND = 404;
    case CREATED = 201;
}
