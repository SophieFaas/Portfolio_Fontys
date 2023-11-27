<?php

ini_set('display_errors', 1);
ini_set('display_startup_errors', 1);
error_reporting(E_ALL);

require_once 'vendor/autoload.php';

use JetBrains\PhpStorm\NoReturn;
use Sophie\Herkansingoop\Base\DB;
use Sophie\Herkansingoop\Routes\Web;

// Hoef je geen vardump meer te gebruiken! :)
function dd(...$args): void
{
    if (count($args) === 1) {
        var_dump($args[0]);
    } else {
        var_dump($args);
    }
    die;
}

DB::getInstance();
echo Web::handle();
