# Network Latency

### a. Problem Summary

We are given a graph with weighted edges and need to find the minimum latency (shortest path) from node 1 to node N.If no path exists, return -1.

### b. Approach
I used Dijkstra's Algorithm with a priority queue.
I always picked the node with the smallest distance and updated its neighbors if a shorter path was found.

### c. Time Complexity
O((N + M) log N)

Using a priority queue for processing nodes

### d. Space Complexity
O(N + M)

For storing the graph and distance array

### e. Reflection
I learned how Dijkstra’s algorithm efficiently finds the shortest path and how using a priority queue improves performance compared to simple approaches.

![alt text](<Screenshot 2026-03-26 at 8.42.07 AM.png>)