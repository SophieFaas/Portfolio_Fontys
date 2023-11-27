<?php

namespace Sophie\Herkansingoop\Base\Responses;

use Sophie\Herkansingoop\Base\Interfaces\Response;
use Sophie\Herkansingoop\Enums\StatusCode;

class JsonResponse implements Response
{
    public function __construct(public array $data, private readonly StatusCode $statusCode = StatusCode::SUCCESS)
    {
    }

    // Zet header van de statuscode
    public function response(): string
    {
        http_response_code($this->statusCode->value);

        return json_encode($this->data);
    }

    // Redirect
    public function shouldRedirectBack(): bool
    {
        return true;
    }
}