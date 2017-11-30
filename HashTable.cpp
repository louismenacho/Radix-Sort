#include <fstream>
#include "RadixSort.h"

HashTable::HashTable() {
    size = 10;
    *table = new Queue[size];
    for(int i = 0; i < size; i++){
        table[i] = new Queue();
    }
}

void HashTable::printTable(ofstream &outfile) {
    outfile << "HashTable" << endl;
    for(int i = 0; i < size; i++){
        outfile << i << ": ";
        table[i]->printQueue(outfile);
    }
    outfile << endl;
}
