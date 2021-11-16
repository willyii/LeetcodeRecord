#include <vector>

using namespace std;

class Solution {
public:
  bool canJump(vector<int> &nums) {
    int pos = 0, end = pos + nums[0];
    while (pos <= end) {
      end = max(end, pos + nums[pos]);
      pos++;
      if (end >= nums.size() - 1)
        return true;
    }
    return false;
  }
};
