#include <iostream>
#include <stdexcept>

using namespace std;

// this is a template class and it is single-linked list that holds items of type Item_Type
template <typename Item_Type> class Single_Linked_List {
private:
  // using a struct to reprsent a node in the linked list
  struct Node {
    Item_Type data; // data held by node
    Node *next;     // pointer to the next node

    // constructor to initialize a node with data and set the next pointer to nullptr
    Node(const Item_Type &item) : data(item), next(nullptr) {}
  };

  Node *head;       // pointer to first node in the list (head)
  Node *tail;       // pointer to last node in the list (tail)
  size_t num_items; // num of items currently in the list

public:
  // constructor: initilzes an empty linked list with head and tail as nullptr and no items
  Single_Linked_List() : head(nullptr), tail(nullptr), num_items(0) {}

  // dsstructor: deallocates memory used by the list by removing all nodes
  ~Single_Linked_List() {
    while (!empty()) {
      pop_front(); 
    }
  }

  // pushing an item to the front of the list
  void push_front(const Item_Type &item) {
    Node *new_node = new Node(item); // creating a new node
    new_node->next = head;           // linking the new node to the current head
    head = new_node;                 // updating head to the new node
    if (num_items == 0) { // if the list was empty, update tail to the new node
      tail = head;
    }
    num_items++; // incremening the size of the list
  }

  // pushing an item to the back of the list
  void push_back(const Item_Type &item) {
    Node *new_node = new Node(item); // creating a new node
    if (empty()) { // if the list is empty, set both head and tail to the new node
      head = tail = new_node;
    } else {
      tail->next = new_node; // if not, link the current tail to the new node
      tail = new_node;       // updating tail to the new node
    }
    num_items++; // incrementing the size of the list
  }

  // popping the item from the front of the list
  void pop_front() {
    if (!empty()) {
      Node *old_head = head; // save the current head
      head = head->next;     // move head to the next node
      delete old_head;       // deleting the old head node
      num_items--;           // decremtngin the size of the list
      if (num_items == 0) {  // if the list is now empty, set tail to nullptr
        tail = nullptr;
      }
    }
  }

  // poppping the item from the back of the list
  void pop_back() {
    if (!empty()) {
      if (num_items == 1) { // if there is only one node, remove it
        delete head;
        head = tail = nullptr;
      } else {
        Node *temp = head;
        while (temp->next !=
               tail) { // traversing the list to find the node before the tail
          temp = temp->next;
        }
        delete tail;          // deleting the tail node
        tail = temp;          // updating tail to the previous node
        tail->next = nullptr; // setting the next pointer of the new tail to nullptr
      }
      num_items--; // decrmenting the size of the list
    }
  }

  // retunring the first item in the list
  Item_Type &front() const {
    if (!empty()) {
      return head->data; // return the data of the head node
    }
    throw std::runtime_error(
        "List is empty."); // throwing an error if the list is empty
  }

  // returning the last item in the list
  Item_Type &back() const {
    if (!empty()) {
      return tail->data; // returning the data of the tail node
    }
    throw std::runtime_error(
        "List is empty."); // thrwoing an error if the list is empty
  }

  // checking if the list is empty
  bool empty() const {
    return num_items == 0; // return true if there are no items in the list
  }

  // inserting an item at a specified index
  void insert(size_t index, const Item_Type &item) {
    if (index >= num_items) {
      push_back(item); // if index is out of bounds, add the item at the end
    } else if (index == 0) {
      push_front(item); // if index is 0, add the item at the front
    } else {
      Node *new_node = new Node(item); // creating a new node
      Node *temp = head;
      for (size_t i = 0; i < index - 1;
           ++i) { // traversing to the node before the target index
        temp = temp->next;
      }
      new_node->next = temp->next; // linking the new node to the next node
      temp->next = new_node;       // inserting the new node in its position
      num_items++;                 // incremnting the size of the list
    }
  }

  // remvoing an item at a specified index
  bool remove(size_t index) {
    if (index >= num_items) {
      return false; // if the index is out of bounds, return false
    }
    if (index == 0) {
      pop_front(); // if the index is 0, remove the first item
    } else {
      Node *temp = head;
      for (size_t i = 0; i < index - 1;
           ++i) { // traversing to the node before the target index
        temp = temp->next;
      }
      Node *node_to_remove = temp->next; // getting the node to remove
      temp->next =
          node_to_remove->next; // updating the link to bypass the removed node
      if (node_to_remove ==
          tail) { // if the removed node was the tail, update the tail
        tail = temp;
      }
      delete node_to_remove; // delting the node
      num_items--;           // decrementing the size of the list
    }
    return true;
  }

  // finding the first occurrence of an item in the list
  size_t find(const Item_Type &item) const {
    Node *temp = head;
    size_t index = 0;
    while (temp != nullptr) {   // traversing the list
      if (temp->data == item) { // if the item is found, return its index
        return index;
      }
      temp = temp->next;
      index++;
    }
    return num_items; // if it is not found, return the size of the list (which means it wasnt found)
  }

  // returning the number of items in the list
  size_t size() const {
    return num_items; // returning the number of items
  }
};