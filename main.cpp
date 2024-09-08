// Name: Mahnoor Shahid
// Date: September 1, 2024
// Assignment: Assignment 1 - Question 1
// Compiler: Replit
// Sources: CS-303 Lecture Slides & ChatGpt/Replit AI for debugging.

#include "functions.h"
#include <iostream>

using namespace std;

int main() {
  const char *filename = "input.txt";
  int size = 0; 
  //read int from file to array
  int *array1 = readFile(filename, size);

  //check to see if file is read successfully
  if (array1 == nullptr) {
    return 1;
  }

  // 1. checking if a specific number exists
  int numberToFind;
  cout << "Enter a number to find: ";
  cin >> numberToFind;
  //find the number
  int index = findInteger(array1, size, numberToFind);
  if (index != -1) {
    //number found
    cout << "Number " << numberToFind << " found at index " << index << "."
         << endl;
  } else {
    //number not found
    cout << "Number " << numberToFind << " not found in the array." << endl;
  }

  cout << "\n";

  // 2. modifying the value at a given index
  int modifyIndex;
  cout << "Enter the index to modify: ";
  //index to modify
  cin >> modifyIndex;
  int newValue;
  cout << "Enter the new value: ";
  //new value to set
  cin >> newValue;
  auto [oldVal, modifiedValue] = modifyInteger(array1, modifyIndex, newValue);
  //modify the integer
  cout << "Old value at index " << modifyIndex << " was " << oldVal << ". "
       << "The new value is " << modifiedValue << "." << endl;

  cout << "\n";

  // 3. adding a new integer to the end of the array
  int newNumber;
  cout << "Enter a new number to add to the array: ";
  //new number to add
  cin >> newNumber;
  array1 = addInteger(array1, size, newNumber);
  //add the number to the array
  cout << "Added new number " << newNumber
       << " to the array. The new size is now " << size << "." << endl;

  cout << "\n";

  // 4. removing or setting to 0 an integer at a given index
  int removeIndex;
  cout << "Enter the index to remove or set to 0: ";
  //index to remove or set to 0
  cin >> removeIndex;
  bool remove;
  cout << "Enter 1 to remove or 0 to set to 0: ";
  //remove or set to 0 by either choosing 1 or 0
  cin >> remove;
  array1 = removeIntegerOrSetZero(array1, size, removeIndex, remove);
  if (remove) {
    cout << "After removing, the array size is now " << size << "." << endl;
  } else {
    cout << "After setting to 0, the array size is " << size << "." << endl;
  }

  // cleaning up 
  delete[] array1;

  return 0;
}