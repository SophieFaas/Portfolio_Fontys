<?php

namespace Sophie\Herkansingoop\Controllers;

use Sophie\Herkansingoop\Base\Controller;
use Sophie\Herkansingoop\Base\Responses\View;
use Sophie\Herkansingoop\Views\Homepage;

class HomepageController extends Controller
{

    public function index(): View
    {
        return new View('homepage', ['test' => 'een testzin']);
    }

}