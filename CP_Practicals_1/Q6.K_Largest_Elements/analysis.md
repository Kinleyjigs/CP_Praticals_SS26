![alt text](<Screenshot 2026-03-22 at 11.17.02 AM.png>)

### a. Problem Summary
This program takes a list with numbers and returns those numbers with the K highest numbers in it in order of highest to lowest. Then it will print out those numbers in order of highest number to lowest number.

### b. How the Code Works
To do this correctly and efficiently, the program uses a structure called a priority queue (in effect, a structure for keeping the "largest" value (element/number) at the front of the priority queue).

The priority queue creates the largest of the numbers inserted within it and then puts that number at the front of the queue every time a new number is inserted into it. The first step in solving this problem is to read in the values of N (total count of numbers to be read) and K (number of largest values to return).

The second step in solving this problem is to store each of the N values into the priority queue. No matter what order the numbers were read into the priority queue, the largest number will always remain at the front of the queue.

Lastly, once K largest values have been somehow extracted from the priority queue, the program simply does the following (in K iterations):
1. Take the largest number (this is the largest number currently at the front of the priority queue)
2. Print that number
3. Remove that number from the priority queue.

### c. Time Complexity
The overall time complexity is O(N log N).

Adding each number into the queue takes a little time (log N).
Since we add N numbers, it becomes N log N.
Removing the top K elements also takes time, but it is smaller compared to the first step.

### d. Space Complexity

The space complexity is O(N).

This is because all the input numbers are stored in the priority queue, so the memory used increases with the number of inputs.

### e. Reflection
This problem shows how useful a priority queue can be when dealing with 'top K' problems. Instead of sorting the entire list, it automatically keeps the largest values ready at the top. It makes the solution cleaner and more efficient, since we don't have to worry about arranging everything manually.