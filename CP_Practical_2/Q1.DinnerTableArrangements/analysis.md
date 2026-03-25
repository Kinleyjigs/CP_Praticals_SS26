# Dinner Table Arrangements - Analysis

## a. Problem Summary
We have N friends sitting around a circular table. Each friend has allergies. Two people can sit next to each other only if they share no common allergies. So in this problem we need to check if it is possible to arrange everyone in a valid circle.

## b. Algorithm Explanation

- First, check which friends can sit together using bitwise AND (no common allergies).
- Use DP with bitmask where dp[mask][last] means a valid arrangement ending with last.
- Start with single friends, then keep adding compatible friends one by one.
- After using all friends, check if the last person can sit with the first to form a circle.

## c. Time Complexity Analysis
O(2^n × N^2)

There are 2^n states and up to N transitions for each.

## d. Space Complexity

O(2^n × N)

Used for storing DP states.

## e. Reflection
While solving this problem, I learned how useful bitmask DP is for handling combinations efficiently. Instead of checking all permutations, I used DP to reduce the complexity.

I also understood how bitwise operations make checking compatibility very fast. The circular condition (first and last connection) was a bit tricky but important.

Overall, this problem helped me combine DP and graph thinking to solve it efficiently.

![alt text](<Screenshot 2026-03-25 at 9.56.25 PM.png>)