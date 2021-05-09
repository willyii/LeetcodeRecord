#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    sort(begin(nums), end(nums));
    vector<vector<int>> ans;
    int sum;

    for (int i = 0; i < nums.size() && nums[i] <= 0; i++) {
      if (i == 0 || nums[i] != nums[i - 1]) {
        int lo = i + 1, hi = nums.size() - 1;
        while (lo < hi) {
          sum = nums[lo] + nums[hi] + nums[i];
          if (sum > 0)
            hi--;
          else if (sum < 0)
            lo++;
          else {
            ans.push_back({nums[i], nums[lo], nums[hi]});
            lo++;
            while (lo < hi && nums[lo] == nums[lo - 1]) {
              lo++;
            }
          }
        }
      }
    }

    return ans;
  }
};
