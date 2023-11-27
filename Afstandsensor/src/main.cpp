#include <Arduino.h>

#include "functions.h"

#define ANALOGPORTDISTANCE A0

typedef int (*functionPtr)(int*, int, double*);

int time = 0;
int analogValue = 0;
double distance = 0;

const int arraySize = 50;
int arrayMeasurements[arraySize] = {0};

void performFunction(functionPtr function, int* microseconds, int analogCounts, double* centimetres) {
  function(microseconds, analogCounts, centimetres);
  Serial.print(*centimetres);
  Serial.println(" cm");
  Serial.print("Execution time: ");
  Serial.print(*microseconds);
  Serial.println(" ms");
  Serial.println();
}

// Returns the moving average
int calculateMovingAverage() {
  int sum = 0;
  for(int i = 0; i < arraySize; i++) {
    sum += arrayMeasurements[i];
  }
  return sum/arraySize;
}

void setup() {
  // put your setup code here, to run once:
  pinMode(ANALOGPORTDISTANCE, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogValue = analogRead(ANALOGPORTDISTANCE);
  for (int i = 1; i < arraySize; i++) {
    arrayMeasurements[i - 1] = arrayMeasurements [i];
  }
  arrayMeasurements[arraySize - 1] = analogValue;

  Serial.println("Analog value: ");
  Serial.println(analogValue);
  Serial.println();

  functionPtr linear = linearFunction;
  functionPtr thirdDegreePolynomial = thirdDegreePolynomialFunction;
  functionPtr power = powerFunction;
  
  Serial.print("Distance according to linear function: ");
  performFunction(linear, &time, analogValue, &distance);

  Serial.print("Distance according to third degree polynomial function: ");
  performFunction(thirdDegreePolynomial, &time, analogValue, &distance);

  Serial.print("Distance according to power function: ");
  performFunction(power, &time, analogValue, &distance);

  Serial.println("Moving average (analog counts):");
  Serial.println(calculateMovingAverage());
  Serial.println();
  delay(1000);
}