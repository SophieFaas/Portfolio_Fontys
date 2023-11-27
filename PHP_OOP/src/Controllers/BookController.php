<?php

namespace Sophie\Herkansingoop\Controllers;

use Sophie\Herkansingoop\Base\Controller;
use Sophie\Herkansingoop\Base\Interfaces\CRUD;
use Sophie\Herkansingoop\Base\Responses\JsonResponse;
use Sophie\Herkansingoop\Base\Responses\View;
use Sophie\Herkansingoop\Base\ValidationException;
use Sophie\Herkansingoop\Enums\StatusCode;
use Sophie\Herkansingoop\Models\Book;


class BookController extends Controller implements CRUD
{

    public function index(): View
    {
        return new View('list_books', [
            'books' => Book::all(),
        ]);
    }

    public function edit(int $id): View
    {
        return new View('edit_book', ['book' => Book::find($id)]);
    }

    public function create(): View
    {
        return new View('create_book');
    }
    public function store(array $data): JsonResponse
    {
        // ISBN moet uit cijfers bestaan.
        if(! ctype_digit($data['isbn'])){
            throw new ValidationException('All isbn characters should be numbers');
        }
        return new JsonResponse(['success' => Book::create($data)], StatusCode::CREATED);
    }

    public function update(int $id, array $data): JsonResponse
    {
        return new JsonResponse(['success' => Book::find($id)->update($data)]);
    }

    public function destroy(int $id): JsonResponse
    {
        return new JsonResponse(['success' => Book::find($id)->delete()]);
    }
}