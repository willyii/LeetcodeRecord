#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    vector<int> ans;
    unordered_map<int, int> memo;
    for (int i = 0; i < nums.size(); i++) {
      int diff = target - nums[i];

      // Find
      if (memo.find(diff) != memo.end()) {
        ans.emplace_back(memo[diff]);
        ans.emplace_back(i);
        return ans;
      }

      memo[nums[i]] = i;
    }

    return ans;
  }
};
