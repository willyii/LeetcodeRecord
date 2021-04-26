#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    if (s.length() == 0 || s.length() == 1)
      return s.length();

    unordered_map<char, int> memo;
    for (auto c : s)
      memo[c] = 0;

    int l = 0, r = 0, ans = 1;
    while (r < s.length()) {
      memo[s[r]] += 1;

      while (memo[s[r]] > 1) {
        memo[s[l++]] -= 1;
      }

      r++;
      ans = max(ans, r - l);
    }

    return ans;
  }
};
