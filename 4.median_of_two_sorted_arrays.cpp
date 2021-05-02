// 1 3 | 5 nums1
// 2 4 | 6  7
#include <vector>

using namespace std;

class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    if (nums1.size() > nums2.size())
      return findMedianSortedArrays(nums2, nums1);

    int m = nums1.size(), n = nums2.size();
    int l = 0, r = m, half = (m + n + 1) / 2;

    while (l <= r) {
      int mid = l + (r - l) / 2;
      int mid2 = half - mid;

      double left_1 = mid == 0 ? INT_MIN : nums1[mid - 1]; // int_min
      double right_1 = mid == m ? INT_MAX : nums1[mid];    // 1

      double left_2 = mid2 == 0 ? INT_MIN : nums2[mid2 - 1]; // 1
      double right_2 = mid2 == n ? INT_MAX : nums2[mid2];    // int_max

      if (right_2 >= left_1 &&
          right_1 >= left_2) { // find the correct partition
        if ((m + n) % 2 == 0)
          return (max(left_2, left_1) + min(right_1, right_2)) / 2.0;
        else
          return max(left_2, left_1);
      } else if (left_2 > right_1) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }

    return 0;
  }
};
