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
  vector<int> grayCode(int n) {
    vector<int> v1 = {0}, v2;
    vector<int> *a = &v1, *b = &v2, *t;
    for(int i=0; i<n; i++){
      for(auto j = a->begin(); j != a->end(); ++j)
        b->push_back(*j);
      for(auto j = a->rbegin(); j != a->rend(); ++j)
        b->push_back(*j + (1<<i));
      t = a; a = b; b = t;
      b->clear();
    }
    return *a;
  }
};

int main(){
  auto sol = Solution();
  auto v = sol.grayCode(2);
  prints(v);
}
