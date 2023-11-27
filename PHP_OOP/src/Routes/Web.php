<?php

namespace Sophie\Herkansingoop\Routes;

use Sophie\Herkansingoop\Base\Interfaces\Response;
use Sophie\Herkansingoop\Controllers\BookController;
use Sophie\Herkansingoop\Controllers\HomepageController;
use Sophie\Herkansingoop\Controllers\MoviesController;
use Sophie\Herkansingoop\Controllers\NotFoundController;

class Web
{
    private static string $path;
    private static string $genericPath;

    private static ?int $id;

    public static function handle(): string
    {
        self::$path = parse_url($_SERVER["REQUEST_URI"], PHP_URL_PATH);
        $method = $_POST['_method'] ?? null;

        if ($method) {
            unset($_POST['_method']);
        }

        preg_match('/\d+/', self::$path, $matches);
        self::$id = $matches[0] ?? null;

        self::$genericPath = preg_replace('/\d+/', '{id}', self::$path);
        $response = self::route($method ?? $_SERVER['REQUEST_METHOD']);

        if ($response->shouldRedirectBack()) {
            header("Location: {$_SERVER['HTTP_REFERER']}");
            exit;
        }

        return $response->response();
    }

    public static function route(string $method): Response
    {
        return match ($method) {
            'GET' => self::gets(),
            'POST' => self::posts(),
            'PUT' => self::puts(),
            'DELETE' => self::deletes(),
        };
    }

    public static function gets(): Response
    {
        return match (self::$genericPath) {
            '/' => (new HomepageController())->index(),
            '/books' => (new BookController())->index(),
            '/movies' => (new MoviesController())->index(),
            '/books/{id}/edit' => (new BookController())->edit(self::$id),
            '/books/create' => (new BookController())->create(),
            '/movies/{id}/edit' => (new MoviesController())->edit(self::$id),
            '/movies/create' => (new MoviesController())->create(),
            default => (new NotFoundController())->notFound(),
        };
    }

    public static function posts(): Response
    {
        return match (self::$genericPath) {
            '/movies' => (new MoviesController())->store($_POST),
            '/books' => (new BookController())->store($_POST),
        };


    }

    // Update
    public static function puts(): Response
    {
        return match (self::$genericPath) {
            '/movies/{id}' => (new MoviesController())->update(self::$id, $_POST),
            '/books/{id}' => (new BookController())->update(self::$id, $_POST),
        };
    }

    // Delete
    public static function deletes(): Response
    {
        return match (self::$genericPath) {
            '/movies/{id}' => (new MoviesController())->destroy(self::$id),
            '/books/{id}' => (new BookController())->destroy(self::$id),
        };
    }
}
