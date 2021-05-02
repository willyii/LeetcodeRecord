// cabbad
// 0  ^ 5

#include <string>

using namespace std;

class Solution {

public:
  string longestPalindrome(string s) {

    if (s.size() == 0 || s.size() == 1)
      return s;

    string ans;
    int best_length = 0;

    for (int i = 0; i < s.length(); i++) {
      // i is the middle of substr
      int tmp_l = i, tmp_r = i;
      while (tmp_l >= 0 && tmp_r < s.length() && s[tmp_l] == s[tmp_r]) {
        tmp_l--;
        tmp_r++;
      }
      if (tmp_r - tmp_l - 1 > best_length) {
        best_length = tmp_r - tmp_l - 1;
        ans = s.substr(tmp_l + 1, best_length);
      }

      // i  and  i + 1 are middle of substr
      tmp_l = i, tmp_r = i + 1;
      while (tmp_l >= 0 && tmp_r < s.length() && s[tmp_l] == s[tmp_r]) {
        tmp_l--;
        tmp_r++;
      }
      if (tmp_r - tmp_l - 1 > best_length) {
        best_length = tmp_r - tmp_l - 1;
        ans = s.substr(tmp_l + 1, best_length);
      }
    }

    return ans;
  }
};
