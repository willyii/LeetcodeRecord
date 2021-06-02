#include <vector>

using namespace std;

class Solution {

  int helper(vector<int> &nums, int target, bool left) {
    int lo = 0, hi = nums.size() - 1;

    while (lo <= hi) {
      int mid = (lo + hi) / 2;
      if (nums[mid] < target || (nums[mid] == target && !left)) {
        lo = mid + 1;
      } else {
        hi = mid - 1;
      }
    }

    return left ? lo : hi;
  }

public:
  vector<int> searchRange(vector<int> &nums, int target) {
    int left = helper(nums, target, true);

    if (left >= nums.size() || nums[left] != target)
      return {-1, -1};

    int right = helper(nums, target, false);

    return {left, right};
  }
};
