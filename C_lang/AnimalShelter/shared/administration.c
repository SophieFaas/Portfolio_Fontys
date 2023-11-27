#include "administration.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// leave resource_detector.h as last include!
#include "resource_detector.h"

// Add animal.

// De nieuwe animal voegen we toe aan de animalArray. 
// Er komt dan eentje bij de newNumberOfAnimalsPresent bij, en die gaat naar de numberOfAnimalsPresent.
int addAnimal(
            const Animal* animalPtr, Animal* animalArray,
            size_t animalArrayLength, size_t numberOfAnimalsPresent,
            size_t* newNumberOfAnimalsPresent)
{
    // Mag niet groter zijn
    if (numberOfAnimalsPresent >= animalArrayLength)
    {
        return -1;
    }

    if (animalPtr == NULL || animalArray == NULL || newNumberOfAnimalsPresent == NULL)
    {
        return -1;
    }
    
    // Id mag maar 1x in voor komen.
    Animal animalFound = {0, Cat, Female, 1, {1, 1, 2000}};
    if (findAnimalById(animalPtr->Id, animalArray, numberOfAnimalsPresent, &animalFound))
    {
        return -1;
    }
    

    // animalPrt -+-> animalArray
    animalArray[numberOfAnimalsPresent] = *animalPtr;

    // newNumberOfAnimalsPresent ++
    *newNumberOfAnimalsPresent = numberOfAnimalsPresent + 1;
    
    return 0;
}

// Remove animal.
int removeAnimal(
            int animalId, Animal* animalArray,
            size_t numberOfAnimalsPresent,
            size_t* newNumberOfAnimalsPresent)
{
    if (animalArray == NULL || newNumberOfAnimalsPresent == NULL)
    {
        return -1;
    }

    // Doorzoek de array
    for (int i = 0; i < numberOfAnimalsPresent; i++)
    {
        if (animalId == animalArray[i].Id)
        {
            animalArray[i] = animalArray[numberOfAnimalsPresent - 1];
            *newNumberOfAnimalsPresent = numberOfAnimalsPresent -1;
            return 1;
        }
    }
    
    return 0;
}

// Find animal.
// Gebruik een for-loop met if else.
// Eerst ga je alle animals bekijken. Dan zoek je de juiste animalId. En die kopieer je naar je pointer.
int findAnimalById(
            int animalId, const Animal* animalArray,
            size_t numberOfAnimalsPresent, Animal* animalPtr)
{
    // Error
    if (animalArray == NULL || numberOfAnimalsPresent == NULL || animalPtr == NULL)
    {
        return -1;
    }
    

    // for loop
    for (int i = 0; i < numberOfAnimalsPresent; i++)
    {
        if (animalId == animalArray[i].Id)
        {
            *animalPtr = animalArray[i];
            return 1;
        }
    }
    return 0;
}


/*-------------------------------------------------------------------------------*/
// Sort animal

// Sort animal age.
int sortAnimalsByAge(Animal* animalArray, size_t numberOfAnimalsPresent)
{
    return 0;
}

// Sort animal year found.
int sortAnimalsByYearFound(
            Animal* animalArray, size_t numberOfAnimalsPresent)
{
    return 0;
}

// Sort animal sex.
int sortAnimalsBySex(Animal* animalArray, size_t numberOfAnimalsPresent)
{
    return 0;
}
