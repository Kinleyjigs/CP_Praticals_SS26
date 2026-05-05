#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// Part 1: The Compressed Node
class RadixNode {
public:
    string text; // Instead of 1 character, it holds a chunk of a word
    bool isEndOfWord;
    // Map to find children quickly based on their first letter
    unordered_map<char, RadixNode*> children; 

    // Constructor
    RadixNode(string t, bool isWord) {
        text = t;
        isEndOfWord = isWord;
    }
};

// Part 2: The Tree Structure
class PatriciaTrie {
private:
    RadixNode* root;

    // Helper function to find how many characters two strings share
    int getCommonPrefixLength(string a, string b) {
        int i = 0;
        while (i < a.length() && i < b.length() && a[i] == b[i]) {
            i++;
        }
        return i;
    }

public:
    PatriciaTrie() {
        // The root is always an empty starting point
        root = new RadixNode("", false); 
    }

    // Part 3: INSERTION (The tricky part!)
    void insert(string word) {
        RadixNode* current = root;

        while (word.length() > 0) {
            char firstChar = word[0];

            // Case A: No child starts with this letter. Just add the whole remaining word!
            if (current->children.find(firstChar) == current->children.end()) {
                current->children[firstChar] = new RadixNode(word, true);
                return;
            }

            // Case B: A child shares at least the first letter
            RadixNode* child = current->children[firstChar];
            int commonLen = getCommonPrefixLength(child->text, word);

            // If the child's text is longer than the common part, we must SPLIT the node.
            // Example: Child is "apple", we insert "app". Common is "app". We split off "le".
            if (commonLen < child->text.length()) {
                string splitPart = child->text.substr(commonLen);
                
                // Create a new node for the leftover part of the old child
                RadixNode* splitNode = new RadixNode(splitPart, child->isEndOfWord);
                splitNode->children = child->children; // Hand over the grandchildren

                // Update the old child to just be the shared prefix
                child->text = child->text.substr(0, commonLen);
                child->isEndOfWord = false;
                child->children.clear();
                child->children[splitPart[0]] = splitNode; // Link the new split node
            }

            // If the word we are inserting is longer than the common part, 
            // chop off the common part and keep traversing down.
            if (commonLen < word.length()) {
                word = word.substr(commonLen);
                current = child; // Move down the tree
            } 
            // If the word ends exactly here, just mark it as a word
            else {
                child->isEndOfWord = true;
                return;
            }
        }
    }

    // Part 4: SEARCHING
    bool search(string word) {
        RadixNode* current = root;

        while (word.length() > 0) {
            char firstChar = word[0];

            // If no path matches the first letter, it's not here
            if (current->children.find(firstChar) == current->children.end()) {
                return false; 
            }

            RadixNode* child = current->children[firstChar];
            int commonLen = getCommonPrefixLength(child->text, word);

            // If the chunk doesn't fully match the child node's text, the word isn't here
            if (commonLen < child->text.length() && commonLen < word.length()) {
                return false; 
            }

            // Chop off the matched part and continue
            word = word.substr(commonLen);
            current = child;
        }

        // We traced the whole word. Is the flag set to true?
        return current->isEndOfWord;
    }

    // Part 5: DELETION
    bool remove(string word) {
        // (Simplified for beginners: We do a "Soft Delete")
        // A true hard delete requires complex node merging. 
        // Here, we just find the node and turn the switch off.
        RadixNode* current = root;

        while (word.length() > 0) {
            char firstChar = word[0];
            if (current->children.find(firstChar) == current->children.end()) return false;

            RadixNode* child = current->children[firstChar];
            int commonLen = getCommonPrefixLength(child->text, word);

            if (commonLen < child->text.length() && commonLen < word.length()) return false;

            word = word.substr(commonLen);
            current = child;
        }

        // Turn off the "is Word" switch
        if (current->isEndOfWord) {
            current->isEndOfWord = false;
            return true; // Successfully deleted
        }
        return false; // The word existed as a prefix, but wasn't an actual word
    }
};

// Part 6: Testing it out
int main() {
    PatriciaTrie myTree;

    cout << "Inserting 'romane', 'romanus', 'apple', 'app'..." << endl;
    myTree.insert("romane");
    myTree.insert("romanus");
    myTree.insert("apple");
    myTree.insert("app");

    cout << "-----------------" << endl;
    cout << "Search 'apple': " << (myTree.search("apple") ? "Found" : "Not Found") << endl;
    cout << "Search 'app': " << (myTree.search("app") ? "Found" : "Not Found") << endl;
    cout << "Search 'roman': " << (myTree.search("roman") ? "Found" : "Not Found") << endl; // Just a prefix

    cout << "-----------------" << endl;
    cout << "Deleting 'apple'..." << endl;
    myTree.remove("apple");
    cout << "Search 'apple': " << (myTree.search("apple") ? "Found" : "Not Found") << endl;
    cout << "Search 'app': " << (myTree.search("app") ? "Found" : "Not Found") << endl; // 'app' should still exist!

    return 0;
}