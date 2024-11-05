#include <iostream>
#include <vector>

using namespace std;

template <typename Item_Type>

// Searches for the last occurrence of a specified target in vector
int linear_search_last(const vector<Item_Type> &items, const Item_Type &target, int pos_last);
//PRE: items is a vector of Item_Type objects, target is the Item_Type object to be found, and pos_last
//POST: returns the position of the last occurrence of target in items
