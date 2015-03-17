#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <utility>
#include <map>
#include <set>
#include <string>
#include <deque>
#include <unordered_map>
#include <unordered_set>
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
  void solve(vector<vector<char>> &board) {
    int m = board.size();
    if(!m) return;
    int n = board[0].size();
    if(!n) return;
    unordered_set<int> saw;
    for(int i=0; i<m; i++)
      for(int j=0; j<n; j++)
        if(board[i][j] == 'O' && saw.find(i*n+j) == saw.end()){
          vector<pair<int,int> > to_fill = {{i, j}}, q = {{i, j}}; saw.insert(i*n+j);
          bool ok = true;
          while(!q.empty()){
            auto t = q.back(); q.pop_back();
            int ci = t.first, cj = t.second;
            for(auto t : vector<pair<int,int> >{{0,1}, {0,-1}, {1,0}, {-1,0}}){
              int ai = t.first, aj = t.second;
              int ni= ci+ai, nj = cj+aj;
              if(ni < 0 || nj < 0 || ni == m || nj == n){
                ok = false;
              } else {
                if(board[ni][nj] == 'O' && saw.find(ni*n+nj) == saw.end()){
                  to_fill.push_back({ni,nj}); q.push_back({ni,nj}); saw.insert(ni*n+nj);
                }
              }
            }
          }
          if(ok) for(auto t : to_fill) board[t.first][t.second] = 'X';
        }
  }
};

int main(){
  auto sol = Solution();
  vector<vector<char> > m = {{'X', 'X', 'X'},{'X', 'O', 'X'},{'X', 'X', 'X'}};
  sol.solve(m);
  for(auto &v : m){
    for(auto c : v)
      cout << c;
    cout << endl;
  }
    
}
