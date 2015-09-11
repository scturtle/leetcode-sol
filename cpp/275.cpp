#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
  int hIndex(vector<int>& citations) {
    int n = citations.size();
    if(n == 0 || citations[n-1] == 0)
      return 0;
    if(citations[0] >= n)
      return n;
    int l=0, r=n-1;
    while(l+1 != r){
      int m = (l+r) / 2;
      if(citations[m] >= n-m)
        r = m;
      else
        l = m;
    }
    return n-r;
  }
};

int main(){
  Solution sol = Solution();
  vector<int> v{0, 1, 3, 5, 6};
  cout << sol.hIndex(v) << endl;
}
