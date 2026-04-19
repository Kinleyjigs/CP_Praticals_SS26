#   Floyd Warshall Algorithm

### Analysis and Explanations
#### Why it works with negative edge weights?
Floyd–Warshall works because it checks every possible path between all pairs of vertices, using intermediate nodes step by step.

So even if an edge has a negative weight, the algorithm will still compare it with other paths and pick it if it gives a shorter distance.

#### Why it fails in the presence of negative cycles?
The algorithm cannot produce a correct or stable result when a negative cycle exists. This is because repeated traversal of the cycle continuously reduces the total distance without limit.

A clear indication of this issue is when the distance from a vertex to itself becomes negative (dist[i][i]< 0). This implies that moving in a cycle results in a lower cost than remaining at the same vertex, which makes the concept of a shortest path invalid.