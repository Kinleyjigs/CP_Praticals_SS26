# The Shortest Path with Toll Booths

### a. Problem Summery 
We have N toll booths and start with M coins.At each booth, we can either pay the toll (1 min) or skip (2 min) with at most K skips.We need to find the minimum time to reach the end, or return -1 if impossible.

### b. Algorithm Explanation

I used a BFS approach with states (position, coins left, skips used).
From each state, I either paid the toll (if enough coins) or skipped (if skips remain), and explored all possible paths to find the minimum time.

### Time Complexity
O(N × M × K)

Each state is processed once

### Space Complexity  
O(N × M × K)

For storing visited states

### e. Reflection
I learned how to use state based BFS to handle multiple constraints like coins and skips. This problem showed me that sometimes we need to track extra information to find the optimal solution.

![alt text](<Screenshot 2026-03-26 at 9.40.13 PM.png>)