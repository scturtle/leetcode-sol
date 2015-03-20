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
#include <sstream>
using namespace std;

template<typename T>
void prints(vector<T> &v){
  cout << "[";
  for(uint i=0; i<v.size()-1; ++i)
    cout << v[i] << ", ";
  if(v.size()) cout << v[v.size()-1];
  cout << "]\n";
}

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  int findPeakElement(const vector<int> &num) {
    int n = num.size();
    int l = 0, r = n;
    while(r - l > 2){
      int m = (l + r) / 2;
      int ml = num[m-1], mm = num[m], mr= num[m+1];
      if(ml < mm && mr < mm)
        l = m, r = m+1;
      else if(ml > mm)
        r = m+1;
      else
        l = m;
    }
    if(l+1 == r)
      return l;
    else
      return num[l] > num[l+1] ? l : l+1;
  }
};

int main(){
  auto sol = Solution();
  vector<int> v = {4, 3, 2};
  cout << sol.findPeakElement(v);
}
