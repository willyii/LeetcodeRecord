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
  void reverseList(ListNode *head) {
    if (!head->next->next) {
      head->next->next = head;
      head->next = nullptr;
      return;
    }

    ListNode *first = head, *second = first->next, *third = second->next;
    while (second) {
      second->next = first;
      first = second;
      second = third;
      if (third) {
        third = third->next;
      }
    }
    return;
  }

public:
  ListNode *reverseKGroup(ListNode *head, int k) {
    if (!head || k == 1) {
      return head;
    }

    ListNode *end = head;
    for (int i = 1; i < k && end; i++) {
      end = end->next;
    }
    if (!end) {
      return head;
    }

    ListNode *sub_ans = reverseKGroup(end->next, k);
    end->next = nullptr;

    reverseList(head);
    head->next = sub_ans;

    return end;
  }
};
