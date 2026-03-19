![alt text](<Screenshot 2026-03-18 at 10.46.21 PM.png>)

## a. Problem Summary
This program asks to enter N numbers and removes any repeated numbers from the list.
It first sorts the numbers and then prints only the unique values.

## b. Algorithm Explanation
- First, the program takes N numbers from the user and stores them in a vector.
- Then it sorts the numbers from smallest to largest so that duplicate numbers come together.
- After sorting, the program checks each number one by one.
- It prints the first number, and for the rest it prints only if the number is different from the previous one.
- like doing this way, duplicate numbers are skipped and only unique numbers are shown.

## c. Time Complexity
The time complexity is O(N log N).
- Taking input takes O(N) time.
- Printing unique numbers also takes O(N) time.
- But sorting takes O(N log N) time, which is the slowest step, so it decides the overall complexity.

## d. Space Complexity
- The space complexity is O(N).

- This is because the program stores all N numbers in a vector.
If the user enters more numbers, more memory is needed.

## e. Reflection
From this problem, I learned that sorting data first can make solving problems easier and faster. After sorting, duplicate numbers come next to each other, so it becomes simple to remove them by comparing with the previous number. I also understood the importance of checking the first element carefully to avoid errors while comparing. This problem improved my understanding of vectors, sorting, loops, and how to think logically while writing efficient programs.