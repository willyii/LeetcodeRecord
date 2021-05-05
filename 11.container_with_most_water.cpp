#include <vector>

using namespace std;

class Solution {
public:
  int maxArea(vector<int> &height) {
    int l = 0, r = height.size() - 1;
    int ans = INT_MIN;

    while (l <= r) {
      ans = max(ans, (r - l) * (min(height[l], height[r])));
      if (height[l] <= height[r])
        l++;
      else
        r--;
    }

    return ans;
  }
};
