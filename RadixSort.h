#ifndef RADIXSORT_H
#define RADIXSORT_H
#include <iostream>
using namespace std;

class Node {
private:
    friend class Stack;
    friend class Queue;
    friend class RadixSort;
    string data;
    Node *next;
public:
    Node(string data);
    ~Node();
};

class Stack {
private:
    Node *top;
public:
    Stack();
    void push(string data);
    Node* pop();
    bool isEmpty();
    void printStack(ofstream& outfile);
};

class Queue {
    friend class HashTable;
private:
    Node *head;
    Node *tail;
public:
    Queue();
    void addTail(Node *node);
    Node* deleteHead();
    bool isEmpty();
    void printQueue(ofstream &outfile);

};

class HashTable {
    friend class RadixSort;
private:
    int size;
    Queue *table[];
public:
    HashTable();
    void printTable(ofstream &outfile);
};

class RadixSort {
private:
    int currentTable;
    int previousTable;
    int totalDigit;
    int currentDigit;
    int currentQueue;
    int index;
    HashTable *hashTable[2];
    Stack stack;
public:
    RadixSort(Stack stack, int max);
    void swapTables();
    int calcTotalDigit(int max);
    int hash(int x);
    void sort(ofstream &outfile);

    int getDigit(Node *node);
};

#endif
