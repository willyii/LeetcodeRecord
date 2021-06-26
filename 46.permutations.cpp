#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> permute(vector<int> &nums) {
    if (nums.size() == 1) {

      return {nums};
    }

    vector<vector<int>> ans;

    for (int num : nums) {
      vector<int> next_nums;
      for (int num2 : nums) {
        if (num != num2) {
          next_nums.push_back(num2);
        }
      }

      vector<vector<int>> next_ans = permute(next_nums);

      for (auto element : next_ans) {
        ans.push_back(element);
        ans.back().push_back(num);
      }
    }

    return ans;
  }
};
