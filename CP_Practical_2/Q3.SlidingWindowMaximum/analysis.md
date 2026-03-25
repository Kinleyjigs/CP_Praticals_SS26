# Sliding Window Maximum 

### a. Problem Statement
In this problem we are given an array and a window size k, we need to find the maximum value in each sliding window as it moves from left to right.

### b. Algorithm Explanation
I used a deque (double-ended queue) to store indices of useful elements in decreasing order.
For each element, I removed elements that are out of the current window and those that are smaller than the current element.  The front of the deque always gives the maximum for the current window.

### c. Time Complexity
O(n) Each element is added and removed at most once.

### d. Space Complexity

O(k) The deque stores at most k elements.


### Reflection
I learned how a deque can efficiently solve sliding window problems in linear time. It helped me understand how to maintain useful elements while removing unnecessary ones to get the maximum quickly.

![alt text](<Screenshot 2026-03-25 at 10.48.33 PM.png>)