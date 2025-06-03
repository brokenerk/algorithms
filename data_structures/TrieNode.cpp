#include <bits/stdc++.h>
using namespace std;


class TrieNode {
    public:
        // pointer array for child nodes of each node
        TrieNode* children[26];
        // Used for indicating ending of string
        bool isLeaf;

        TrieNode() {
            // initialize the wordEnd variable with false
            // initialize every index of childNode array with NULL
            isLeaf = false;
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
};

// Method to insert a key into the Trie
void insert(TrieNode* root, const string& key) {
    // Initialize the curr pointer with the root node
    TrieNode* curr = root;
    // Iterate across the length of the string
    for (char c : key) {
        // Check if the node exists for the current character in the Trie
        if (curr->children[c - 'a'] == nullptr) {
            // If node for current character does not exist then make a new node
            TrieNode* newNode = new TrieNode();
            // Keep the reference for the newly created node
            curr->children[c - 'a'] = newNode;
        }
        // Move the curr pointer to the newly created node
        curr = curr->children[c - 'a'];
    }
    // Mark the end of the word
    curr->isLeaf = true;
}

// Method to search a key in the Trie
bool search(TrieNode* root, const string& key) {
    // Initialize the curr pointer with the root node
    TrieNode* curr = root;
    // Iterate across the length of the string
    for (char c : key) {
        // Check if the node exists for the current character in the Trie
        if (curr->children[c - 'a'] == nullptr) 
            return false;
        // Move the curr pointer to the already existing node for the 
        // current character
        curr = curr->children[c - 'a'];
    }
    // Return true if the word exists and is marked as ending
    return curr->isLeaf;
}

// Method to Seach Prefix key in Trie
bool isPrefix(TrieNode *root, string &key) {
    TrieNode *current = root;
    for (char c : key) {
        int index = c - 'a';
        // If character doesn't exist, return false
        if (current->children[index] == nullptr)
            return false;
        current = current->children[index];
    }
    return true;
}


int main() {
    // Create an example Trie
    TrieNode *root = new TrieNode();
    vector<string> arr = {"and", "ant", "do", "dad"};

    for (const string &s : arr)
        insert(root, s);

    // One by one search strings
    vector<string> searchKeys = {"do", "gee", "bat"};
    for (string &s : searchKeys){
        if(search(root, s))
            cout << "true ";
        else
            cout << "false ";
    } 
    cout<<"\n";

    // One by one search for prefixes
    vector<string> prefixKeys = {"ge", "an", "do", "de"};
    for (string &s : prefixKeys){
        if (isPrefix(root, s))
            cout << "true ";
        else
            cout << "false ";
    }

    return 0;
}
