![alt text](<Screenshot 2026-03-19 at 10.05.28 PM.png>)

## a. Problem Summery 
This program looks at a list of numbers using a small window of size K.
It moves this window from left to right, and for each position, it finds and prints the largest number inside the window.

## b. Algorithm Explanation 
The program uses a deque (double ended queue) to help track useful numbers.
Instead of storing numbers, it stores their positions (indices).

Step by step:
1. As we move through the list, we remove old positions from the front if they are no longer inside the window.
2. Before adding a new number, we remove all smaller numbers from the back of the deque because they are not useful anymore.
3. Then we add the current number's position to the deque.
4. The front of the deque always holds the index of the largest number in the current window.
5. Once the window reaches size K, we print the maximum value.

## c. Time Complexity
The time complexity is O(N).Even though there is a loop inside another loop, each number is:
- Added once
- Removed once

So the total work is still proportional to N.

## d. Space Complexity
The space complexity is O(K) (plus O(N) for storing input).
- The deque stores at most K elements at a time.
- So memory depends on the window size K, not the whole list.

## e. Reflection
From this problem, I learned a very smart way to find the maximum in a sliding window using a deque. At first, I thought we had to check all K elements every time, which would be slow. But using a deque makes it much faster because we only keep useful elements. I also learned that storing indices instead of values helps us easily remove elements that are no longer in the window. The idea of removing smaller elements before adding a new one was very useful, as it keeps the maximum always ready at the front. This problem improved my understanding of efficient problem-solving and data structures.