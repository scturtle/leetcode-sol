#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int n = matrix.size();
    if (n == 0)
      return false;
    int m = matrix[0].size();
    int j;
    for (j = 0; j < m; j++) {
      if (target == matrix[0][j])
        return true;
      if (j == m-1 || target < matrix[0][j+1])
        break;
    }
    for (int i = 1; i < n; i++){
      if(target > matrix[i][j]){
        while(target > matrix[i][j] && j+1 < m)
          ++j;
      } else if (target < matrix[i][j]){
        while(target < matrix[i][j] && j > 0)
          --j;
      }
      if(target == matrix[i][j])
        return true;
    }
    return false;
  }
};

int main(){
  auto s = Solution();
  vector<vector<int>> v = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}};
  cout << s.searchMatrix(v, 25) << endl;
}
