#include <algorithm>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {

  vector<vector<int>> twoSum(vector<int> &nums, int target, int start) {
    unordered_set<int> seen;
    vector<vector<int>> ans;
    for (int i = start; i < nums.size(); i++) {

      int complement = target - nums[i];
      if (seen.count(complement) != 0) {
        ans.push_back({nums[i], complement});
        seen.insert(nums[i]);
        while (i < nums.size() - 1 && nums[i] == nums[i + 1]) {
          i++;
        }
      } else {
        seen.insert(nums[i]);
      }
    }
    return ans;
  }

  vector<vector<int>> kSum(vector<int> &nums, int target, int k, int start) {
    if (k == 2)
      return twoSum(nums, target, start);

    // special case
    if (start == nums.size() || nums[start] * k > target ||
        target > nums.back() * k)
      return {};

    vector<vector<int>> ans;
    for (int i = start; i < nums.size(); i++) {

      if (i != start && nums[i] == nums[i - 1])
        continue;

      vector<vector<int>> tmp = kSum(nums, target - nums[i], k - 1, i + 1);
      for (vector<int> element : tmp) {
        ans.push_back(element);
        ans.back().push_back(nums[i]);
      }
    }

    return ans;
  }

public:
  vector<vector<int>> fourSum(vector<int> &nums, int target) {
    sort(nums.begin(), nums.end());
    return kSum(nums, target, 4, 0);
  }
};
