#include <algorithm>
#include <type_traits>
#include <vector>

using namespace std;

class Solution {
public:
  void nextPermutation(vector<int> &nums) {
    int length = nums.size();
    // find the index x that decrease
    for (int i = length - 2; i >= 0; i--) {
      if (nums[i] >= nums[i + 1]) {
        continue;
      }

      // find the minimal number that larger then index but index larger than x
      int exchange_index = i + 1;
      for (int j = i + 1; j < nums.size(); j++) {
        if (nums[j] > nums[i] && nums[j] < nums[exchange_index]) {
          exchange_index = j;
        }
      }

      // swap
      swap(nums[i], nums[exchange_index]);

      // sort x+1 to the end of nums
      sort(nums.begin() + i + 1, nums.end());

      return;
    }

    sort(nums.begin(), nums.end());
    return;
  }
};
