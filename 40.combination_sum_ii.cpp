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
      return {{target}};
    }

    ans_type ans1 = helper(candidates, target - candidates[idx], idx + 1);
    ans_type ans2;

    for (int i = idx + 1; i < candidates.size(); i++) {
      if (candidates[i] != candidates[i - 1]) {
        ans2 = helper(candidates, target, i);
        break;
      }
    }

    for (vector<int> element : ans1) {
      ans2.push_back(element);
      ans2.back().push_back(candidates[idx]);
    }

    return ans2;
  }

public:
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end());
    return helper(candidates, target, 0);
  }
};
