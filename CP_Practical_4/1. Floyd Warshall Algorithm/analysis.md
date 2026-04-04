# Floyd-Warshall Algorithm Analysis

## Problem Summary
Find shortest paths between all pairs of vertices in a weighted graph. It also works when some edges have negative weights, as long as there is no negative cycle.

## Algorithm Explanation
Floyd-Warshall uses dynamic programming with three nested loops:

- Outer loop (k): Choose each vertex as an intermediate node.
- Inner loops (i, j): Check every source-destination pair.
- Relaxation: Update if path through k is better:
	dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

Key Idea: Build the answer step by step. After processing vertex k, dist[i][j] stores the best path from i to j using only vertices 0 to k as intermediate nodes.

Steps:

1. Initialize distance matrix with INF.
2. Set diagonal values to 0.
3. Fill direct edge weights.
4. Run three loops for k, i, j and relax distances.

## Time Complexity Analysis
Three nested loops run over all vertices:

- Each loop runs n times.
- Each iteration does constant work.

Total: O(n^3), where n is number of vertices.

## Space Complexity Analysis
- Distance matrix uses O(n^2).
- Extra variables use O(1).

Total: O(n^2).

## Reflection
Floyd-Warshall is easy to code and straightforward. Its main strength is its usefulness in finding the shortest path between all pairs of vertices. Floyd-Warshall does not perform well on huge graphs since its complexity is cubic. But for small to moderate-sized graphs, it is one of the best algorithms available.

![alt text](<Screenshot 2026-04-04 at 1.28.16 AM.png>)