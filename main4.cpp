// Name: Mahnoor Shahid
// Date: November 1, 2024
// Assignment: Assignment 3 - Question 2
// Compiler: Replit
// Sources: CS-303 Lecture Slides - (Lecture 9: Slide 30) & ReplitAI for debugging

#include "linearsearch.h"
using namespace std;

// this is the same code from lecture 9 slide 30, just modified it to find the last occurence of a target in a vector

template <typename Item_Type>

int linear_search_last(const vector<Item_Type> &items, const Item_Type &target,
                       int pos_last) {
  // base case - if pos_last is less than 0, we searched the entire vector without finding the target
  if (pos_last < 0) {
      cout << "Error: Target not found in the vector." << endl;
      return -1;  // target not found
  }

  // cheking if the current position holds the target item
  if (target == items[pos_last])
    return pos_last; // target found return index

  // recursive call - check the previous element
  return linear_search_last(items, target, pos_last - 1);
}

int main() {
  vector<int> items = {1, 2, 3, 4, 2, 5, 6, 2};
  
  // target  to search for
  int target = 2;
  
  // find the last occurrence of the target in the vector
  int index = linear_search_last(items, target, items.size() - 1);

  // if the target was found, print the index
  if (index != -1) {
      cout << "The last occurrence of " << target << " is at index: " << index << endl;
  }

  return 0;
}
