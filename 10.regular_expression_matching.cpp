#include <string>

using namespace std;

enum Status { NotVisited, True, False };

class Solution {

  Status memo[30][30];

public:
  bool isMatch(string s, string p) { return dp(0, 0, s, p); }

  bool dp(int i, int j, string s, string p) {

    if (memo[i][j] != NotVisited)
      return memo[i][j] == True;

    bool ans;
    if (j == p.length() && i == s.length())
      ans = true;
    else if (j > p.length() || i > s.length())
      ans = false;
    else {
      bool first_match = (s[i] == p[j] || p[j] == '.');
      if (j + 1 < p.length() && p[j + 1] == '*') {
        ans = (first_match && dp(i + 1, j, s, p)) || dp(i, j + 2, s, p);
      } else {
        ans = first_match && dp(i + 1, j + 1, s, p);
      }
    }
    memo[i][j] = ans ? True : False;

    return ans;
  }
};
