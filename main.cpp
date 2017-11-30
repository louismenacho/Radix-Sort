//Louis Menacho
#include <fstream>
#include "RadixSort.h"

using namespace std;

int main(int argc, char *argv[]) {
    //Step 0
    ifstream infile(argv[1]);
    Stack stack;
    string number;
    int max = 0;

    //Step 1
    while (infile >> number) {
        stack.push(number);
        int num = atoi(number.c_str()); //convert number string to int
        if(num > max){
            max = num;
        }
    }

    ofstream outfile;
    outfile.open(argv[2]);
    stack.printStack(outfile);
    outfile << endl;

    RadixSort *radixSort = new RadixSort(stack, max);
    radixSort->sort(outfile);

    outfile.close();

    return 0;
}

