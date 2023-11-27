#include <string.h>

#include "administration.h"
#include "unity.h"
#include "unity_test_module.h"

// leave resource_detector.h as last include!
#include "resource_detector.h"

// I rather dislike keeping line numbers updated, so I made my own macro to ditch the line number
#define MY_RUN_TEST(func) RUN_TEST(func, 0)

void administration_setUp(void)
{
    // This is run before EACH test
}

void administration_tearDown(void)
{
    // This is run after EACH test
}

// Testen Find animal:

// Test die zoekt of animal echt echt bestaat.
void test_FindAnimalTrue(void)
{

    Animal animal1 = {1, Cat, Female, 8, {7, 8, 2020} };
    Animal animal2 = {2, Parrot, Male, 2, {12, 10, 2021} };
    Animal animal3 = {3, Dog, Female, 10, {1, 5, 2021} };
    int arrayLength = 8;
    Animal animalArray[arrayLength];
    animalArray[0] = animal1;
    animalArray[1] = animal2;
    animalArray[2] =  animal3;
    size_t numberAnimals = 3;
    Animal animalFound;
    TEST_ASSERT_EQUAL(1, findAnimalById(2, animalArray, numberAnimals, &animalFound));
}

// Test die animal zoekt die niet bestaat.
void test_FindAnimalFalse(void)
{
    Animal animal1 = {1, Cat, Female, 8, {7, 8, 2020} };
    Animal animal2 = {2, Parrot, Male, 2, {12, 10, 2021} };
    Animal animal3 = {3, Dog, Female, 10, {1, 5, 2021} };
    int arrayLength = 8;
    Animal animalArray[arrayLength];
    animalArray[0] = animal1;
    animalArray[1] = animal2;
    animalArray[2] =  animal3;
    size_t numberAnimals = 3;
    Animal animalFound;
    TEST_ASSERT_EQUAL(0, findAnimalById(4, animalArray, numberAnimals, &animalFound));
}

// Test voor toevoegen dier
void test_AddAnimalTrue(void)
{
    Animal animal1 = {1, Cat, Female, 8, {7, 8, 2020} };
    Animal animal2 = {2, Parrot, Male, 2, {12, 10, 2021} };
    Animal animal3 = {3, Dog, Female, 10, {1, 5, 2021} };
    Animal animal4 = {4, Dog, Male, 5, {9, 1, 2020}};
    int arrayLength = 8;
    Animal animalArray[arrayLength];
    animalArray[0] = animal1;
    animalArray[1] = animal2;
    animalArray[2] =  animal3;
    size_t numberAnimals = 3;
    TEST_ASSERT_EQUAL(0, addAnimal(&animal4, animalArray, arrayLength, numberAnimals, &numberAnimals));
}

void test_AddAnimalFalse(void)
{
    Animal animal1 = {1, Cat, Female, 8, {7, 8, 2020} };
    Animal animal2 = {2, Parrot, Male, 2, {12, 10, 2021} };
    Animal animal3 = {3, Dog, Female, 10, {1, 5, 2021} };
    Animal animal4 = {3, Dog, Male, 5, {9, 1, 2020}};
    int arrayLength = 8;
    Animal animalArray[arrayLength];
    animalArray[0] = animal1;
    animalArray[1] = animal2;
    animalArray[2] =  animal3;
    size_t numberAnimals = 3;
    TEST_ASSERT_EQUAL(-1, addAnimal(&animal4, animalArray, arrayLength, numberAnimals, &numberAnimals));
}

// Test voor verwijderen dier
void test_RemoveAnimalTrue(void)
{
    Animal animal1 = {1, Cat, Female, 8, {7, 8, 2020} };
    Animal animal2 = {2, Parrot, Male, 2, {12, 10, 2021} };
    Animal animal3 = {3, Dog, Female, 10, {1, 5, 2021} };
    int arrayLength = 8;
    Animal animalArray[arrayLength];
    animalArray[0] = animal1;
    animalArray[1] = animal2;
    animalArray[2] =  animal3;
    size_t numberAnimals = 3;
    TEST_ASSERT_EQUAL(1, removeAnimal(2, animalArray, numberAnimals, &numberAnimals));
    TEST_ASSERT_EQUAL(2, numberAnimals);
}

void test_RemoveAnimalFalse(void)
{
    Animal animal1 = {1, Cat, Female, 8, {7, 8, 2020} };
    Animal animal2 = {2, Parrot, Male, 2, {12, 10, 2021} };
    Animal animal3 = {3, Dog, Female, 10, {1, 5, 2021} };
    int arrayLength = 8;
    Animal animalArray[arrayLength];
    animalArray[0] = animal1;
    animalArray[1] = animal2;
    animalArray[2] =  animal3;
    size_t numberAnimals = 3;
    TEST_ASSERT_EQUAL(0, removeAnimal(4, animalArray, numberAnimals, &numberAnimals));
}

void run_administration_tests()
{
    UnityRegisterSetupTearDown( administration_setUp, administration_tearDown);

    MY_RUN_TEST(test_FindAnimalTrue);
    MY_RUN_TEST(test_FindAnimalFalse);
    MY_RUN_TEST(test_AddAnimalTrue);
    MY_RUN_TEST(test_AddAnimalFalse);
    MY_RUN_TEST(test_RemoveAnimalTrue);
    MY_RUN_TEST(test_RemoveAnimalFalse);

    UnityUnregisterSetupTearDown();
}
