<?php

namespace Sophie\Herkansingoop\Base;

class Model
{
    public int $id;

    public static string $table;

    public static function query(string $query, array $bindings): array
    {
        return DB::getInstance()->query($query, $bindings, static::class);
    }

    public static function find(int $id): static
    {
        $table = static::$table;

        return static::first("SELECT * FROM {$table} WHERE id = :id LIMIT 1", ['id' => $id]);
    }

    public static function first(string $query, array $bindings): static
    {
        return DB::getInstance()->first($query, $bindings, static::class);
    }

    public static function all($columns = null): array
    {
        return DB::getInstance()->selectAll(static::$table, static::class, $columns);
    }

    public static function create(array $data): static
    {
        $id = DB::getInstance()->insert(static::$table, $data);

        return static::find($id);
    }

    public function update(array $data): static
    {
        DB::getInstance()->update(static::$table, $this->id, $data);

        return $this->refresh();
    }

    public function delete(): bool
    {
        return DB::getInstance()->delete(static::$table, $this->id);
    }

    public function refresh(): static
    {
        return static::find($this->id);
    }
}