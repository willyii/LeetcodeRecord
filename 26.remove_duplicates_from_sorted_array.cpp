#include <vector>

using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    if (nums.size() == 0 || nums.size() == 1) {
      return nums.size();
    }

    int lo = 1, hi = lo;
    while (hi < nums.size() && nums[hi] == nums[hi - 1])
      hi++;

    while (hi < nums.size()) {
      nums[lo++] = nums[hi++];
      while (hi < nums.size() && nums[hi] == nums[hi - 1])
        hi++;
    }

    return lo;
  }
};
