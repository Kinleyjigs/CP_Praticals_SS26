# Johnson's Algorithm Analysis

## Problem Summary
Find shortest paths between all pairs of vertices in a weighted, sparse graph that may contain negative edge weights. Johnson's algorithm combines Bellman-Ford and Dijkstra to efficiently solve this problem.

## Algorithm Explanation
Johnson's algorithm works in three main steps:

1. **Reweighting**: Add an imaginary source that connects to all vertices with zero-weight edges. Run Bellman-Ford from this source to compute "height" values h[v].
2. **Reweight edges**: For each edge (u, v) with weight w, change it to w' = w + h[u] - h[v]. Now all weights are non-negative.
3. **Dijkstra from each vertex**: Run Dijkstra from every source using reweighted edges. Convert results back using original heights.

Key Idea: The reweighting transforms negative weights into non-negative ones while preserving shortest path relationships. This allows fast Dijkstra algorithm to run from every vertex.

Steps:

1. Create imaginary source with zero edges.
2. Run Bellman-Ford to compute heights.
3. Reweight all edges.
4. Run Dijkstra from each vertex.
5. Convert output back to original weights.

## Time Complexity Analysis
- Bellman-Ford: O(VE).
- Dijkstra V times with priority queue: O(V × E log V).

Total: O(VE log V).

This is faster than Floyd-Warshall for sparse graphs (E ≪ V^2).

## Space Complexity Analysis
- Graph storage: O(V + E).
- Output matrix: O(V^2).
- Bellman-Ford and Dijkstra data: O(V).

Total: O(V^2).

## Reflection
Johnson's algorithm is clever because it combines two algorithms to solve a hard problem. It is much better for sparse graphs than Floyd-Warshall. However, it is more complex to implement and understand. The reweighting trick eliminates negative weights while keeping shortest paths correct—this is elegant problem-solving.

![alt text](<Screenshot 2026-04-04 at 2.31.27 AM.png>)

