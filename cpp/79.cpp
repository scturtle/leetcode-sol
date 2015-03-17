#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <utility>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <climits>
#include <numeric>
using namespace std;

template<typename T>
void prints(vector<T> &v){
  cout << "[";
  for(uint i=0; i<v.size()-1; ++i)
    cout << v[i] << ", ";
  if(v.size()) cout << v[v.size()-1];
  cout << "]\n";
}

class Solution {
public:
  bool dfs(const vector<vector<char> > &board, const string &word,
           int i, int j, int cur, vector<vector<bool> > &saw){
    if(cur == word.length())
      return true;
    if(i <0 || j < 0 || i == board.size() || j == board[0].size() ||
       saw[i][j] || word[cur] != board[i][j])
      return false;
    saw[i][j] = true;
    bool result = (dfs(board, word, i+1, j, cur+1, saw) ||
                   dfs(board, word, i-1, j, cur+1, saw) ||
                   dfs(board, word, i, j+1, cur+1, saw) ||
                   dfs(board, word, i, j-1, cur+1, saw));
    saw[i][j] = false;
    return result;
  }
  bool exist(vector<vector<char> > &board, string word) {
    int m = board.size();
    int n = board[0].size();
    vector<vector<bool> > saw;
    for(int i=0; i<m; i++)
      saw.push_back(vector<bool>(n, false));
    for(int i=0; i<m; i++)
      for(int j=0; j<n; j++)
        if(board[i][j] == word[0])
          if(dfs(board, word, i, j, 0, saw))
            return true;
    return false;
  }
};


int main(){
  auto sol = Solution();
}
