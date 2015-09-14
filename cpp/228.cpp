#include<vector>
#include<string>
#include<utility>
using namespace std;

class Solution {
public:
  vector<string> summaryRanges(vector<int>& nums) {
    vector<pair<int, int>> rg;
    for(int n : nums)
      if(!rg.empty() && rg[rg.size()-1].second+1 == n)
        ++rg[rg.size()-1].second;
      else
        rg.push_back({n, n});
    vector<string> res;
    for(auto p : rg){
      int i=p.first, j=p.second;
      if(i == j)
        res.push_back(to_string(i));
      else
        res.push_back(to_string(i)+"->"+to_string(j));
    }
    return res;
  }
};
