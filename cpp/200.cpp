#include <vector>
#include <utility>
using namespace std;

class Solution {
public:
  int numIslands(vector<vector<char>>& grid) {
    int n = grid.size();
    if(n == 0) return 0;
    int m = grid[0].size();
    int ans = 0;
    vector<int> si, sj;
    vector<int> ai = {0, 0, 1, -1}, aj = {1, -1, 0, 0};
    for(int i=0; i<n; i++)
      for(int j=0; j<m; j++)
        if(grid[i][j] == '1'){
          ans += 1;
          grid[i][j] = '0';
          si.push_back(i); sj.push_back(j);
          while(!si.empty()){
            int ui = si.back(); si.pop_back();
            int uj = sj.back(); sj.pop_back();
            for(int k = 0; k < 4; k++){
              int vi = ui + ai[k], vj = uj + aj[k];
              if(0 <= vi && vi < n && 0 <= vj && vj < m && grid[vi][vj] == '1'){
                grid[vi][vj] = '0';
                si.push_back(vi); sj.push_back(vj);
              }
            }
          }
        }
    return ans;
  }
};
