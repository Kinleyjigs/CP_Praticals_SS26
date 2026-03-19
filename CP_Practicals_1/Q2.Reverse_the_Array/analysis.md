![alt text](<Screenshot 2026-03-18 at 10.23.44 PM.png>)

## a. Problem summary
This program asks the user to enter a number N, which tells how many integers they want to input.
It then stores these numbers in a list (vector), prints the numbers in the original order, and finally prints them again in reverse order.

## b. Algorithm Explanation
The program works step by step as follows:

1. First, it asks the user to enter the value of N (total number of integers).
2. Then it uses a loop to take N numbers from the user and stores them in a vector using push_back().
3. After storing the numbers, the program prints the original sequence by traversing the vector from the first element to the last.
4. Next, it prints the reversed sequence by traversing the vector from the last element to the first.
5. Finally, the program ends after displaying both sequences.

## c. Time Complexity Analysis
The time complexity of this program is O(N).
- One loop runs N times to take input.
- Another loop runs N times to print the original sequence.
- A third loop runs N times to print the reversed sequence.

## d. Space Complexity Analysis
The space complexity is O(N).

This is because the program stores all N numbers inside a vector.
As the number of inputs increases, the memory required also increases linearly.

## e. Reflection
While solving this problem, I learned how to use vectors in C++ to store multiple inputs dynamically. I also understood how loops can be used to traverse data in both forward and reverse directions. This problem helped me improve my understanding of indexing, especially how to start from N-1 when printing elements in reverse order. Additionally, I learned about time and space complexity and how storing more elements increases memory usage. Overall, this exercise strengthened my basic programming logic and made me more comfortable working with arrays and loops in C++.

