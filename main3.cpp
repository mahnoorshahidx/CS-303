// Name: Mahnoor Shahid
// Date: October 28, 2024
// Assignment: Assignment 3 - Question 1
// Compiler: Replit
// Sources: CS-303 Lecture Slides & ChatGpt/Replit AI for debugging

#include "queue.h"

int main() {
  // a) instantite the queue with integers + push 10 values into queue
  Queue<int> queue;
  for (int i = 1; i <= 10; ++i) {
    queue.push(i);
  }

  // b) displaying these elements that were pushed
  cout << "The current elements in queue: ";
  queue.display();

  // c) moving the front element to the rear + displaying the updtd queue
  queue.move_to_rear();
  cout << "\nThe queue after moving the front element to rear (first time): ";
  queue.display();

  // doing it again to show that the element is moved to the rear
  queue.move_to_rear();
  cout << "\nThe queue after moving the front element to rear (second time): ";
  queue.display();

  // one final time to show the function is working properly
  queue.move_to_rear();
  cout << "\nThe queue after moving the front element to rear (third time): ";
  queue.display();

  return 0;
}
