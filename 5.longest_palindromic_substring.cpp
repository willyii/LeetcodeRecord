#include <string>

using namespace std;

class Solution {

public:
  string longestPalindrome(string s) {
    string ans;

    for (int idx = 0; idx < s.size(); idx++) {

      // idx at center
      int tmp_l = idx, tmp_r = idx;
      while (tmp_l >= 0 && tmp_r < s.size() && s[tmp_l] == s[tmp_r]) {
        tmp_l--;
        tmp_r++;
      }
      if ((tmp_r - tmp_l - 1) > ans.length())
        ans = s.substr(tmp_l + 1, tmp_r - tmp_l - 1);

      // idx and idx +1
      tmp_l = idx, tmp_r = idx + 1;
      while (tmp_l >= 0 && tmp_r < s.size() && s[tmp_l] == s[tmp_r]) {
        tmp_l--;
        tmp_r++;
      }
      if (tmp_r - tmp_l - 1 > ans.length())
        ans = s.substr(tmp_l + 1, tmp_r - tmp_l - 1);
    }
    return ans;
  }
};
