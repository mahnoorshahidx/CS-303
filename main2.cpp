// Name: Mahnoor Shahid
// Date: September 22, 2024
// Assignment: Assignment 2 - Question 1
// Compiler: Replit
// Sources: CS-303 Lecture Slides & ChatGpt/Replit AI for debugging

#include "Stack.h"
#include <iostream>

int main() {
  // creating a stack object
  Stack s;

  // checking if the stack is empty
  if (s.isEmpty()) {
    cout << "Stack is empty." << endl;
  } else {
    cout << "Stack is not empty." << endl;
  }

  cout << "\n";

  // inserting integer values onto the stack
  s.push(2);
  s.push(4);
  s.push(6);

  // displaying how the stack looks after addding the integers
  s.display();

  cout << "\n";

  // removing an element from the stack
  s.pop();

  // displaying how the stack looks after removing an element
  s.display();

  cout << "\n";

  // finding the top of the stack
  cout << "Top of the stack: " << s.top() << endl;

  cout << "\n";

  // finding the average value of the stack elements
  cout << "Average value of stack elements: " << s.average() << endl;

  cout << "\n";

  // checking if the stack is empty
  if (s.isEmpty()) {
    cout << "Stack is empty." << endl;
  } else {
    cout << "Stack is not empty." << endl;
  }

  return 0;
}