#include <vector>

using namespace std;

class Solution {
public:
  int removeElement(vector<int> &nums, int val) {
    int lo = 0, hi = nums.size() - 1;
    while (hi >= lo && nums[lo] != val) {
      lo++;
    }
    while (hi >= lo && nums[hi] == val) {
      hi--;
    }

    while (lo <= hi) {
      nums[lo++] = nums[hi--];
      while (hi >= lo && nums[lo] != val) {
        lo++;
      }
      while (hi >= lo && nums[hi] == val) {
        hi--;
      }
    }
    return lo;
  }
};
