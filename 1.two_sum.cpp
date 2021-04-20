#include <unordered_map>
#include <vector>

using namespace std;

/**
 * Use a hashmap to store the map from value to index. Go through every element,
 * use hashmap to check if "diff" met or not. If met, save the answer.
 */
class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> memo; // Map value to index
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++) {
      int diff = target - nums[i];
      if (memo.find(diff) != memo.end()) {
        ans.emplace_back(memo[diff]);
        ans.emplace_back(i);
        break;
      }
      memo[nums[i]] = i;
    }
    return ans;
  }
};
