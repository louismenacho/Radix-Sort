#include <fstream>
#include "RadixSort.h"

Queue::Queue() {
    Node *dummy = new Node("-9999");
    head = dummy;
    tail = dummy;
}

void Queue::addTail(Node *node) {
    if(head->next == NULL){
        head->next = node;
        tail = node;
    }
    else {
        tail->next = node;
        tail = tail->next;
    }
}

Node* Queue::deleteHead() {
    Node *oldHead = head->next;
    if (oldHead->next == NULL) {
        string oldData = oldHead->data;
        head->next = NULL;
        return new Node(oldData);
    }
    else {
        string oldData = oldHead->data;
        head->next = oldHead->next;
        return new Node(oldData);
    }
}

bool Queue::isEmpty() {
    if(head->next == NULL){
        return true;
    }
    else {
        return false;
    }
}

void Queue::printQueue(ofstream &outfile) {
    if(!isEmpty()) {
        outfile << "Head";
        Node *current = head;
        int count = 0;
        while (current != NULL) {
                outfile << "-->(" << current->data << ",";
                if(current->next!=NULL) {
                    outfile << current->next->data << ")";
                }
                else{
                    outfile << "-1)";
                }
                current = current->next;
        }
    }
    outfile << endl;
}
