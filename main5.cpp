// Name: Mahnoor Shahid
// Date: November 5, 2024
// Assignment: Assignment 3 - Question 3
// Compiler: Replit
// Sources: CS-303 Lecture Slides - lecture 10 slide 138 & Replit AI for debugging

#include <iostream>
#include "insertionsort.h"

//same code concept from lecture 10 slide 138 but modified to be used with linked list

void insertion_sort(Node*& head) {
    // checking if the list is empty or has only one element
    if (head == nullptr || head->next == nullptr) {
        return;  // you dont need to sort if the list is empty or has only one element
    }

    Node* sorted = nullptr;  // ptr to the head of the sorted part of the list
    Node* current = head;    // ptr to traverse the orig list

    // tjhis loop traverses the original list until we reach the end
    while (current != nullptr) {
        Node* nextNode = current->next; 

        // inserting the current node in the right position in the sorted part of the list
        if (sorted == nullptr || sorted->data >= current->data) {
            // if sorted is empty or the current nods data is less than or equal to the head of the sorted list, insert current at the beginning
            current->next = sorted;  // point currents next to the current sorted list
            sorted = current;        // updte sorted to be the new head
        } 
        
        else {
            // find the correct position to insert current in the sorted list
            Node* temp = sorted; // starting at the head of the sorted list
            // traversing sorted until we find a node with data greater than current
            while (temp->next != nullptr && temp->next->data < current->data) {
                temp = temp->next;  // move temp to the next node
            }
            // inserting current in the sorted part
            current->next = temp->next; // point currents next to the next node in sorted
            temp->next = current;        // link temps next to the current node
        }

        // move to the next node in the orig list
        current = nextNode; // here we advanbce to the next node that was saved earlier in the code
    }

    // after we go thorugh all nodes, update head to point to the new sorted list
    head = sorted;
}

void print_list(Node* head) {
    Node* temp = head;
    // traversing the list and print each nods data
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // creating a linked list that is not in order
    Node* head = new Node(5);
    head->next = new Node(4);
    head->next->next = new Node(3);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);

    // printing how the original linked list looks like
    cout << "Original List (before sorting): ";
    print_list(head);

    // sorting the linked list so it should be ascending order
    insertion_sort(head);

    // printing the sorted linked list
    cout << "\nSorted List (after sorting): ";
    print_list(head);

    return 0;
}
