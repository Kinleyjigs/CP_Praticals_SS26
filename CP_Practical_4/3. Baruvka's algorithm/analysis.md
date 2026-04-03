# Boruvka's Algorithm Analysis

## Problem Summary
Build a Minimum Spanning Tree (MST) for an undirected, weighted graph. The result is a tree connecting all vertices with the smallest total edge weight. Boruvka's algorithm is one of the oldest MST algorithms and is naturally parallel.

## Algorithm Explanation
Boruvka's algorithm works by repeatedly merging components using their cheapest outgoing edges:

1. **Find components**: Initially, each vertex is its own component.
2. **Find cheapest edge per component**: For each component, find the minimum-weight edge that connects it to another component.
3. **Add edges**: Add all these edges to the MST and merge components.
4. **Repeat**: Continue until only one component remains.

Key Idea: In each round, every component greedily picks its cheapest connection to the outside world. This greedy choice is always safe because of the "cut property" of MSTs.

Steps:

1. Initialize component data structure (DSU/Union-Find).
2. While more than one component exists:
   - For each edge, track the cheapest one for each component pair.
   - Merge components using these cheapest edges.
   - Update component count.
3. Return total weight.

## Time Complexity Analysis
- Each round reduces component count (at least halves it).
- Number of rounds: O(log V).
- Each round scans all edges: O(E).
- Union-Find operations: O(α(V)) per edge (nearly constant).

Total: O(E log V).

## Space Complexity Analysis
- Graph storage: O(V + E).
- DSU structure: O(V).
- Best edge tracking: O(V).

Total: O(V + E).

## Reflection
Boruvka's algorithm is elegant because it naturally parallelizes—each component can independently find its cheapest edge, then all edges are added at once. It's less famous than Kruskal or Prim, but historically important. The algorithm is fast and, for dense graphs, can match or beat other MST algorithms. It teaches well-structured thinking about graph connectivity.


![alt text](<Screenshot 2026-04-04 at 2.35.02 AM.png>)