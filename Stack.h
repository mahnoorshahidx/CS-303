#include <iostream>
#include <vector>
#pragma once

using namespace std;

class Stack {
private:
  // vector that stores the elements of the stack
  vector<int> stack;

public:
  // pushing an element onto the stack
  void push(int value) {
    stack.push_back(value); // adds the value to the end of the vector
  }

  // popping the top element from the stack
  void pop() {
    // first checking if the stack is not empty before popping
    if (!isEmpty()) {
      stack.pop_back(); // removes the last element from the vector
    } else {
      cout << "Stack is empty, cannot pop!"
           << endl; // if the stack is empty - error
    }
  }

  // checking if the stack is empty
  bool isEmpty() const {
    return stack
        .empty(); // returns true if the stack has no elements, false otherwise
  }

  // finding the top element of the stack
  int top() const {
    // checking if the stack is not empty before returning the top element
    if (!isEmpty()) {
      return stack.back(); // returns the last element in the vector
    } else {
      cout << "Stack is empty!" << endl; // if the stack is empty - error 
      return -1; 
    }
  }

  // finding the average value of the stack elements
  double average() const {
    // checking if the stack is not empty before calculating the average
    if (stack.empty()) {
      cout << "Stack is empty, cannot calculate average!" << endl;
      return 0; 
    }

    int sum = 0; // varible to store the sum of all stack elements
    // summing up all the elements in the stack
    for (int value : stack) {
      sum += value;
    }
    // returning the average by dividing the sum by the number of elements
    return static_cast<double>(sum) / stack.size();
  }

  // displayinf the stack elements
  void display() const {
    // cechking if the stack is empty before attempting to display
    if (stack.empty()) {
      cout << "Stack is empty!" << endl;
      return;
    }

    cout << "Stack elements: ";
    // iterate over the stack and print each element
    for (int value : stack) {
      cout << value << " "; // dosplay each element
    }
    cout << endl;
  }
};