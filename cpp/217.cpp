#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
  bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> m;
    for(int n : nums){
      if(m.find(n) != m.end())
        return true;
      m.insert(n);
    }
    return false;
  }
};
