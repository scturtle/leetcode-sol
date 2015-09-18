struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* removeElements(ListNode* head, int val) {
    ListNode h(0);
    h.next = head;
    ListNode *p = &h;
    while(p->next){
      if(p->next->val == val)
        p->next = p->next->next;
      else
        p = p->next;
    }
    return h.next;
  }
};
