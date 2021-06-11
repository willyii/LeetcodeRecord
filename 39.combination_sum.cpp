#include <algorithm>
#include <vector>

using namespace std;

typedef vector<vector<int>> ans_type;

class Solution {

  ans_type helper(vector<int> &candidates, int target, int idx) {
    if (target < 0 || idx == candidates.size()) {
      return {};
    }
    if (target == candidates[idx]) {
      return {{candidates[idx]}};
    }

    ans_type ans1 = helper(candidates, target, idx + 1);
    ans_type ans2 = helper(candidates, target - candidates[idx], idx);

    for (vector<int> element : ans2) {
      ans1.push_back(element);
      ans1.back().push_back(candidates[idx]);
    }

    return ans1;
  }

public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end());
    return helper(candidates, target, 0);
  }
};
