### a. Problem Summary

The problem is to generate all possible subsets of a given set (size ≤ 20) and count how many of those subsets have a sum divisible by a given number K.

### b. Algorithm Explanation

The solution uses bitmasking to generate all subsets.
Each number from 0 to 2^N - 1 represents a subset.

For each bitmask:
1. Check which elements are included using bit operations
2. Calculate the sum of those elements
3. If the sum is divisible by K, increase the count

### c. Time Complexity

There are 2^N subsets, and each takes up to N steps to compute the sum.
Overall time complexity = O(N × 2^N)

### d. Space Complexity

Only the input array is stored.
Space complexity = O(N)

### e.Reflection

This problem shows how bitmasking can efficiently generate all subsets. It also helps understand how binary numbers can represent combinations. It is useful when N is small (like ≤ 20).

#### screenshot
![alt text](<Screenshot 2026-04-19 at 7.00.57 PM.png>)