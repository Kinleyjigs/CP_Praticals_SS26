
# Reflections — CP_Practical_6

### 1) Trie

![alt text](image/trie.png)

**Time complexity:** O(n)

A Trie is a tree-like data structure used to store and search words by breaking them into characters. It shares a common prefixes, so similar words reuse the same path instead of being stored separately. Because of this, operations like **searching** and **inserting** are fast and depend only on the length of the word, not the number of words stored.

I also learned that Tries are very useful for things like autocomplete and dictionaries. However, one limitation is that they can use a lot of memory since each character is stored as a separate node, even when there are many nodes with only one child.

##### For example,
when storing words like "cat" and "car," both share the path "ca" and only branch at the last letter. This shows how the Trie avoids duplication by sharing prefixes.

![alt text](image/trie_structure.svg)


### 2) PATRICIA Tries 

![alt text](image/patricia.png) 


**Time Complexity:** O(n)

- Even though it is an optimized version of a standard Trie, it still has O(n) time complexity. However, a Patricia Trie is faster in practice because it reduces unnecessary nodes, not the amount of work per character.

![alt text](image/patricia_vs_trie.svg)

A Patricia Trie is an improved version of a normal Trie that saves memory. Instead of storing one character at a time, it combines chains of nodes into one edge and stores whole parts of words. This means it skips unnecessary steps and keeps the structure smaller.

Compared to a regular Trie, which stores every character separately, a Patricia Trie stores words in chunks. Because of this, it uses less space and can be a bit faster, but it is also slightly more complex to implement.

### 3) Manacher's Algorithm

**Time complexity:** O(n) 

