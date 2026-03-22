![alt text](<Screenshot 2026-03-22 at 4.52.09 PM.png>)

### a. Problem Summary
The program considers the entire set of input (any sequence of integer values), examines all combinations of those input items (including selecting none), sums the results for each possible combination, counts the number of sums calculated that were even.

### b. Algorithm Explanation
The bit mask function makes finding all subsets simple.

Every number can therefore be represented by its corresponding on/off (1/0) settings:
- 1: include
- 0: do not include

Since the total number of subsets can be calculated as 2ⁿ, the program essentially creates all possible combinations of elements by counting upward from 0 to 2ⁿ - 1.

For each subset:
- Take the numbers included (represented as binary digits)
- Sum them
- Determine if that sum is currently even

For every subset whose sum is even, we add to our counter.The empty subset qualifies, because its sum is 0, which is, therefore, an even sum.

### c. Time Complexity Analysis
The time complexity is O(N × 2^n).
- There are 2^n subsets
- For each subset, we check all N elements
- So total work becomes N × 2^n

### d. Space Complexity Analysis
The space complexity is O(N).

We only store the original list of numbers and we do not save all subsets, we just process them one by one.

### e. Reflection
This problem allowed me to see how useful bitmasking can be. I was able to create subsets without using a lot of code. Using binary numbers makes generating subsets very easy and clean. I now see that even though 0's and 1's are basic concepts they are powerful tools in combination problems.