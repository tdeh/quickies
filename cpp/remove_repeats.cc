// Function to remove repeats from a linked list

#include <cassert>
#include <iostream>


struct Node {
    Node* next;
    int value;
};


// Function to remove repeats from a linked list
void RemoveRepeats(Node* head) {
    for (Node* itr = head; itr->next != nullptr; itr = itr->next) {
        Node* runner = itr->next;
        while (runner != nullptr && runner->value == itr->value) {
            runner = runner->next;
        }
        itr->next = runner;
    }
}


int main() {
    return 0;
}
