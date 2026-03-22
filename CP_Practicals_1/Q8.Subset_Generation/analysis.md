![alt text](<Screenshot 2026-03-22 at 4.07.44 PM.png>)

### a. Problem Summary
The above mentioned software takes as input N items and generates every possible combination. The user may specify an empty set as one of the combinations. The total number of combinations generated is equal to 2 to the power of N (2^n).

### b. Algorithm Explanation
The program uses a bitmasking technique to generate subsets.
1. First, it reads the number of elements and stores them in a vector.
2. Then, it calculates total subsets using 2ⁿ (1 << n).
3. Each number from 0 to 2ⁿ - 1 represents a subset.
4. For each number (mask), we check its binary form:
    - If a bit is 1, we include that element in the subset
    - If a bit is 0, we skip it

This way, every possible combination is printed.

### c. Time Complexity Analysis
The time complexity is O(N × 2ⁿ).
- There are 2^n subsets
- For each subset, we check all N elements
- So total work becomes N × 2^n

### d. Space Complexity Analysis
The space complexity is O(N).
- We only store the input elements in a vector
- No extra large memory is used apart from that

### e. Reflection
I learned a lot about the potential of using bit masking for generating combinations. It turns out that we can generate all subsets of a set without having to do any complicated recursive calls.we can just use binary numbers to represent each subset. This made for a very clean and efficient solution, as well as allowed me to see some real-world applications of binary arithmetic.