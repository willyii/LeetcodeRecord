#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

/**
 * I plan to use an array with 26 ints to store number of occurance of each
 * char. Then I use two pointer to indicate the left end and right end of
 * subarray.
 */
class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    if (s.size() == 0 || s.size() == 1)
      return s.size();

    unordered_map<char, int> memo;
    for (char c : s)
      memo[c] = 0;
    int left_end = 0, right_end = 0, ans = 1;

    while (right_end < s.size()) {
      memo[s[right_end]] += 1;

      while (memo[s[right_end]] > 1) { // visited
        memo[s[left_end]] -= 1;
        left_end += 1;
      }

      right_end++;
      ans = std::max(ans, right_end - left_end);
    }

    return ans;
  }
};
