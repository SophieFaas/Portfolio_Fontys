<?php

namespace Sophie\Herkansingoop\Base;

use PDO;

class DB
{
    private static self|null $instance = null;

    private PDO $pdo;

    // Singleton
    private function __construct()
    {
        $host = '127.0.0.1';
        $db = 'oop';
        $user = 'root';
        $pass = '';
        $charset = 'utf8mb4';
        $port = 3306;

        $dsn = "mysql:host=$host;dbname=$db;charset=$charset;port=$port";

        $options = [
            PDO::ATTR_ERRMODE => PDO::ERRMODE_EXCEPTION,
            PDO::ATTR_EMULATE_PREPARES => false,
            PDO::ATTR_DEFAULT_FETCH_MODE => PDO::FETCH_PROPS_LATE,
        ];

        $this->pdo = new PDO($dsn, $user, $pass, $options);
    }

    public static function getInstance(): self
    {
        if (self::$instance == null) {
            self::$instance = new self();
        }

        return self::$instance;
    }

    public function first(string $query, array $bindings = [], string $class = null): Model
    {
        return $this->query($query, $bindings, $class)[0];
    }

    public function query(string $query, array $bindings = [], string $class = null): array
    {
        $stmt = $this->pdo->prepare($query);
        $stmt->execute($bindings);

        return $stmt->fetchAll(PDO::FETCH_CLASS | PDO::FETCH_PROPS_LATE, $class);
    }

    public function selectAll(string $table, string $class, array $columns = null): array
    {
        if (!$columns) {
            return $this->query("SELECT * FROM {$table}", class: $class);
        }

        $columnsString = implode(', ', $columns);

        return $this->query("SELECT {$columnsString} FROM {$table}", class: $class);
    }

    public function insert(string $table, array $data): int
    {
        $columns = array_keys($data);
        $columnKeys = implode(', ', $columns);

        foreach ($columns as $key => $column) {
            $columns[$key] = ":{$column}";
        }

        $columnValues = implode(', ', $columns);
        $stmt = $this->pdo->prepare("INSERT INTO {$table} ({$columnKeys}) VALUES ($columnValues)");
        $stmt->execute($data);

        return $this->pdo->lastInsertId();
    }

    public function update(string $table, int $id, array $data): bool
    {
        $columns = array_keys($data);

        foreach ($columns as $key => $column) {
            $columns[$key] = "$column=:$column";
        }


        $prepared = implode(', ', $columns);

        $data['id'] = $id;

        $stmt = $this->pdo->prepare("UPDATE {$table} SET {$prepared} WHERE id=:id");
//dd("UPDATE {$table} SET {$prepared} WHERE id=:id", $data);
        return $stmt->execute($data);
    }

    public function delete(string $table, int $id): bool
    {
        $data = [];
        $data['id'] = $id;
        $stmt = $this->pdo->prepare("DELETE FROM {$table} WHERE id=:id");

        return $stmt->execute($data);
    }

}