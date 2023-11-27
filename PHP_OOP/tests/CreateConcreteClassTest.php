<?php


use PHPUnit\Framework\TestCase;
use Sophie\Herkansingoop\Base\ValidationException;
use Sophie\Herkansingoop\Controllers\MoviesController;
use Sophie\Herkansingoop\Enums\Genre;

class CreateConcreteClassTest extends TestCase
{
    public function test_too_long_name_throws_validation_exception(): void
    {
        $this->expectException(ValidationException::class);

        (new MoviesController())->store([
            'director' => 'AAAAAAAAAAAAA'
        ]);
    }

    public function test_no_exception_when_short(): void
    {

        $response = (new MoviesController())->store([
            'director' => 'AAAAAA',
            'genre' => Genre::ARTHOUSE->value
        ]);

      $this->assertArrayHasKey('success', $response->data);
    }

}
