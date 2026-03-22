![alt text](<Screenshot 2026-03-20 at 7.22.47 AM.png>)

## a. Problem Summary
This problem is about managing a line of people where they can join or leave from both the front and the back.
After every operation, we need to print the current state of the line.

## b. Algorithm Explanation
We use a deque because it allows adding and removing elements from both ends easily.

Step by step:
1. First, we read how many operations we need to perform.

2. For each operation:
- If it is push_front x, we add the person x to the front.
- If it is push_back x, we add the person x to the back.
- If it is pop_front, we remove the person at the front (if not empty).
- If it is pop_back, we remove the person at the back (if not empty).

3. After every operation, we print the current line from front to back.

## c. Time Complexity
- Adding or removing elements from the deque is very fast and takes O(1) time.
- But after every operation, we print the whole line, which takes O(N) time.
- Since we do this many times, the total time becomes O(N²) in the worst case.

## d. Space Complexity 
The space complexity is O(N).
- The deque stores all the people currently in the line.
- If more people join, more memory is used.

## e. Reflection
From this problem, I learned the importance of using the right data structure. A deque is very useful when we need to add or remove elements from both ends quickly. If I had used a normal vector, removing from the front would be slow because all elements would need to shift. I also practiced handling different types of input commands and printing the result after each step. Overall, this problem helped me better understand deques, efficiency, and how to simulate real-life situations using code.