# Boruvka's Algorithm Analysis

## Problem Summary
Create the MST of an undirected, weighted graph. The output of this process will be a tree that includes all the vertices with the minimum weight of edges in total. One of the earliest developed algorithms for creating an MST is Boruvka's algorithm.

## Algorithm Explanation
The Boruvka's algorithm consists of iteratively combining the components based on the least cost edges:

1. **Component identification**: At first, each vertex will be an independent component.
2. **Cheapest edge from components**: The smallest edge connecting each component with other components needs to be found.
3. **Edge selection**: Choose those edges and combine components.
4. **Iteration process**: Repeat steps till one single component is left.

Fundamental principle: Every component is greedy and selects its cheapest connection to the remaining graph due to cut property of MST.

Steps:

1. Create DSU or Union-Find structure for components.
2. Repeat steps while there is more than one component:
   - Find the cheapest edge connecting two components for each edge.
   - Combine components through cheapest edges.
   - Reduce the component count.
3. Output total weight.

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
The beauty of Boruvka’s Algorithm lies in the fact that it can be easily parallelized by getting each component to independently discover its least expensive edge, after which all these edges can simply be joined together. It isn’t as popular as Kruskal and Prim, but it does hold historical significance. The Algorithm is efficient and, in dense graphs, may even outperform others.


![alt text](<Screenshot 2026-04-04 at 2.35.02 AM.png>)