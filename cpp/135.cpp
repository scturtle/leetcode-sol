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
  int candy(vector<int> &ratings) {
    vector<pair<int,int> > rat_idx;
    int n = ratings.size();
    for(int i=0; i<n; i++)
      rat_idx.push_back(make_pair(ratings[i], i));
    sort(rat_idx.begin(), rat_idx.end());
    vector<int> cand(n, -1);
    for(auto &p : rat_idx){
      int i = p.second;
      int left = i>0 ? (ratings[i]>ratings[i-1] ? cand[i-1] : 0) : 0;
      int right = i+1<n ? (ratings[i]>ratings[i+1] ? cand[i+1] : 0) : 0;
      cand[i] = 1 + max(left, right);
    }
    // prints(cand);
    return accumulate(cand.begin(), cand.end(), 0);
  }
};

int main(){
  auto sol = Solution();
  vector<int> v = {1,6,5,3,4,2};
  prints(v);
  sol.candy(v);
}
