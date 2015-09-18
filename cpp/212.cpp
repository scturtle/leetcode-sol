#include <string>
#include <set>
#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
  int idx;
  Node **ch;
  Node() {
    ch = new Node *[26]();
    for (int i = 0; i < 26; i++)
      ch[i] = nullptr;
    idx = -1;
  }
};

class Solution {
  vector<int> di{0, 0, 1, -1}, dj{1, -1, 0, 0};
  void dfs(vector<vector<char>> &board, int i, int j, Node *p, set<int> &idx) {
    if (p->idx >= 0)
      idx.insert(p->idx);
    for (int k = 0; k < 4; k++) {
      int ii = i + di[k], jj = j + dj[k];
      if (0 <= ii && ii < board.size() && 0 <= jj && jj < board[0].size()) {
        int id = board[ii][jj] - 'a';
        if (board[ii][jj] != '\0' && p->ch[id] != nullptr) {
          char t = board[ii][jj];
          board[ii][jj] = '\0';
          dfs(board, ii, jj, p->ch[id], idx);
          board[ii][jj] = t;
        }
      }
    }
  }

public:
  vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
    int n = board.size();
    if (n == 0)
      return {};
    int m = board[0].size();
    if (m == 0)
      return {};
    Node *root = new Node();
    for (size_t i = 0; i < words.size(); i++) {
      Node *p = root;
      for (char c : words[i]) {
        int id = c - 'a';
        if (p->ch[id] == nullptr)
          p->ch[id] = new Node();
        p = p->ch[id];
      }
      p->idx = i;
    }
    set<int> idx;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        int id = board[i][j] - 'a';
        if (root->ch[id] != nullptr) {
          char t = board[i][j];
          board[i][j] = '\0';
          dfs(board, i, j, root->ch[id], idx);
          board[i][j] = t;
        }
      }
    vector<string> ans;
    for (int i : idx)
      ans.push_back(words[i]);
    return ans;
  }
};

int main() {
  vector<vector<char>> board{{'a', 'a'}};
  vector<string> words{"aa"};
  for (string w : Solution().findWords(board, words))
    cout << w << endl;
}
