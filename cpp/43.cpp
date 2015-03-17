#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <utility>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <climits>
#include <numeric>
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
  string multiply(string num1, string num2) {
    int n1 = num1.length(), n2 = num2.length();
    int n3 = n1 + n2;
    int res[n3];
    for(int i=0; i<n3; i++)
      res[i] = 0;
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    for(int i=0; i<n1; i++)
      for(int j=0; j<n2; j++){
        int t = (num1[i] - '0') * (num2[j] - '0');
        res[i+j] += t;
      }
    int addition = 0;
    for(int i=0; i<n3; i++){
      res[i] += addition;
      addition = res[i] / 10;
      res[i] = res[i] % 10;
    }
    int j = n3 - 1;
    string ans;
    while(res[j] == 0 && j >= 0) j--;
    if(j == -1) return "0";
    for(; j >=0; j--) ans += to_string(res[j]);
    return ans;
  }
};

int main(){
  auto sol = Solution();
  cout << sol.multiply("0", "0");
}
