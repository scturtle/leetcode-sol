using ll = long long;
class Solution {
public:
  int computeArea(ll A, ll B, ll C, ll D, ll E, ll F, ll G, ll H) {
    ll total = (C-A)*(D-B) + (G-E)*(H-F);
    ll w = min(C, G) - max(A, E);
    if(w < 0) w = 0;
    ll h = min(H, D) - max(B, F);
    if(h < 0) h = 0;
    return (int)(total - h*w);
  }
};
