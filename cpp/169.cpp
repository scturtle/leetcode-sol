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
    int majorityElement(vector<int> &num) {
        int cnt = 0;
        int ans;
        for(int i=0; i<num.size(); i++){
            if(cnt == 0)
                ans = num[i];
            cnt += num[i] == ans ? 1 : -1;
        }
        return ans;
    }
};

int main(){
  auto sol = Solution();
}
