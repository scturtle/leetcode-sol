#include <string>
using namespace std;

class TrieNode {
public:
  bool exists;
  TrieNode **children;
  // Initialize your data structure here.
  TrieNode() {
    children = new TrieNode*[26](); // () for init
    exists = false;
  }
};

class Trie {

private:
  TrieNode *root;

  TrieNode* search(string word, bool create){
    TrieNode *p = root;
    for (char c : word) {
      int id = c - 'a';
      if (p->children[id] == nullptr){
        if(create)
          p->children[id] = new TrieNode();
        else
          return nullptr;
      }
      p = p->children[id];
    }
    return p;
  }

public:
  Trie() { root = new TrieNode(); }

  // Inserts a word into the trie.
  void insert(string word) {
    search(word, true)->exists = true;
  }

  // Returns if the word is in the trie.
  bool search(string word) {
    TrieNode *p = search(word, false);
    return p && p->exists;
  }

  // Returns if there is any word in the trie
  // that starts with the given prefix.
  bool startsWith(string prefix) {
    return search(prefix, false) != nullptr;
  }
};
