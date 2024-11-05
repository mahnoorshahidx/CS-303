#include <iostream>

using namespace std;

// node struc for singly linked list
struct Node {
    int data;
    Node* next;

    // constructor to initialize the node with a value
    Node(int x) : data(x), next(nullptr) {}
};

void insertion_sort(Node*& head);
//PRE: head is a pointer to the head of the linked list
//POST: the linked list is sorted in ascending order

void print_list(Node* head);
//PRE: head is a pointer to the head of the linked list
//POST: the linked list is printed to the screen
