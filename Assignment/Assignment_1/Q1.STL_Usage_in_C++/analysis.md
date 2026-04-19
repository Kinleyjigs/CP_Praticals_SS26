# STL Usage in C++ 

### a. Problem Summary
The problem asks to demonstrate the use of different STL containers in C++. It involves storing and reversing elements using a vector, performing operations using a deque, and calculating the sum of a fixed-size array using STL functions.

### b. Algorithm Explanation

First, the program reads N numbers and stores them in a vector, then prints them in reverse using iterators.
Next, it processes Q operations on a deque where elements can be added to the front or back, or removed from the front.
Finally, it stores 5 numbers in a fixed array and calculates their total using the accumulate() function.

### c. Time Complexity Analysis
1. Vector input and reverse printing: O(N)
2. Deque operations: O(Q) (each operation is constant time)
3. Array sum using accumulate: O(M)

Overall time complexity: O(N + Q + M)

### d. Space Complexity Analysis
Vector uses O(N) space
Deque uses up to O(Q) space
Array uses O(M) space

Overall space complexity: O(N + Q + M)

### e. Reflection

From this problem, I understood how different STL containers are used for different purposes. Vectors are useful for dynamic storage, deque allow efficient insertion and deletion from both ends, and arrays are good for fixed-size data. I also learned how STL functions like accumulate() make tasks easier and cleaner.

#### screenshot
![alt text](<Screenshot 2026-04-18 at 10.57.34 PM.png>)