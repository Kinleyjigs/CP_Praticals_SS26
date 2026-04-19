# Bellman-Ford Algorithm 

### a. Problem Summary
The problem is about finding the shortest distance from one starting point (source) to all other vertices in a graph, even when some edges have negative weights. It also requires checking if there is a negative cycle, which makes shortest paths impossible.

### b. Algorithm Explanation
First, we set the source distance to 0 and all others to infinity.
Then, we relax all edges multiple times (V−1 times) to update the shortest distances.
After that, we do one more pass to check for negative cycles.
Finally, we print the shortest distances or mark nodes as unreachable.
### c. Time Complexity Analysis
The algorithm mainly runs edge relaxation V−1 times, so the time complexity is O(V × E).

### d. Space Complexity Analysis
We store distances and edges, so the space complexity is O(V + E).

### e. Reflection
From this problem, I learned that not all shortest path algorithms work in every case. Bellman-Ford is useful when there are negative edges, unlike Dijkstra. I also understood how negative cycles can be detected and why they matter.

#### screenshot

![alt text](<Screenshot 2026-04-19 at 6.03.50 PM.png>)