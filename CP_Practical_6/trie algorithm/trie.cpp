#include <iostream>
#include <string>

using namespace std;

// Part 1: The Building Block (The Node)
class TrieNode {
public:
    TrieNode* children[26]; 
    bool isEndOfWord;       

    // Constructor: This runs automatically when we create a new node
    TrieNode() {
        isEndOfWord = false; 
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr; 
        }
    }
};

// Part 2: The Trie Structure
class Trie {
private:
    TrieNode* root; // The very top of the tree

public:
    // Constructor
    Trie() {
        root = new TrieNode(); 
    }

    // Part 3: Adding a word
    void insert(string word) {
        TrieNode* currentNode = root; // Start at the top

        for (int i = 0; i < word.length(); i++) {
            char c = word[i]; // Get the current letter
            int alphabetIndex = c - 'a'; // Turn 'a' into 0, 'b' into 1, etc.

            // If there is no node for this letter yet, make a new one
            if (currentNode->children[alphabetIndex] == nullptr) {
                currentNode->children[alphabetIndex] = new TrieNode();
            }

            // Move down to that child node
            currentNode = currentNode->children[alphabetIndex];
        }
        
        // After the loop, we are at the last letter. Mark it as a word.
        currentNode->isEndOfWord = true;
    }

    // Part 4: Searching for a complete word
    bool search(string word) {
        TrieNode* currentNode = root; // Start at the top

        for (int i = 0; i < word.length(); i++) {
            char c = word[i];
            int alphabetIndex = c - 'a';

            // If the path breaks, the word isn't here
            if (currentNode->children[alphabetIndex] == nullptr) {
                return false; 
            }

            // Move down to the next letter
            currentNode = currentNode->children[alphabetIndex];
        }
        
        // We found the path! But is it a complete word, or just a prefix?
        if (currentNode->isEndOfWord == true) {
            return true;
        } else {
            return false;
        }
    }
};

// Part 5: Testing it out
int main() {
    Trie myDictionary;

    myDictionary.insert("cat");
    myDictionary.insert("car");

    cout << "Searching for 'cat'..." << endl;
    if (myDictionary.search("cat") == true) {
        cout << "Found it!" << endl;
    } else {
        cout << "Not found." << endl;
    }

    cout << "Searching for 'ca'..." << endl;
    if (myDictionary.search("ca") == true) {
        cout << "Found it!" << endl;
    } else {
        cout << "Not found. (It is only a prefix, not a full word)" << endl;
    }

    return 0;
}