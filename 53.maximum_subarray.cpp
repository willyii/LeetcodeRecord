#include <vector>

using namespace std;

class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int ans = nums[0], current = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      current = max(nums[i] + current, nums[i]);
      ans = max(ans, current);
    }
    return ans;
  }
};
