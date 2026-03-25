# Maximum AND Subarray

### a. Problem Summary
In this problem we are given an array and a number k and we need to find the maximum AND value among all subarrays of size k.

### b. Algorithm Explanation
I used a greedy bit approach. Starting from the highest bit, I tried to set each bit in the result and checked if there exists a subarray of size k where all elements support that bit pattern. If yes, I kept the bit; otherwise, I ignored it and moved to the next bit.

### c. Time Complexity
O(32 × n × k) ≈ O(n × k), since we check up to 32 bits and each check scans subarrays of size k.

### d. Space Complexity
O(n), only the input array is stored, with no extra space used.

### e. Reflection
I learned how to use a bitwise greedy approach to build the maximum value step by step. Checking bits from MSB to LSB helped me understand how to maximize the result efficiently.

![alt text](<Screenshot 2026-03-25 at 10.34.15 PM.png>)
