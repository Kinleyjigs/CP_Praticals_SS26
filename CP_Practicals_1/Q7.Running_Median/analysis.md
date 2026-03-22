![alt text](<Screenshot 2026-03-22 at 12.33.07 PM.png>)

### a. Problem Summary
In this assignment, we have to determine the median (value that separates the higher half from the lower half) of a collection of numbers that are continually being added to one at a time. Each time one is added to the collection, we must update the median as quickly as possible to show the latest median.

we cannot sort the numbers every time another is added since the collection of numbers is always growing, and sorting them would take too long; therefore, you will need to find a more efficient method.

### b. How the Algorithm Works
We use the following two groups (or buckets) of numbers to make things faster:

1. A "Max Heap" which holds the smaller half of the numbers: that is, the highest number in this group will be the largest number from each group.

2. A "Min Heap" which holds the largest half of the numbers: that is, the lowest number in this group will be the largest number from each group.

When a new number comes in, we determine what group it belongs to based on whether it is larger than or smaller than the current median.

Each time one of the groups becomes too large when compared to the other group, we will move one of the numbers from that group over to the other group, so that both groups contain the same number of members.

To find the median:
- If the total number of members is odd, the median will be the member at the top of the larger group.
- If the total number of members is even, to find the median, we will take the average of both group members that are at the top of each group.

### Time Complexity
The time complexity is O(N log N).
- Each new number added takes log N time
- Since we do this for all N numbers, it becomes N log N

Getting the median itself is very fast (O(1)), so most of the time is spent inserting numbers.

### Space Complexity 
The space complexity is O(N).

Even though we use two heaps, we still store all the numbers, so memory grows with the input size.

### Reflection 
Data Structures can provide a lot of power for example rather than continuously sorting a list, storing the two halves of it in two heaps allows the two middle numbers to always be available for quickly calculating the median.

From the Output(screenshot) we can see:
- When there is an odd number (1 through 3: 1, 2, 3) the median is correct= 2.0
- When there is an even number (1 through 4: 1, 2, 3, 4) the median is calculated as average of the two middle (2+3)/2 = 2.5

Also, final formatting is correct since it is always presented with one decimal (1.0) which matches the required behaviour.