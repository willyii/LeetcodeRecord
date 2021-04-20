/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

/**
 * Using an bool "carry" to indicate should add one or not. Then go over every
 * digit.
 */
class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *ans = new ListNode(), *ans_head = ans;
    bool carry = false;
    while (l1 != nullptr || l2 != nullptr) {
      if (l1 != nullptr && l2 != nullptr) {
        int add = l1->val + l2->val + carry;
        carry = (add >= 10);
        ans->next = new ListNode(add % 10);
        l1 = l1->next;
        l2 = l2->next;
      } else if (l1 == nullptr) {
        int add = l2->val + carry;
        carry = (add >= 10);
        ans->next = new ListNode(add % 10);
        l2 = l2->next;
      } else {
        int add = l1->val + carry;
        carry = (add >= 10);
        ans->next = new ListNode(add % 10);
        l1 = l1->next;
      }
      ans = ans->next;
    }
    if (carry) {
      ans->next = new ListNode(1);
    }
    return ans_head->next;
  }
};
