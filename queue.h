#include <iostream>
#include <stdexcept> 

using namespace std;

template <typename T>
class Queue {
private:
  // this is node structure for linked list
  struct Node {
    T data;                                   // data of the node
    Node *next;                               // pointer to the next node
    Node(T val) : data(val), next(nullptr) {} // constructor
  };

  Node *frontNode; // a ptr to the front of the queue
  Node *rearNode;  // a ptr to the rear of the queue
  int counter;     // this counter is used to keep track of the size of the queue

public:
  // constructor
  Queue() : frontNode(nullptr), rearNode(nullptr), counter(0) {}

  // destructor
  ~Queue() {
    while (!empty()) {
      pop();
    }
  }

  // adding an element at the rear of the queue
  void push(T value) {
    // creating a new node with the provided value
    Node *newNode = new Node(value);
    // checking if the queue already has elements
    if (rearNode) {
      // it does, link the current rear node to the new node
      rearNode->next = newNode;
    } else {
      // it doesn't, set the new node as the front node
      frontNode = newNode;
    }
    // updating the rear node to be the new node
    rearNode = newNode;
    // incrementing the counter to show the new size of the queue
    counter++;
  }

  // removing an element from the front of the queue
  void pop() {
    // checking if the queue is empty
    if (empty()) {
      cout << "Queue is empty\n";
      return;
    }
    // storing the current front node in a temp pointer
    Node *temp = frontNode;
    // moving the front pointer to the next node in the queue
    frontNode = frontNode->next;
    // deleting the old front node
    delete temp;
    // decrement the counter because we removed an element
    counter--;
    // if the queue is empty after the removal, resetting the rear pointer to nullptr
    if (counter == 0) {
      rearNode = nullptr;
    }
  }

  // returning the element at the front of the queue
  T front() const {
    // checking if the queue is not empty
    if (!empty()) {
      // return the data of the front node
      return frontNode->data;
    }
    // if queue is empty, throw error
    throw runtime_error("Queue is empty");
  }

  // return the size of the queue
  int size() const {
    return counter;
  } // counter was used to keep track of the size

  // checking if the queue is empty
  bool empty() const { return counter == 0; }

  // moving the front element to the rear of the queue
  void move_to_rear() {
    if (size() > 1) { // only perform this function if there is more than one element in queue
      T frontElement = front(); // getting the front element
      pop();                    // removing the front element
      push(frontElement);       // pushing the front element to the rear
    }
  }

  // displaying all elements of the queue
  void display() {
    int s = size(); // saving the original size
    for (int i = 0; i < s; ++i) {
      // get the front element
      T val = front();
      cout << val << " ";
      // remove the front element
      pop();
      // re-adding the removed element to the rear of the queue
      push(val);
    }
    cout << endl;
  }
};
