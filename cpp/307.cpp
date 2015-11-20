#include <vector>
#include <iostream>
using namespace std;

struct Node {int l, r, s;};

class NumArray {
  Node tree[100000];

  void build(int l, int r, vector<int> &nums, int rt){
    tree[rt].l = l;
    tree[rt].r = r;
    if(l == r)
      tree[rt].s = nums[l];
    else{
      int m = (l + r) / 2;
      build(l, m, nums, 2*rt);
      build(m+1, r, nums, 2*rt+1);
      tree[rt].s = tree[2*rt].s + tree[2*rt+1].s;
    }
  }

public:
  NumArray(vector<int> &nums) {
    if(nums.empty()) return;
    build(0, nums.size()-1, nums, 1);
  }

  void update(int i, int val, int rt=1) {
    if(tree[rt].l == tree[rt].r){
      tree[rt].s = val;
      return;
    }
    int m = (tree[rt].l + tree[rt].r) / 2;
    if(i <= m)
      update(i, val, rt*2);
    else
      update(i, val, rt*2+1);
    tree[rt].s = tree[rt*2].s + tree[rt*2+1].s;
  }

  int sumRange(int i, int j, int rt=1) {
    if (i == tree[rt].l && j == tree[rt].r)
      return tree[rt].s;
    int m = (tree[rt].l + tree[rt].r) / 2;
    if(j <= m)
      return sumRange(i, j, rt*2);
    else if(i > m)
      return sumRange(i, j, rt*2+1);
    else return sumRange(i, m, rt*2) + sumRange(m+1, j, rt*2+1);
  }
};

int main(){
  vector<int> v {1, 3, 5};
  NumArray sa(v);
  cout << sa.sumRange(0, 2) << endl;
}
