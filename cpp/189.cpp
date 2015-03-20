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
  int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
  void rotate(int nums[], int n, int k) {
    // permutation group
    k %= n;
    if(k == 0) return;
    int groups = gcd(n, k);
    for(int i=0; i<groups; i++){
      int v = nums[i], w;
      int j = (i + k) % n;
      do {
        w = nums[j]; nums[j] = v; v = w;
        j = (j + k) % n;
      } while(j != (i + k) % n);
    }
  }
};

int main(){
  auto sol = Solution();
  int a[6] = {1,2,3,4,5,6};
  sol.rotate(a, 6, 4);
  for(int i=0; i<6; i++)
    cout << a[i] << " ";
}
