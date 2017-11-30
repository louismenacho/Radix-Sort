#include "RadixSort.h"
using namespace std;

Node::Node(string data) {
this->data = data;
next = NULL;
}

Node::~Node() {
    data = "";
    next = NULL;
    delete this;
}