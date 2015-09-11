// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
  int firstBadVersion(int n) {
    if(isBadVersion(1)) return 1;
    long long l=1, r=n;
    while(l+1 != r){
      long long m = (l+r) / 2;
      if(isBadVersion(m))
        r = m;
      else
        l = m;
    }
    return r;
  }
};
