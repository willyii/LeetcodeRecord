#include <set>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> permuteUnique(vector<int> &nums) {
    if (nums.size() == 1) {
      return {nums};
    }

    set<int> visited;
    vector<vector<int>> ans;

    for (int i = 0; i < nums.size(); i++) {
      if (visited.count(nums[i]) != 0) {
        continue;
      }
      vector<int> next_nums;
      for (int j = 0; j < nums.size(); j++) {
        if (j == i) {
          continue;
        }
        next_nums.push_back(nums[j]);
      }

      vector<vector<int>> next_ans = permuteUnique(next_nums);

      for (auto element : next_ans) {
        ans.push_back(element);
        ans.back().push_back(nums[i]);
      }

      visited.insert(nums[i]);
    }

    return ans;
  }
};
