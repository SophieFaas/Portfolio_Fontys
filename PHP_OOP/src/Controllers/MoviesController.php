<?php

namespace Sophie\Herkansingoop\Controllers;

use Sophie\Herkansingoop\Base\Controller;
use Sophie\Herkansingoop\Base\Interfaces\CRUD;
use Sophie\Herkansingoop\Base\Responses\JsonResponse;
use Sophie\Herkansingoop\Base\Responses\View;
use Sophie\Herkansingoop\Base\ValidationException;
use Sophie\Herkansingoop\Enums\Genre;
use Sophie\Herkansingoop\Enums\StatusCode;
use Sophie\Herkansingoop\Models\Movie;

// Implements is voor interfaces.
class MoviesController extends Controller implements CRUD
{

    public function index(): View
    {
        return new View('list_movies', [
            'movies' => Movie::all(),
        ]);
    }

    public function edit(int $id): View
    {
        return new View('edit_movie', ['movie' => Movie::find($id)]);
    }

    public function create(): View
    {
        return new View('create_movie');
    }

    public function store(array $data): JsonResponse
    {
        // Titel mag niet twee keer voorkomen.
        $titles = [];
        /** @var Movie $movie */
        foreach (Movie::all() as $movie){
            $titles[] = $movie->title;
        }
        //dd($titles);

        if(in_array($data['title'], $titles)){
            throw new ValidationException('This movie is already in the database.');
        }
        //dd(Movie::all());
        //dd($data);
        // Exception titel moet minstens 1 karakter hebben.
        if (strlen($data['title']) < 1){
            throw new ValidationException('The title is too short');
        }

        // Exception genre moet bestaan.
        if (! in_array($data['genre'], Genre::keys())) {
            throw new ValidationException('This genre does not exist');
        }

        // Exception director naam te lang
        if (strlen($data['director']) > 10) {
            throw new ValidationException('The name is too long');
        }
        // Exception niet dubbel in database

        return new JsonResponse(['success' => Movie::create($data)], StatusCode::CREATED);
    }

    public function update(int $id, array $data): JsonResponse
    {

        return new JsonResponse(['success' => Movie::find($id)->update($data)]);
    }

    public function destroy(int $id): JsonResponse
    {
        return new JsonResponse(['success' => Movie::find($id)->delete()]);
    }
}