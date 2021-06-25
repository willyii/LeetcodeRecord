#include <vector>

using namespace std;

class Solution {
public:
  int jump(vector<int> &nums) {
    int ans = 0, fursest = 0, jump_end = 0;

    for (int i = 0; i < nums.size() - 1; i++) {
      fursest = max(nums[i] + i, fursest);
      if (i == jump_end) {
        jump_end = fursest;
        ans++;
      }
    }

    return ans;
  }
};
