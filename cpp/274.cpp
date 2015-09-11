#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
  int hIndex(vector<int>& citations) {
    int n = citations.size();
    sort(citations.begin(), citations.end(), greater<int>());
    if(n == 0 || citations[0] == 0)
      return 0;
    if(citations[n-1] >= n)
      return n;
    int l=0, r=n-1;
    while(l+1 != r){
      int m = (l+r) / 2;
      if(citations[m] < m+1)
        r = m;
      else
        l = m;
    }
    return l+1;
  }
};

int main(){
  Solution sol = Solution();
  vector<int> v{3, 0, 6, 1, 5};
  cout << sol.hIndex(v) << endl;
}
