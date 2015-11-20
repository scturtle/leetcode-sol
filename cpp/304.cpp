#include <vector>
using namespace std;

class NumMatrix {
  vector<vector<int>> s;
public:
  NumMatrix(vector<vector<int>> &matrix) {
    int n = matrix.size();
    if(n == 0) return;
    int m = matrix[0].size();
    if(m == 0) return;
    s = vector<vector<int>>(n, vector<int>(m, 0));
    vector<int> c(m, 0);
    for(int i=0; i<n; i++)
      for(int j=0; j<m; j++){
        c[j] += matrix[i][j];
        s[i][j] = (j ? s[i][j-1] : 0) + c[j];
      }
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    int ans = s[row2][col2];
    if(row1) ans -= s[row1-1][col2];
    if(col1) ans -= s[row2][col1-1];
    if(row1 && col1) ans += s[row1-1][col1-1];
    return ans;
  }
};
