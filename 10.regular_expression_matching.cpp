// "abc" "abc" => "bc" "bc"
// "abc" ".bc" => "bc" "bc"
// "abc" "a*bc" => (abc bc) || (bc a*bc)
//
#include <string>

using namespace std;
// i, j => Match(s[i:] , p[j:])
//
enum Status { NotVisited, True, False };

class Solution {
  Status memo[21][31];

public:
  bool isMatch(string s, string p) { return dp(0, 0, s, p); }

  bool dp(int i, int j, string s, string p) {
    if (memo[i][j] != NotVisited) {
      return memo[i][j] == True ? true : false;
    }

    bool ans;
    if (i == s.length() && j == p.length())
      ans = true;
    else if (i > s.length() || j > p.length())
      ans = false;
    else {
      bool first_match = (s[i] == p[j] || p[j] == '.');
      if (j + 1 < p.length() && p[j + 1] == '*') {
        ans = (dp(i, j + 2, s, p)) || (first_match && dp(i + 1, j, s, p));
      } else {
        ans = first_match && dp(i + 1, j + 1, s, p);
      }
    }
    memo[i][j] = ans ? True : False;
    return ans;
  }
};
