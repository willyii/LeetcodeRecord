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

class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *tmp_head = new ListNode(0, head);
    ListNode *lo = tmp_head, *hi = tmp_head;

    for (int i = 0; hi != nullptr && i <= n; i++) {
      hi = hi->next;
    }

    while (hi != nullptr) {
      lo = lo->next;
      hi = hi->next;
    }

    lo->next = lo->next->next;

    return tmp_head->next;
  }
};
