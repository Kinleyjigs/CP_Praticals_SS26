#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class RadixNode {
public:
    string text; 
    bool isEndOfWord;
    unordered_map<char, RadixNode*> children; 

    RadixNode(string t, bool isWord) {
        text = t;
        isEndOfWord = isWord;
    }
};

class PatriciaTrie {
private:
    RadixNode* root;

    int getCommonPrefixLength(string a, string b) {
        int i = 0;
        while (i < a.length() && i < b.length() && a[i] == b[i]) {
            i++;
        }
        return i;
    }

public:
    PatriciaTrie() {
        root = new RadixNode("", false); 
    }

    void insert(string word) {
        RadixNode* current = root;

        while (word.length() > 0) {
            char firstChar = word[0];

            if (current->children.find(firstChar) == current->children.end()) {
                current->children[firstChar] = new RadixNode(word, true);
                return;
            }

            RadixNode* child = current->children[firstChar];
            int commonLen = getCommonPrefixLength(child->text, word);

            if (commonLen < child->text.length()) {
                string splitPart = child->text.substr(commonLen);
                
                RadixNode* splitNode = new RadixNode(splitPart, child->isEndOfWord);
                splitNode->children = child->children; 

                child->text = child->text.substr(0, commonLen);
                child->isEndOfWord = false;
                child->children.clear();
                child->children[splitPart[0]] = splitNode; 
            }

            if (commonLen < word.length()) {
                word = word.substr(commonLen);
                current = child; // Move down the tree
            } 

            else {
                child->isEndOfWord = true;
                return;
            }
        }
    }

    bool search(string word) {
        RadixNode* current = root;

        while (word.length() > 0) {
            char firstChar = word[0];

            if (current->children.find(firstChar) == current->children.end()) {
                return false; 
            }

            RadixNode* child = current->children[firstChar];
            int commonLen = getCommonPrefixLength(child->text, word);

            if (commonLen < child->text.length() && commonLen < word.length()) {
                return false; 
            }

            word = word.substr(commonLen);
            current = child;
        }

        return current->isEndOfWord;
    }

    bool remove(string word) {
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

        if (current->isEndOfWord) {
            current->isEndOfWord = false;
            return true; 
        }
        return false; 
    }
};

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