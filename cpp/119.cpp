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
  vector<int> getRow(int n) {
    vector<int> v = {1}, w;
    vector<int> *a = &v, *b = &w, *c;
    for(int i=1; i<=n; i++){
      b->push_back(1);
      for(int j=1; j<i; j++)
        b->push_back((*a)[j-1] + (*a)[j]);
      b->push_back(1);
      c = a; a = b; b = c;
      b->clear();
    }
    return a == &v ? v : w;
  }
};

int main(){
  auto sol = Solution();
  auto ans = sol.getRow(3);
  prints(ans);
}
