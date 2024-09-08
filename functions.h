#pragma once 
#include <iostream>
#include <utility> //to use pair method

using namespace std;

//PRE stands for preconditions which mean -> what variables the function takes 
//POST stands for postconditions which mean -> what the function is intended to do

int* readFile(const char* filename, int& size);
//PRE: The filename is a valid txt file that contains int & reference to size is available to store num of int read.
//POST: Read int from file into array, update size with num of int, & return pointer to array. 

int findInteger(int* array1, int size, int num);
//PRE: Array1 is a valid array, size is the size of array1, num is the number to find.
//POST: Returns the index of num in array1, -1 if not found.

pair<int, int> modifyInteger(int* array1, int size, int index, int newVal);
//PRE: Array1 is a valid array, index is within bounds, size is the size of array & newVal is to replace current value at index. 
//POST: Replaces the int at the index with the new value & returns a pair of the old value & the new value.

int* addInteger(int* array1, int &size, int newVal);
//PRE: Array1 is a valid array, size is the size of array1, newVal is the new value to add.
//POST: Adds the new value to the end of the array & returns a pointer to the new array.

int* removeIntegerOrSetZero(int* array1, int &size, int index, bool remove);
//PRE: Array1 is a valid array, size is the size of array1, index is within bounds, & remove indicates whether to remove or set to 0.
//POST: If remove is true, removes the int at the index & returns a pointer to the new array. If remove is false, set the element at the index to 0. 

bool isDuplicate(int* array, int size, int newNumber);
//PRE: Array is a valid array, size is the size of array, newNumber is the number to check for.
//POST: Returns true if newNumber is a duplicate, false otherwise.