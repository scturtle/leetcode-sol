class Solution {
public:
  bool isPowerOfTwo(int a) {
    if(a <= 0) return false;
    return a == (a & (~a + 1));
  }
};
