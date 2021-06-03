#include <vector>

using namespace std;

class Solution {
public:
  int searchInsert(vector<int> &nums, int target) {
    int lo = 0, hi = nums.size() - 1;
    while (lo < nums.size() && hi >= 0 && lo <= hi) {
      int mid = (lo + hi) / 2;
      if (nums[mid] == target) {
        return mid;
      } else if (nums[mid] < target) {
        lo = mid + 1;
      } else {
        hi = mid - 1;
      }
    }

    if (lo < nums.size() && nums[lo] < target) {
      return lo + 1;
    }
    return lo;
  }
};
