<?php

namespace Sophie\Herkansingoop\Base\Interfaces;

// http response die terug gaat naar de gebruiker.
interface Response
{
    public function response(): string;

    public function shouldRedirectBack(): bool;
}