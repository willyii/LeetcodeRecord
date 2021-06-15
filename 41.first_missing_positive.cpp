#include <vector>

using namespace std;

class Solution {
public:
  int firstMissingPositive(vector<int> &nums) {
    bool find_one = false;

    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == 1)
        find_one = true;

      if (nums[i] <= 0 || nums[i] > nums.size()) {
        nums[i] = 1;
      }
    }

    if (!find_one)
      return 1;

    for (int i = 0; i < nums.size(); i++) {
      nums[abs(nums[i]) - 1] = -1 * abs(nums[abs(nums[i]) - 1]);
    }

    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] > 0) {
        return i + 1;
      }
    }
    return nums.size() + 1;
  }
};
