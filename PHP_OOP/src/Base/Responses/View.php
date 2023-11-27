<?php

namespace Sophie\Herkansingoop\Base\Responses;


use Sophie\Herkansingoop\Base\Interfaces\Response;
use Sophie\Herkansingoop\Enums\StatusCode;

class View implements Response
{
    public function __construct(private readonly string $template, private array $data = [], private readonly StatusCode $statusCode = StatusCode::SUCCESS)
    {
    }

    public function escape(string $string)
    {
        return htmlspecialchars($string, ENT_QUOTES, 'UTF-8');
    }

    public function response(): string
    {
        return $this->render();
    }

    public function render(): string
    {
        http_response_code($this->statusCode->value);
        //  Haalt uit array, zet key als variabele scope
        extract($this->data);

        // ob_start & ob_get_clean werken samen, ob_get_clean krijgt inhoud van require
        ob_start();
        require "{$_SERVER['DOCUMENT_ROOT']}/src/Views/{$this->template}.php";
        return ob_get_clean();
    }

    public function shouldRedirectBack(): bool
    {
        return false;
    }
}