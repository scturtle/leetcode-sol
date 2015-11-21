class Solution {
public:
  string getHint(string secret, string guess) {
    int a[10] = {0}, b[10] = {0};
    int A = 0, B = 0;
    for(int i=0; i<secret.size(); i++)
      if(secret[i] == guess[i])
        A++;
      else
        a[secret[i]-48]++, b[guess[i]-48]++;
    for(int i=0; i<10; i++)
      B += a[i] < b[i] ? a[i] : b[i];
    return to_string(A)+"A"+to_string(B)+"B";
  }
};
