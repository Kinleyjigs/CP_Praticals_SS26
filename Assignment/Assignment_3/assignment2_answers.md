# Assignment 2 - CSF303: Competitive Programming
## Complete Solutions with Diagrams and Examples

---

## Q1. Maximum Flow Problem Formulation and Algorithms (10 marks)

### Part 1: Basic Definitions

#### **Maximum Flow Problem**
The maximum flow problem asks: "What is the maximum amount of 'stuff' (data, water, traffic) that can flow from a starting point to an ending point through a network with limited capacity pipes?"

**Key Concepts:**

1. **Source (s)**: The starting point where flow originates
   - In the cloud service example: The central server
   - Think of it as a water source or power plant

2. **Sink (t)**: The ending point where flow terminates
   - In the cloud service example: The regional servers (combined)
   - Think of it as a drain or consumption point

3. **Capacity**: The maximum amount that can flow through each link/edge
   - In the cloud service example: Maximum bandwidth of each communication link
   - Like the diameter of a pipe limiting water flow

4. **Residual Graph**: A helper graph that shows remaining capacity
   - Shows how much MORE flow can be pushed through each edge
   - Also shows "backward edges" representing flow we can cancel

**Simple Example:**
```
Network:
        (10)
    s ------> A
    |         |
(5) |         | (15)
    v         v
    B ------> t
        (10)

s = source (central server)
t = sink (regional server)
Numbers in () = capacity
```

### Part 2: Ford-Fulkerson Method

**Working Principle:**

The Ford-Fulkerson method is like repeatedly finding any path from source to sink and pushing as much flow as possible through it.

**Steps:**
1. Start with zero flow
2. Find ANY path from source to sink with available capacity (called an "augmenting path")
3. Find the minimum capacity along this path (the "bottleneck")
4. Push that amount of flow through the path
5. Update the residual graph
6. Repeat until no more paths exist

**Simple Example:**

```
Step 0: Initial Network
        (0/10)
    s --------> A
    |           |
(0/5)|          | (0/15)
    v           v
    B --------> t
        (0/10)

Format: (current_flow/capacity)

Step 1: Find path s→A→t
Bottleneck = min(10, 15) = 10
Push 10 units

        (10/10)
    s --------> A
    |           |
(0/5)|          | (10/15)
    v           v
    B --------> t
        (0/10)

Step 2: Find path s→B→t
Bottleneck = min(5, 10) = 5
Push 5 units

        (10/10)
    s --------> A
    |           |
(5/5)|          | (10/15)
    v           v
    B --------> t
        (5/10)

Maximum Flow = 10 + 5 = 15 units
```

### Part 3: Edmonds-Karp vs Dinic's Algorithm

#### **Edmonds-Karp Algorithm**

**Approach:**
- Uses BFS (Breadth-First Search) to find the shortest augmenting path
- Always picks the path with fewest edges

**Efficiency:**
- Time Complexity: O(V × E²)
- V = vertices, E = edges
- Slower but simpler

**Best for:**
- Small to medium networks
- When simplicity matters more than speed

#### **Dinic's Algorithm**

**Approach:**
- Uses "level graphs" and finds multiple augmenting paths at once
- Works in phases, blocking all paths at current level before moving to next

**Efficiency:**
- Time Complexity: O(V² × E)
- Much faster for dense graphs

**Best for:**
- Large networks with many edges
- Competition programming where speed is critical

**Comparison Table:**

| Feature | Edmonds-Karp | Dinic's |
|---------|-------------|---------|
| Path Selection | BFS - shortest path | Level graph - multiple paths |
| Time Complexity | O(V × E²) | O(V² × E) |
| Implementation | Simpler | More complex |
| Speed on large graphs | Slower | Faster |
| Best use case | Small networks | Large networks |

### Part 4: Ford-Fulkerson vs Dinic's - Deep Dive

#### **Core Mechanisms:**

**Ford-Fulkerson:**
- Finds ONE path at a time using DFS (any path)
- Updates graph
- Repeats

**Dinic's:**
- Builds a "level graph" (BFS layers)
- Finds MULTIPLE "blocking flows" in one phase
- Only advances when current level is exhausted

#### **Level Graphs and Blocking Flows (Dinic's)**

**Level Graph:**
A level graph assigns each vertex a level based on its shortest distance from the source.

```
Example:
    s (Level 0)
   / \
  A   B (Level 1)
   \ /
    t (Level 2)

Level graph only includes edges that go from level i to level i+1
```

**Blocking Flow:**
A blocking flow is when we push flow through multiple paths until no more paths exist at the current level structure.

**Simple Example:**

```
Original Graph:
        (10)      (10)
    s ------> A ------> t
    |                   ^
    |       (10)        |
    +------> B --------+
        (10)      (10)

Step 1: Build Level Graph
Level 0: s
Level 1: A, B
Level 2: t

Step 2: Find blocking flow
- Push through s→A→t: 10 units
- Push through s→B→t: 10 units
- Both paths at this level are now saturated

Total flow = 20 units (in ONE phase!)
```

#### **Catastrophic Example for Basic DFS Ford-Fulkerson**

**The Problem:**
When edge capacities are poorly chosen and DFS picks bad paths, Ford-Fulkerson can take forever.

**Classic Bad Case:**

```
Graph:
        (1000)          (1000)
    s ---------> A -----------> t
    |            |              ^
    |     (1)    |              |
    |            |              |
    +----------> B ------------+
        (1000)          (1000)

Also add edge A→B with capacity 1
```

**What happens with DFS Ford-Fulkerson:**

```
If DFS keeps picking paths that use the A↔B edge (capacity 1):

Iteration 1: s → A → B → t (push 1 unit)
Iteration 2: s → A → B → A → ... (push 1 unit)
Iteration 3: s → B → A → t (push 1 unit)
...and so on

This takes 2000 iterations to complete!
Time: O(F × E) where F = total flow = 2000
```

**How Dinic's handles it efficiently:**

```
Dinic's builds level graph:
Level 0: s
Level 1: A, B
Level 2: t

It finds:
- Path s→A→t: push 1000
- Path s→B→t: push 1000

Done in 1 phase!
Time: O(V² × E) regardless of flow value
```

**Why Dinic's wins:**
- Doesn't get "tricked" by bad DFS choices
- Uses BFS to ensure shortest paths
- Processes multiple paths simultaneously
- Time complexity doesn't depend on flow value (F)

---

## Q2. Bipartite Matching and Assignment Problems (10 marks)

### Part 1: Modeling as Bipartite Graph (2 marks)

**Bipartite Graph:**
A graph with two separate groups where edges only connect nodes between groups, never within a group.

**For Student-Project Assignment:**

```
Left Partition:              Right Partition:
Students                     Projects
┌─────────┐                 ┌─────────┐
│ Alice   │────────────────→│ AI App  │
│ Bob     │────────────────→│ Web Dev │
│ Charlie │────────────────→│ Database│
└─────────┘                 └─────────┘

Edges = Student preferences
```

**Diagram:**

```
    Students                    Projects
    
    Alice  ------------------>  AI App
      |   \                        |
      |     \                      |
      |       \                    |
    Bob   ----\-+------------->  Web Dev
      |         \|                 |
      |          X                 |
      |         /|                 |
  Charlie  ---/--+------------->  Database
            /
          /
```

**Two Partitions:**
1. **Left partition (U)**: Set of all students {Alice, Bob, Charlie}
2. **Right partition (V)**: Set of all projects {AI App, Web Dev, Database}

**Key property:** No student connects to another student, no project connects to another project.

### Part 2: Transform to Maximum Bipartite Matching (3 marks)

**Transformation Steps:**

1. **Create Super Source (s):**
   - Add one source node
   - Connect it to ALL students with capacity 1
   - This represents "each student can be assigned once"

2. **Create Super Sink (t):**
   - Add one sink node
   - Connect ALL projects to it with capacity 1
   - This represents "each project can accept one student"

3. **Set Edge Capacities:**
   - Source to students: capacity 1
   - Students to preferred projects: capacity 1
   - Projects to sink: capacity 1

**Flow Network Diagram:**

```
                Students        Projects
                
        ┌───→  Alice  ───→  AI App    ───┐
        │ 1        | 1    1    |  1       │
        │          ↓           ↓          │ 1
   s  ──┼───→  Bob    ───→  Web Dev  ───┼──→  t
  (source) 1      | 1    1    |  1       │ 1  (sink)
        │         ↓           ↓          │
        └───→  Charlie ───→ Database ───┘
          1         1      1      1

All edges have capacity 1
```

**Why this works:**
- Maximum flow = Maximum number of successful assignments
- Flow of 1 through a student→project edge = that assignment is made
- Capacity 1 constraint ensures each student gets at most 1 project
- Capacity 1 from projects to sink ensures each project gets at most 1 student

**Example:**
If maximum flow = 3, then all 3 students get assigned to projects!

### Part 3: Hopcroft-Karp Algorithm (3 marks)

**What it does:**
Hopcroft-Karp finds the maximum matching in a bipartite graph VERY efficiently.

**How it works (Simple version):**

1. **Start with no matches**

2. **Find multiple augmenting paths at once using BFS:**
   - An augmenting path is a path from an unmatched student to an unmatched project
   - Unlike simple algorithms that find one path at a time, Hopcroft-Karp finds many

3. **Use DFS to lock in all the paths found in step 2**

4. **Repeat until no more augmenting paths exist**

**Why it's efficient:**

| Algorithm | Time Complexity |
|-----------|----------------|
| Basic Ford-Fulkerson | O(V × E) |
| Hopcroft-Karp | O(E × √V) |

For large bipartite graphs, √V is MUCH smaller than V!

**Simple Example:**

```
Round 1:
Unmatched students: Alice, Bob, Charlie
Unmatched projects: AI, Web, DB

BFS finds multiple augmenting paths:
- Alice → AI
- Bob → Web
- Charlie → DB

DFS locks them in
Result: All matched in 1 round!

Versus basic algorithm: Would take 3 rounds (one match per round)
```

### Part 4: Real-World Application (2 marks)

**Job Matching in Software Engineering:**

**Scenario:**
A tech company uses automated systems to match:
- **Left side:** Job applicants with specific skills
- **Right side:** Open positions requiring those skills

**Example:**

```
    Applicants              Job Positions
    
    Alice (Python, AI) ──→ ML Engineer
    Bob (Java, Web)    ──→ Backend Dev
    Charlie (React)    ──→ Frontend Dev
    David (DevOps)     ──→ Cloud Architect
```

**Why Bipartite Matching:**
- Each applicant should get at most one position
- Each position should go to at most one applicant
- Need to maximize total successful placements
- Must respect skill requirements (edges = applicant qualifies for job)

**System uses Hopcroft-Karp to:**
1. Quickly find maximum number of successful placements
2. Handle thousands of applicants and positions
3. Process in real-time during hiring events

---

## Q3: Weighted Assignment Matrix (5 Marks)

### Problem Setup

**Engineers:** E1, E2, E3  
**Modules:** M1, M2, M3

**Cost Matrix W (in days):**

```
        M1   M2   M3
    ┌───────────────┐
E1  │  9    2    7  │
E2  │  6    4    3  │
E3  │  5    8    2  │
    └───────────────┘
```

**Goal:** Assign each engineer to exactly one module to minimize total delivery time.

### Hungarian Algorithm Solution

#### **Step 1: Row Reduction**

**Rule:** Subtract the minimum value in each row from all elements in that row.

**Row 1 (E1):** Min = 2  
Subtract 2: [9-2, 2-2, 7-2] = [7, 0, 5]

**Row 2 (E2):** Min = 3  
Subtract 3: [6-3, 4-3, 3-3] = [3, 1, 0]

**Row 3 (E3):** Min = 2  
Subtract 2: [5-2, 8-2, 2-2] = [3, 6, 0]

**Matrix after Row Reduction:**

```
        M1   M2   M3
    ┌───────────────┐
E1  │  7    0    5  │
E2  │  3    1    0  │
E3  │  3    6    0  │
    └───────────────┘
```

#### **Step 2: Column Reduction**

**Rule:** Subtract the minimum value in each column from all elements in that column.

**Column 1 (M1):** Min = 3  
Subtract 3: [7-3, 3-3, 3-3] = [4, 0, 0]

**Column 2 (M2):** Min = 0  
Subtract 0: [0-0, 1-0, 6-0] = [0, 1, 6]

**Column 3 (M3):** Min = 0  
Subtract 0: [5-0, 0-0, 0-0] = [5, 0, 0]

**Matrix after Column Reduction:**

```
        M1   M2   M3
    ┌───────────────┐
E1  │  4    0    5  │
E2  │  0    1    0  │
E3  │  0    6    0  │
    └───────────────┘
```

#### **Step 3: Find Optimal Assignment**

**Rule:** Try to assign zeros such that each row and column has exactly one assignment.

**Looking at the matrix:**

```
        M1   M2   M3
    ┌───────────────┐
E1  │  4   [0]   5  │  ← E1 must take M2 (only zero in row)
E2  │  0    1   [0] │  ← E2 can take M1 or M3
E3  │ [0]   6    0  │  ← E3 can take M1 or M3
    └───────────────┘
```

**Assignment Process:**

1. E1 → M2 (only zero available in E1's row)
2. Now M2 is taken, look at E2: Can choose M1 or M3
3. E2 → M3 (let's choose M3 with zero)
4. Now M3 is taken, E3 must take M1

**Final Optimal Assignment:**
- **E1 → M2**
- **E2 → M3**
- **E3 → M1**

#### **Step 4: Calculate Minimum Total Cost**

Using the **ORIGINAL cost matrix:**

```
        M1   M2   M3
    ┌───────────────┐
E1  │  9    2    7  │  → E1→M2 = 2
E2  │  6    4    3  │  → E2→M3 = 3
E3  │  5    8    2  │  → E3→M1 = 5
    └───────────────┘
```

**Total Cost:**
- E1 → M2: 2 days
- E2 → M3: 3 days
- E3 → M1: 5 days

**Minimum Total Cost = 2 + 3 + 5 = 10 days**

### Summary Table

| Engineer | Assigned Module | Delivery Time |
|----------|----------------|---------------|
| E1 | M2 | 2 days |
| E2 | M3 | 3 days |
| E3 | M1 | 5 days |
| **TOTAL** | - | **10 days** |

---

## Q4. NP-Completeness and Problem Reductions (10 marks)

### Part 1: Define Key Terms (4 marks)

#### **P (Polynomial Time)**

**Simple Definition:**
Problems that can be SOLVED quickly (in polynomial time) by a regular computer.

**Characteristics:**
- Fast algorithms exist
- Time grows reasonably with input size
- Examples: O(n), O(n²), O(n³)

**Real Example:**
- **Sorting numbers:** Can be done in O(n log n) time
- **Finding shortest path:** Can be done in O(E + V) time with BFS

**Think of it as:** Problems where we have efficient solutions.

#### **NP (Nondeterministic Polynomial)**

**Simple Definition:**
Problems where we can VERIFY a solution quickly, even if finding it is hard.

**Characteristics:**
- If someone gives you an answer, you can check if it's correct quickly
- Finding the answer might be hard
- Checking the answer is easy

**Real Example:**
- **Sudoku:** 
  - Hard to solve a 9×9 puzzle
  - Easy to check if a completed puzzle is correct (just verify rows, columns, boxes)

**Think of it as:** Problems where checking homework is easier than doing homework.

#### **NP-Hard**

**Simple Definition:**
Problems that are AT LEAST as hard as the hardest problems in NP.

**Characteristics:**
- If you could solve an NP-Hard problem quickly, you could solve ALL NP problems quickly
- Might not even be in NP (might not have quick verification)
- No known efficient algorithm

**Real Example:**
- **Halting Problem:** Determining if a program will ever stop running
  - This is NP-Hard but NOT in NP

**Think of it as:** The brutal boss-level problems.

#### **NP-Complete**

**Simple Definition:**
Problems that are:
1. In NP (solutions can be verified quickly), AND
2. NP-Hard (as hard as any problem in NP)

**Characteristics:**
- The "hardest" problems in NP
- If you solve one NP-Complete problem efficiently, you solve ALL of them
- Thousands of problems are proven NP-Complete

**Real Examples:**
- **Traveling Salesman Problem (TSP)**
- **Knapsack Problem**
- **Boolean Satisfiability (SAT)**

**Think of it as:** The elite group of equally-hard problems.

**Relationship Diagram:**

```
┌─────────────────────────────────────┐
│         NP-Hard                     │
│  ┌──────────────────────────┐       │
│  │  NP-Complete             │       │
│  │  (hardest problems       │       │  Halting Problem
│  │   in NP)                 │       │  (NP-Hard but not in NP)
│  │  ┌─────────────────┐     │       │
│  │  │      NP         │     │       │
│  │  │  ┌─────────┐    │     │       │
│  │  │  │    P    │    │     │       │
│  │  │  │ (easy)  │    │     │       │
│  │  │  └─────────┘    │     │       │
│  │  │                 │     │       │
│  │  └─────────────────┘     │       │
│  │                          │       │
│  └──────────────────────────┘       │
│                                     │
└─────────────────────────────────────┘
```

### Part 2: Purpose of Problem Reduction (2 marks)

**What is Problem Reduction?**

Problem reduction is like saying: "If I can solve Problem B, then I can also solve Problem A by converting it to Problem B."

**Purpose:**

1. **Prove Difficulty:**
   - To show Problem B is at least as hard as Problem A
   - Used to prove NP-Completeness

2. **Reuse Solutions:**
   - If we have a solver for Problem B, we can use it to solve Problem A

**Simple Analogy:**

```
Imagine you need to travel from City A to City C, but there's no direct bus.

Problem A: Travel A → C
Problem B: Travel B → C (direct bus exists)

Reduction: If you can get from A → B (easy), then you can reach C using the B → C bus.

A ──(reduction)──→ B ──(known solution)──→ C
```

**Example in Computing:**

```
Problem A: Is my graph 3-colorable?
Problem B: Boolean Satisfiability (SAT) - a known NP-Complete problem

Reduction: Convert graph coloring to SAT:
- Create variables for each vertex-color combination
- Create clauses ensuring adjacent vertices have different colors
- If SAT solver says "YES", graph is 3-colorable

This proves graph coloring is NP-Complete!
```

**Diagram:**

```
Unknown Problem A
       ↓
    (reduce)
       ↓
Known Problem B ─→ Use existing solver ─→ Solution for B ─→ Convert back ─→ Solution for A
```

### Part 3: Common NP-Complete Problem (2 marks)

#### **Traveling Salesman Problem (TSP)**

**Problem Statement:**
Given a list of cities and the distances between them, find the shortest possible route that visits each city exactly once and returns to the starting city.

**Why No Polynomial-Time Algorithm Exists:**

1. **Exponential Solutions to Check:**
   - For n cities, there are (n-1)!/2 possible routes
   - For 10 cities: ~181,000 routes
   - For 20 cities: ~60 quintillion routes!

2. **No Pattern to Exploit:**
   - Can't use divide-and-conquer easily
   - Can't use greedy approach (always fails for some cases)
   - Must consider global optimization

3. **Proven NP-Complete:**
   - Through reduction from Hamiltonian Cycle problem
   - If TSP had a polynomial solution, ALL NP problems would

**Simple Example:**

```
4 cities with distances:

    A
   /│\
  2 3 4
 /  │  \
B───C───D
  5   6

Need to find: A→?→?→?→A with minimum total distance

All possible routes:
1. A→B→C→D→A = 2+5+6+4 = 17
2. A→B→D→C→A = 2+?+6+3 = needs distance B→D
3. A→C→B→D→A = 3+5+?+4 = needs distance D→B
... many more

Must check them ALL to guarantee the minimum!
```

**Why it matters:**
- Delivery routing
- Circuit board design
- DNA sequencing
- Scheduling

### Part 4: Practical Strategies for NP-Hard Problems (2 marks)

#### **Strategy 1: Approximation Algorithms**

**What it is:**
Find a "good enough" solution that's guaranteed to be within a certain percentage of the optimal.

**How it works:**
- Trade optimality for speed
- Get answer like "within 2× of optimal" in polynomial time

**Example - TSP Approximation:**

```
Greedy Nearest Neighbor:
1. Start at any city
2. Always go to the nearest unvisited city
3. Return to start

Current city: A
          ↓
A → B (nearest: 2) → C (nearest from B: 5) → D (nearest from C: 6) → A (4)
Total: 17

Not optimal, but found in O(n²) time!
Guaranteed within 2× optimal for metric TSP.
```

**Code Concept:**
```python
def tsp_approximation(cities, distances):
    visited = [False] * len(cities)
    route = [0]  # start at city 0
    visited[0] = True
    
    for _ in range(len(cities) - 1):
        current = route[-1]
        nearest = find_nearest_unvisited(current, visited, distances)
        route.append(nearest)
        visited[nearest] = True
    
    return route
```

**Advantages:**
- Fast: Polynomial time
- Bounded error: Know how far from optimal
- Good enough for many real applications

#### **Strategy 2: Heuristics with Optimization**

**What it is:**
Use smart guessing combined with local improvement techniques.

**Common Techniques:**

**A) Greedy + Local Search:**

```
Step 1: Get initial solution (greedy)
Step 2: Try small improvements repeatedly

Example - 2-opt for TSP:
Take route: A→B→C→D→A
Try swapping edges:
  Original: A-B-C-D-A
  Swap: A-C-B-D-A (reverse B-C section)
  
If new route is shorter, keep it
Repeat until no improvement
```

**B) Simulated Annealing:**

```
Start with any solution
Repeat many times:
  - Make a random small change
  - If better: accept it
  - If worse: SOMETIMES accept it anyway (avoid getting stuck)
  - Reduce "temperature" (accept worse solutions less often over time)
```

**Real Competition Programming Example:**

```python
def solve_knapsack_heuristic(items, capacity):
    # Sort by value/weight ratio (greedy heuristic)
    items.sort(key=lambda x: x.value/x.weight, reverse=True)
    
    total_value = 0
    total_weight = 0
    selected = []
    
    # Greedy selection
    for item in items:
        if total_weight + item.weight <= capacity:
            selected.append(item)
            total_weight += item.weight
            total_value += item.value
    
    # Local search: try swapping items
    improved = True
    while improved:
        improved = False
        for i in range(len(selected)):
            for j in range(len(items)):
                if items[j] not in selected:
                    # Try replacing selected[i] with items[j]
                    if can_improve(selected, i, items[j], capacity):
                        make_swap(selected, i, items[j])
                        improved = True
                        break
    
    return selected, total_value
```

**Advantages:**
- Often finds very good solutions
- Flexible: can add domain-specific tricks
- Used in real industry (Google Maps routing, etc.)

**When to Use Each:**

| Scenario | Strategy |
|----------|----------|
| Need guaranteed bound | Approximation Algorithm |
| Need best possible solution | Heuristic with lots of time |
| Competition with time limit | Fast heuristic + local search |
| Production system | Approximation or proven heuristic |

---

## Summary: Key Takeaways

### Q1: Maximum Flow
- **Ford-Fulkerson:** Find any path, push flow, repeat
- **Edmonds-Karp:** Use BFS for paths (O(VE²))
- **Dinic's:** Use level graphs + blocking flows (O(V²E)) - fastest for large networks

### Q2: Bipartite Matching
- Model as two groups with edges between them
- Transform to max flow with source/sink
- **Hopcroft-Karp** solves in O(E√V) time
- Used for job matching, assignment problems

### Q3: Hungarian Algorithm
- Row reduction → Column reduction → Find zero assignments
- Guarantees minimum cost assignment
- Our solution: 10 days total

### Q4: Complexity Classes
- **P:** Easy to solve
- **NP:** Easy to verify
- **NP-Complete:** Hardest in NP
- **Strategies:** Approximation algorithms, heuristics

---

**End of Solutions**
