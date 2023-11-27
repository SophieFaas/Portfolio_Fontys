<?php

namespace Sophie\Herkansingoop\Controllers;

use Sophie\Herkansingoop\Base\Controller;
use Sophie\Herkansingoop\Base\Responses\View;
use Sophie\Herkansingoop\Enums\StatusCode;
use Sophie\Herkansingoop\Views\NotFound;

class NotFoundController extends Controller
{
    public function notFound(): View
    {
        return new View('404', statusCode: StatusCode::NOT_FOUND);
    }

}