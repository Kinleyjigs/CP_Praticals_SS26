![alt text](<Screenshot 2026-03-22 at 5.27.36 PM.png>)

### a. Problem Summary
We are given a list of numbers and a target value. The goal is to find how many different subsets can add up exactly to that target.

### b. Algorithm Explanation
Instead of checking all combinations, we use Dynamic Programming (DP).
- We keep a list dp where each index tells us how many ways we can make that sum
- Start with dp[0] = 1 (there is one way to make sum 0 → choose nothing)
- For each number, we update the list by adding it to previous sums
- At the end, dp[target] gives our answer

### c. Time Complexity
O(N × target)

We loop through all numbers and update values up to the target.

### d. Space Complexity
O(target)

We only use one list of size equal to the target.

### e. Reflection
This problem showed me how powerful DP is. Instead of checking every subset, we reuse previous results, which makes the solution much faster and cleaner.