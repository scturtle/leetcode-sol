#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  bool isPalindrome(ListNode *head) {
    vector<int> v;
    while (head) {
      v.push_back(head->val);
      head = head->next;
    }
    int n = v.size();
    for (int i = 0; i < n / 2; i++)
      if(v[i] != v[n-1-i])
        return false;
    return true;
  }
};
