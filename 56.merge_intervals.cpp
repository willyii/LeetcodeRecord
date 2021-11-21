#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans = {intervals[0]};
    for (int i = 1; i < intervals.size(); i++) {
      if (overLaped(ans.back(), intervals[i])) {
        ans.back()[1] = max(ans.back()[1], intervals[i][1]);
      } else {
        ans.push_back(intervals[i]);
      }
    }
    return ans;
  }

private:
  bool overLaped(vector<int> &interval1, vector<int> &interval2) {
    return interval2[0] <= interval1[1];
  }
};
