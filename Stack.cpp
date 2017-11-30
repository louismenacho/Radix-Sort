#include <fstream>
#include "RadixSort.h"

using namespace std;

Stack::Stack() {
    top = NULL;
}

void Stack::push(string data) {
    Node *newItem = new Node(data);
    newItem->next = top;
    top = newItem;
}

Node* Stack::pop() {
    if (isEmpty()) {
        //cout << "Stack is empty";
        return nullptr;
    }
    else {

        Node *oldTop = new Node(top->data);
        top = top->next;
        return oldTop;
    }
}

bool Stack::isEmpty() {
    if (top == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

void Stack::printStack(ofstream &outfile) {
    if(!isEmpty()) {
        outfile << "Stack" << endl;
        outfile << "Top";
        Node *current = top;
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