#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
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
    vector<int> twoSum(vector<int> &numbers, int target) {
      vector<pair<int, int>> ns;
      for(uint i=0; i<numbers.size(); i++){
        ns.push_back(make_pair(numbers[i], i));
      }
      sort(ns.begin(), ns.end());
      int l = 0, r = ns.size() - 1;
      while(l < r){
        int t = ns[l].first + ns[r].first;
        if(t == target){
          if(ns[l].second < ns[r].second)
            return vector<int>{ns[l].second+1, ns[r].second+1};
          else
            return vector<int>{ns[r].second+1, ns[l].second+1};
        }
        else if (t < target) ++l;
        else --r;
      }
      return vector<int>();
    }
};

int main(){
  auto sol = Solution();
  auto v = vector<int>{2, 7, 11, 15};
  prints(v);
  auto res = sol.twoSum(v, 9);
  prints(res);
}
