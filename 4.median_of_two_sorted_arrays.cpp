
//  1 ,3       , 4
//  2,      5, 6, 7
//
//  (m + n + 1)/ 2
//
//  idx1 = 2
//  idx2 = 2
//
#include <vector>

using namespace std;

class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    if (nums1.size() > nums2.size())
      return findMedianSortedArrays(nums2, nums1);

    int m = nums1.size(), n = nums2.size(), half = (m + n + 1) / 2;
    int l = 0, r = nums1.size();

    while (l <= r) {
      int pos1 = l + (r - l) / 2;
      int pos2 = half - pos1;

      double left_1 = (pos1 == 0) ? INT_MIN : nums1[pos1 - 1];
      double right_1 = (pos1 == m) ? INT_MAX : nums1[pos1];

      double left_2 = (pos2 == 0) ? INT_MIN : nums2[pos2 - 1];
      double right_2 = (pos2 == n) ? INT_MAX : nums2[pos2];

      // find separate point
      if (right_2 >= left_1 && left_2 <= right_1) {
        if ((m + n) % 2 == 1) { // odd element
          return max(left_1, left_2);
        } else { // even
          return (max(left_1, left_2) + min(right_1, right_2)) / 2.0;
        }
      } else if (right_1 < left_2) {
        // mid point too small
        l = pos1 + 1;
      } else {
        // mid point too large
        r = pos1 - 1;
      }
    }
    return 0;
  }
};
