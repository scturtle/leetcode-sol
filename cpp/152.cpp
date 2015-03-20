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

class Solution {
public:
  int _maxProduct(int A[], int i, int j, int &tot, int &lmx, int &lmi, int &rmx, int &rmi){
    if(j - i == 1){
      tot = lmx = lmi = rmx = rmi = A[i];
      return A[i];
    }
    int m = (i+j)/2;
    int ltot, llmx, llmi, lrmx, lrmi, lres;
    lres = _maxProduct(A, i, m, ltot, llmx, llmi, lrmx, lrmi);
    int rtot, rlmx, rlmi, rrmx, rrmi, rres;
    rres = _maxProduct(A, m, j, rtot, rlmx, rlmi, rrmx, rrmi);

    tot = ltot * rtot;
    lmx = max(llmx, max(ltot * rlmx, ltot * rlmi));
    lmi = min(llmi, min(ltot * rlmx, ltot * rlmi));
    rmx = max(rrmx, max(rtot * lrmx, rtot * lrmi));
    rmi = min(rrmi, min(rtot * lrmx, rtot * lrmi));
    int res = max(max(lres, rres), max(lrmx * rlmx, lrmi * rlmi));
    return res;
  }
  int maxProduct(int A[], int n) {
    int tmp;
    return _maxProduct(A, 0, n, tmp, tmp, tmp, tmp, tmp);
  }
};

int main(){
  auto sol = Solution();
  int a[3] = {-4, -3, -2};
  cout << sol.maxProduct(a, 3);
}
