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

#include <vector>
using namespace std;

/* TODO : comment out  */
// struct ListNode {
// int val;
// ListNode *next;
// ListNode() : val(0), next(nullptr) {}
// ListNode(int x) : val(x), next(nullptr) {}
// ListNode(int x, ListNode *next) : val(x), next(next) {}
//};

class Solution {

  ListNode *merge2Lists(ListNode *left, ListNode *right) {
    if (!left && !right)
      return nullptr;
    if (left && !right)
      return left;
    if (!left && right)
      return right;

    ListNode *head = new ListNode(), *cur = head;
    while (left && right) {
      if (left->val < right->val) {
        cur->next = left;
        left = left->next;
      } else {
        cur->next = right;
        right = right->next;
      }
      cur = cur->next;
    }

    while (left) {
      cur->next = left;
      left = left->next;
      cur = cur->next;
    }
    while (right) {
      cur->next = right;
      right = right->next;
      cur = cur->next;
    }

    return head->next;
  }

  ListNode *helper(vector<ListNode *> &lists, int lo, int hi) {
    if (lo == hi) {
      return lists[lo];
    }

    int mid = lo + (hi - lo) / 2;
    ListNode *left_head = helper(lists, lo, mid);
    ListNode *right_head = helper(lists, mid + 1, hi);
    return merge2Lists(left_head, right_head);
  }

public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {

    int length = lists.size();
    if (length == 0)
      return nullptr;
    return helper(lists, 0, length - 1);
  }
};
