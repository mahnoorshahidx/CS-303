// Name: Mahnoor Shahid
// Date: September 1, 2024
// Assignment: Assignment 1 - Question 2
// Compiler: Replit
// Sources: CS-303 Lecture Slides & ChatGpt/Replit AI for debugging.

#include "functions.h"
#include <iostream>
#include <limits>

using namespace std;

int main() {
  const char *filename = "input.txt";
  int size = 0;
  // read int from file to array
  int *array1 = readFile(filename, size);

  // check to see if file is read successfully
  if (array1 == nullptr) {
    return 1;
  }

  // 1. checking if a specific number exists
  int numberToFind;
  cout << "Enter a number to find: ";
  cin >> numberToFind;
  // find the number
  int index = findInteger(array1, size, numberToFind);
  if (index != -1) {
    // number found
    cout << "Number " << numberToFind << " found at index " << index << "."
         << endl;
  } else {
    // number not found
    cout << "Number " << numberToFind << " not found in the array." << endl;
  }

  cout << "\n";

  // 2. modifying the value at a given index
  int modifyIndex;
  int newValue;

  // continuously asking the user to enter a valid index
  while (true) {
    cout << "Enter the index to modify (0 to " << size - 1 << "): ";
    cin >> modifyIndex;

    // checking if the index is valid before proceeding
    if (modifyIndex >= 0 && modifyIndex < size) {
      break; // exiting the loop if a valid index is entered
    } else {
      cout << "Invalid index. Please enter a valid index between 0 and "
           << size - 1 << "." << endl;
    }
  }

  // continuously asking the user to enter a valid new value
  while (true) {
    cout << "Enter the new value: ";
    cin >> newValue;

    // checking if input is a valid integer
    if (cin.fail()) {
      cin.clear(); // clear the error flag
      cin.ignore(numeric_limits<streamsize>::max(),
                 '\n'); // discard invalid input
      cout << "Invalid input. Please enter a valid integer." << endl;
      continue;
    }
    break; // valid input, break the loop
  }

  // modifying the integer at the index
  auto [oldVal, modifiedValue] =
      modifyInteger(array1, size, modifyIndex, newValue);

  // showing the old and new values
  cout << "Old value at index " << modifyIndex << " was " << oldVal << ". "
       << "The new value is " << modifiedValue << "." << endl;

  cout << "\n";

  // 3. adding a new integer to the end of the array
  int newNumber;

  while (true) {
    cout << "Enter a new number to add to the array: ";
    cin >> newNumber;

    // checking if input is a valid integer
    if (cin.fail()) {
      cin.clear(); // clear the error flag
      cin.ignore(numeric_limits<streamsize>::max(),
                 '\n'); // discard invalid input
      cout << "Invalid input. Please enter a valid integer." << endl;
    } else {
      // checking for duplicate values
      if (isDuplicate(array1, size, newNumber)) {
        cout << "The number " << newNumber
             << " already exists in the array. Please enter a different number."
             << endl;
      } else {
        break; // it is a valid input & not a duplicate, exit the loop
      }
    }
  }

  // adding the number to the array
  array1 = addInteger(array1, size, newNumber);

  // showing the result
  cout << "Added new number " << newNumber
       << " to the array. The new size is now " << size << "." << endl;
  cout << "\n";
  delete[] array1;

  // 4. removing or setting to 0 an integer at a given index
  int removeIndex;
  cout << "Enter the index to remove or set to 0: ";
  // index to remove or set to 0
  cin >> removeIndex;
  bool remove;
  cout << "Enter 1 to remove or 0 to set to 0: ";
  // remove or set to 0 by either choosing 1 or 0
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