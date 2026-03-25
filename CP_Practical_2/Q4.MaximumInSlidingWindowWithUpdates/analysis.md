# Maximum in Sliding Window with Updates - Analysis

### a. Problem Summery
We are given an array and need to handle updates as well as queries to find the maximum value in a sliding window

### b. Algorithm Explanation
I used a simple linear approach where for each query, I checked all elements in the window and found the maximum.

### c. Time Complexity
O(Q × K)

Each query takes O(K) time to scan the window

### d. Space Complexity
O(N)

Only the array is stored

### e. Reflection
I learned that while a simple approach is easy to implement, it may not be efficient for large inputs. This made me understand the importance of using advanced data structures like segment trees for better performance.

![alt text](<Screenshot 2026-03-25 at 11.10.25 PM.png>)
