// struct ListNode {
// int val;
// ListNode *next;
// ListNode() : val(0), next(nullptr) {}
// ListNode(int x) : val(x), next(nullptr) {}
// ListNode(int x, ListNode *next) : val(x), next(next) {}
//};

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *ans = new ListNode(), *ans_head = ans;
    bool carry = false;

    while (l1 != nullptr || l2 != nullptr) {
      if (l1 == nullptr) {
        int add = l2->val + carry;
        ans->next = new ListNode(add % 10);
        carry = (add >= 10);
        ans = ans->next;
        l2 = l2->next;
      } else if (l2 == nullptr) {
        int add = l1->val + carry;
        ans->next = new ListNode(add % 10);
        carry = (add >= 10);
        ans = ans->next;
        l1 = l1->next;
      } else {
        int add = l1->val + carry + l2->val;
        ans->next = new ListNode(add % 10);
        carry = (add >= 10);
        ans = ans->next;
        l1 = l1->next;
        l2 = l2->next;
      }
    }

    if (carry) {
      ans->next = new ListNode(1);
    }

    return ans_head->next;
  }
};
