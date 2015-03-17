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
  int minimumTotal(vector<vector<int> > &triangle) {
    int n = triangle.size();
    if(n == 0) return 0;
    vector<int> v(n, 0), w(n, 0);
    vector<int> *a = &v, *b = &w, *c;
    (*a)[0] = triangle[0][0];
    for(int i=2; i<=n; i++){
      for(int j=0; j<i; j++){
        if(j == 0)
          (*b)[j] = triangle[i-1][j] + (*a)[j];
        else if(j == i-1)
          (*b)[j] = triangle[i-1][j] + (*a)[j-1];
        else
          (*b)[j] = triangle[i-1][j] + min((*a)[j], (*a)[j-1]);
      }
      c = a; a = b; b = c;
    }
    return *min_element(a->begin(), a->end());
  }
};

int main(){
  auto sol = Solution();
}
