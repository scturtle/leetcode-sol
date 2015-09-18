#include <string>
using namespace std;

class Node {
public:
  bool end;
  Node **ch;
  Node() {
    ch = new Node *[26]();
    end = false;
  }
};

class WordDictionary {
  Node *root;

public:
  WordDictionary() { root = new Node(); }

  // Adds a word into the data structure.
  void addWord(string word) {
    Node *p = root;
    for (char c : word) {
      int id = c - 'a';
      if (p->ch[id] == nullptr)
        p->ch[id] = new Node();
      p = p->ch[id];
    }
    p->end = true;
  }

  // Returns if the word is in the data structure. A word could
  // contain the dot character '.' to represent any one letter.
  bool search(string word) { return search(word, 0, root); }

  bool search(string word, size_t i, Node *p) {
    for (; i < word.length(); i++) {
      if (word[i] == '.') {
        for (int j = 0; j < 26; j++)
          if (p->ch[j] != nullptr && search(word, i + 1, p->ch[j]))
            return true;
        return false;
      } else {
        int id = word[i] - 'a';
        if (p->ch[id] == nullptr)
          return false;
        else
          p = p->ch[id];
      }
    }
    return p && p->end;
  }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
