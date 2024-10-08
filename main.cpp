// Name: Mahnoor Shahid
// Date: September 20, 2024
// Assignment: Assignment 2 - Question 1
// Compiler: Replit
// Sources: CS-303 Lecture Slides & ChatGpt/Replit AI for debugging

#include <iostream>
#include "SingleLinkedList.h"
using namespace std;

int main() {
  Single_Linked_List<int> list;

  // inserting elements at the back
  list.push_back(1);
  list.push_back(2);
  list.push_back(3);
  cout << "List after push_back(1), push_back(2), push_back(3):\n";
  cout << "Front: " << list.front() << ", Back: " << list.back()
       << ", Size: " << list.size() << endl;

  // inserting elements at the front
  list.push_front(4);
  cout << "\nAfter push_front(4):\n";
  cout << "Front: " << list.front() << ", Back: " << list.back()
       << ", Size: " << list.size() << endl;

  // inserting element at a certain index for example here is at index 4
  list.insert(4, 20);
  cout << "\nAfter insert(4, 20):\n";
  cout << "Front: " << list.front() << ", Back: " << list.back()
       << ", Size: " << list.size() << endl;

  // finding an element
  size_t index = list.find(6);
  if (index != list.size()) {
    cout << "\nElement found at index: " << index << endl;
  } else {
    cout << "\nElement not found." << endl;
  }

  // removing element at index 4
  if (list.remove(4)) {
    cout << "\nAfter removing element at index 4:\n";
    cout << "Front: " << list.front() << ", Back: " << list.back()
         << ", Size: " << list.size() << endl;
  } else {
    cout << "\nFailed to remove element at index 4." << endl;
  }

  // popping from front and back
  list.pop_front();
  cout << "\nAfter pop_front():\n";
  cout << "Front: " << list.front() << ", Back: " << list.back()
       << ", Size: " << list.size() << endl;

  list.pop_back();
  cout << "\nAfter pop_back():\n";
  cout << "Front: " << list.front() << ", Back: " << list.back()
       << ", Size: " << list.size() << endl;

  // checking if the list is empty
  if (list.empty()) {
    cout << "\nThe list is empty." << endl;
  } else {
    cout << "\nThe list is not empty." << endl;
  }

  return 0;
}