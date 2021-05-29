#include <vector>

using namespace std;
class Solution {
public:
  int search(vector<int> &nums, int target) {
    int lo = 0, hi = nums.size() - 1;

    while (lo <= hi) {
      int mid = (lo + hi) / 2;
      if (nums[mid] == target) {
        return mid;
      }

      if (nums[mid] >= nums[0]) { // where is mid
        if (nums[mid] < target ||
            target < nums[0]) { // change according to the place of target
          lo = mid + 1;
        } else /* TODO : */ {
          hi = mid - 1;
        }
      }

      else { // nums[mid] < nums[0]
        if (nums[mid] > target || target >= nums[0]) {
          hi = mid - 1;
        } else {
          lo = mid + 1;
        }
      }
    }

    return -1;
  }
};
