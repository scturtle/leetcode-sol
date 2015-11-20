#include <string>
#include <iostream>
using namespace std;

int len(long long n){
  int l = 1;
  long long t = 10;
  while(1){
    if(n < t)
      return l;
    l += 1;
    t *= 10;
  }
}

class Solution {
public:
  bool isAdditiveNumber(string num) {
    int n = num.size();
    if(n < 3)
      return false;
    long long n1 = 0;
    for(int i1 = 0; i1 < n-2; i1++){
      n1 = n1 * 10 + num[i1] - 48;
      if(i1 > 0 && num[0] == '0')
        return false;
      long long n2 = 0;
      for(int i2 = i1+1; i2 < n-1; i2++){
        n2 = n2 * 10 + num[i2] - 48;
        if(i2 - i1 > 1 && num[i1+1] == '0')
          continue;
        int i3 = i2 + 1;
        long long pre = n2, n3 = n1 + n2;
        int l = len(n3);
        while(i3 + l <= n){
          long long t3 = 0;
          for(int j=i3; j<i3+l; j++)
            t3 = 10 * t3 + num[j] - 48;
          if(t3 != n3)
            break;
          n3 = pre + n3;
          pre = t3;
          i3 += l;
          l = len(n3);
        }
        if(i3 == n)
          return true;
      }
    }
    return false;
  }
};

int main(){
  cout << Solution().isAdditiveNumber("121474836472147483648");
}
