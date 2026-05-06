#include <iostream>
#include <string>

using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < 26; i++) children[i] = nullptr;
    }
};

class Trie {
private:
    TrieNode* root;

    TrieNode* removeHelper(TrieNode* current, string word, int depth) {

        if (!current) return nullptr;

        if (depth == word.length()) {
            
            if (current->isEndOfWord) current->isEndOfWord = false;

            if (isEmpty(current)) {
                delete (current);
                current = nullptr;
            }
            return current;
        }

        int index = word[depth] - 'a';
        current->children[index] = removeHelper(current->children[index], word, depth + 1);

        if (isEmpty(current) && current->isEndOfWord == false) {
            delete (current);
            current = nullptr;
        }

        return current;
    }

    bool isEmpty(TrieNode* root) {
        for (int i = 0; i < 26; i++)
            if (root->children[i]) return false;
        return true;
    }

public:
    Trie() { root = new TrieNode(); }

    // --- INSERT ---
    void insert(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            int i = c - 'a';
            if (!curr->children[i]) curr->children[i] = new TrieNode();
            curr = curr->children[i];
        }
        curr->isEndOfWord = true;
    }

    bool search(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            int i = c - 'a';
            if (!curr->children[i]) return false;
            curr = curr->children[i];
        }
        return curr->isEndOfWord;
    }

    void remove(string word) {
        root = removeHelper(root, word, 0);
    }
};

int main() {
    Trie t;
    t.insert("hero");
    t.insert("heroine");

    cout << "Search 'heroine': " << (t.search("heroine") ? "Found" : "Gone") << endl;
    
    t.remove("heroine");
    cout << "After deleting 'heroine'..." << endl;
    
    cout << "Search 'heroine': " << (t.search("heroine") ? "Found" : "Gone") << endl;
    cout << "Search 'hero': " << (t.search("hero") ? "Found" : "Gone") << endl; // Should still be there!

    return 0;
}