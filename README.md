
Radix Sort specificaions: 
			
(A) Input: a text file contains a list of positive integers. 
       
**** The name of the input file should be given in argv[1].
**** Although the input is a list of positive integers, it would be easier to do your radix sort if you treat each integer as a string. (In C++ you can read a number as a string and read a string at a time)

(B) Output: a text file contains the sorted data in the input file.
**** The name of the output file should be given in argv[2]

(C)Data structure:
1) A node class with two fields: 
- Data (string)
- Next (a node pointer to the next node, initialize to NULL)
- Constructor to create a new node of a given data and next should be null.
- distractor to free a node
	
	2) A linked list Stack class:
- Top // a node pointer 
- Constructor // to create a new stack and top initialize to null.
	- Push // push a node on the top of stack
	- Pop // pop a node from the top of stack
	- isEmpty // return 1 if the stack is empty, return 0 otherwise.
	- printStack

	3) A linked list Queue class
	- head // a node pointer 
	- tail // a node pointer 
- Constructor 
// to create a new queue with a dummy node, initially, head and tail point to the dummy node.
			
	- addTail 		// add a node at the tail of the queue
	- deleteHead 	// delter a node from the head of queue
	- isEmpty 		// return 1 if the stack is empty, return 0 otherwise.
	- printQueue
		
	4) A C++ struct with two fields: 
	- head (a node pointer)
	- tail (a node pointer)
  
	5) A hashTable class:
- size // is 10
- 1-D array (size) of struct as defined in the above;
- constructor that creates a hashTable[size] and for each hashTable[i], create a queue, where hashTable[i].head and hashTable[i].tail are pointed to the same queue’s dummy node .
      - printTable // print each queue in the hashTable
 
    
	5) A RadixSort class:
		- currentTable
		- previousTable
		- totalDigit
		- index
	 	- two hashTables hashTable[0] and hashTable[1]
 		- a hash function: Hash(x) = x, 	
		- include all the methods you need for the Radix sort.

Algorithm steps:

Step 0: - open the input file
	   - create a new stack
	   
Step 1: - read a data from the input file
        - keep track of the largest number in the data  
	  - create a new node for the data
	  - push the new node onto the stack
	  - repeat step 1 until file is empty
	  - print the stack
          
Step 2: - totalDigit <-- determine the number of digits in the largest input data
        - currentDigit <-- 0
        - currentTable <-- 0

Step 3: 
- node <-- pop from the stack
- digit <-- get the currentDigit from the data in the node
- index <-- passing the digit to the hash function to get the index
- call addTail to add the node at the tail of the queue at currentTable, hashTable[currentTable][index]
- repeat steps 3 until the stack is empty
- Print currentTable

Step 4: 
- currentDigit++
- currentTable <-- 1
- previousTable <-- 0
- currentQueue <-- 0

Step 5:
	5.0 print previousTable
 
5.1 node <-- call deleteHead from the currentQueue in the previousTable,
			hashTable[previousTable][currentQueue]

5.2 digit <-- get the currentDigit from the data in the node

5.3 index <-- passing the digit to the hash function to get the index

5.4 call addTail to add the node at the tail of the queue in currentTable, hashTable[currentTable][index]
        
5.5 repeat steps 5.1 - 5.4 until the currentQueue is empty
        
5.6 currentQueue ++ // process the next queue in the previous hashTable

      5.7 repeat step 5.1 - 5.6 until currentQueue >= tableSize

step 6: // swap the table
temp <-- currentTable
currentTable <-- previousTable
previousTable <-- temp
currentQueue <-- 0
currentDigit++ 
 
Step 7: repeat step 5 to 6 until currentDigit >= totalDigits.

Step 8: print currentTable
 

