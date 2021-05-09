#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

class Solution {
public:
  int threeSumClosest(vector<int> &nums, int target) {
    sort(begin(nums), end(nums));
    int ans, distance = INT_MAX;

    for (int i = 0; i < nums.size(); i++) {
      int lo = i + 1, hi = nums.size() - 1;
      // two sum
      while (lo < hi) {
        int sum = nums[i] + nums[lo] + nums[hi];
        int current_distance = abs(sum - target);
        if (current_distance < distance) {
          if (current_distance == 0)
            return target;
          distance = current_distance;
          ans = sum;
        }

        if (sum - target > 0)
          hi--;
        else
          lo++;
      }
    }

    return ans;
  }
};
