#include <set>
#include <string>
using namespace std;

class Solution {
public:
  bool isHappy(int n) {
    set<int> saw;
    while(saw.find(n) == saw.end()){
      if(n == 1) return true;
      saw.insert(n);
      int t = 0;
      for(char c : to_string(n))
        t += (c-48) * (c-48);
      n = t;
    }
    return false;
  }
};
