#include "functions.h"
#include <fstream>
#include <iostream>
#include <utility>

using namespace std;

// function to read data from a file into an array
int *readFile(const char *filename, int &size) {
  ifstream infile(filename);
  if (!infile) {
    cout << "Error opening file."
         << endl;   // error message if file cannot be opened
    return nullptr; // returning nullptr to show that it failed
  }

  int capacity = 10; // the initial capacity of the array
  size = 0;
  int *array1 = new int[capacity]; // allocating initial array

  while (infile >> array1[size]) { // read int from file to array
    size++;
    if (size == capacity) { // checking if array needs to be resized
      // increase the array size
      capacity *= 2;                     // doubling the capacity
      int *newArray = new int[capacity]; // allocating a new larger array
      for (int i = 0; i < size;
           i++) { // copying old array elements to the new array
        newArray[i] = array1[i];
      }
      delete[] array1;   // freeing old array memory
      array1 = newArray; // updating array pointer to the new array
    }
  }

  infile.close(); // close the file
  return array1;  // returning the array
}

// function to check if an integer exists in the array, returns index if found, -1 otherwise
int findInteger(int *array1, int size, int num) {
  for (int i = 0; i < size; i++) { // iterating through the array
    if (array1[i] == num) {        // checking if current element matches num
      return i;                    // returnning index if found
    }
  }
  return -1; // returning -1 if num is not found
}

// function to modify the value at a given index and return the old and new value
pair<int, int> modifyInteger(int *array1, int index, int newVal) {
  int oldVal = array1[index]; // storing old value at index
  array1[index] = newVal;     // updating array element with new value
  return {oldVal, newVal};    // returning a pair of old and new values
}

// function to add a new integer to the end of the array
int *addInteger(int *array1, int &size, int newVal) {
  int *newArray = new int[size + 1]; // allocating new array with additional space
  for (int i = 0; i < size; i++) {   // copying old array elements to new array
    newArray[i] = array1[i];
  }
  newArray[size] = newVal; // adding the new value to the end of the new array
  size++;                  // increaseing the size of the array
  delete[] array1;         // freeing old array memory
  return newArray;         // returning pointer to the new array
}

// function to remove an integer from the array by index or set it to 0
int *removeIntegerOrSetZero(int *array1, int &size, int index, bool remove) {
  if (remove) { // cgheking if the element should be removed
    int *newArray =
        new int[size - 1]; // allocating new array with one less element
    for (int i = 0, j = 0; i < size;
         i++) { // copying elements except the one at index
      if (i != index) {
        newArray[j++] = array1[i];
      }
    }
    size--;          // decreasing the size of the array
    delete[] array1; // freeing old array memory
    return newArray; // returning pointer to the new array
  } else {
    array1[index] = 0; // setting the element at index to 0
    return array1;     // returnning the original array
  }
}