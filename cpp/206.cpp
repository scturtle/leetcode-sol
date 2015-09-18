struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  ListNode *reverseList(ListNode *head, ListNode* tail) {
    if(head == nullptr)
      return tail;
    else{
      ListNode *rest = head->next;
      head->next = tail;
      return reverseList(rest, head);
    }
  }

public:
  ListNode *reverseList(ListNode *head) {
    return reverseList(head, nullptr);
  }
};
