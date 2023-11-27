<?php

namespace Sophie\Herkansingoop\Base\Interfaces;

use Sophie\Herkansingoop\Base\Responses\JsonResponse;
use Sophie\Herkansingoop\Base\Responses\View;


interface CRUD
{
    // view om overzicht van model te laten zien, hier doorklikken naar 'show' en 'edit'
    public function index(): View;

    // view met velden om een nieuw object aan te maken
    public function create(): View;

    // view met velden om een specifiek object aan te passen (deleteknop ook hier)
    public function edit(int $id): View;

    // maak nieuwe aan met dit request
    public function store(array $data): JsonResponse;

    // update met dit request
    public function update(int $id, array $data): JsonResponse;

    // verwijder een record met dit request
    public function destroy(int $id): JsonResponse;
}