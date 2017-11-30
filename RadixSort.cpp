#include <fstream>
#include "RadixSort.h"

RadixSort::RadixSort(Stack stack, int max) {
    //Step 2
    totalDigit = calcTotalDigit(max);
    currentDigit = 0;
    currentTable = 0;
    hashTable[0] = new HashTable();
    hashTable[1] = new HashTable();
    this->stack = stack;
}

void RadixSort::sort(ofstream &outfile){
    //Step 3
    while(!stack.isEmpty()){

        Node *node = stack.pop(); //pop from the stack
        int digit = getDigit(node); //get the currentDigit from the data in the node
        index = hash(digit); //passing the digit to the hash function to get the index
        hashTable[currentTable]->table[index]->addTail(node);
    }
    //print current Table
    hashTable[currentTable]->printTable(outfile);

    //Step 4
    currentDigit++;
    currentTable = 1;
    previousTable = 0;
    currentQueue = 0;

    //print previous Table
    hashTable[previousTable]->printTable(outfile);
    //Repeat here as per Step 7
    while(currentDigit < totalDigit) {
        //Step 5
        while (currentQueue < hashTable[previousTable]->size) {
            while (!hashTable[previousTable]->table[currentQueue]->isEmpty()) {

                Node *node = hashTable[previousTable]->table[currentQueue]->deleteHead();
                int digit = getDigit(node);
                index = hash(digit);
                hashTable[currentTable]->table[index]->addTail(node);
            }
            currentQueue++;
        }
        //Step 6
        swapTables();
        currentQueue = 0;
        currentDigit++;
    }
    //Step 8
    swapTables();
    outfile << "Final ";
    hashTable[currentTable]->printTable(outfile);
}

void RadixSort::swapTables(){
    int temp = currentTable;
    currentTable = previousTable;
    previousTable = temp;
}

int RadixSort::hash(int x) {
    return x;
}

int RadixSort::calcTotalDigit(int max) {
    int digits = 0;
    while (max > 0) {
        max = max/10;
        digits++;
    }
    return digits;
}

int RadixSort::getDigit(Node *node){
    string num = node->data;
    int digit;
    int number = atoi(num.c_str()); //convert string to int
    int mod = 10;
    int div;

    for(int i = currentDigit; i > 0 ; i--){
        mod *= 10;
    }
    div = mod/10;

    digit = (number%mod)/div;

    return digit;
}






