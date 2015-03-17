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
  bool check(vector<char> t){
    sort(begin(t), end(t));
    for(int i=1; i<t.size(); i++)
      if(t[i-1] == t[i] && t[i] != '.')
        return false;
    return true;
  }
  bool isValidSudoku(vector<vector<char>> &board) {
    vector<char> h, v, g;
    for(int i=0; i<9; i++){
      h.clear(); v.clear();
      for(int j=0; j<9; j++)
        h.push_back(board[i][j]), v.push_back(board[j][i]);
      if(!check(h) || !check(v))
        return false;
    }
    for(int i=0; i<9; i+=3)
      for(int j=0; j<9; j+=3){
        g.clear();
        for(int k=0; k<3; k++)
          for(int l=0; l<3; l++)
            g.push_back(board[i+k][j+l]);
        if(!check(g))
          return false;
      }
    return true;
  }
};

int main(){
  auto sol = Solution();
}
