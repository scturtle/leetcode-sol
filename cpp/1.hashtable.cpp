#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <unordered_map>
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
      unordered_map<int, int> m;
      for(int i=0; i<numbers.size(); i++){
        auto res = m.find(target - numbers[i]);
        if(res != m.end())
          return vector<int>{res->second+1, i+1};
        m[numbers[i]] = i;
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
