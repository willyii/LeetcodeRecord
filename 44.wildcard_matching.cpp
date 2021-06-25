#include <string>

using namespace std;

class Solution {
public:
  bool isMatch(string s, string p) {
    int m = s.length(), n = p.length();
    bool dp[m + 1][n + 1];

    for (int i = 0; i < m + 1; i++) {
      for (int j = 0; j < n + 1; j++) {
        if (i == 0 && j == 0) {
          dp[i][j] = true;
        } else if (i == 0) {
          if (p[j - 1] == '*') {
            dp[i][j] = dp[i][j - 1];
          } else {
            dp[i][j] = false;
          }
        } else if (j == 0) {
          dp[i][j] = false;
        }

        else {
          if (s[i - 1] == p[j - 1]) {
            dp[i][j] = dp[i - 1][j - 1];
          } else if (p[j - 1] == '?') {
            dp[i][j] = dp[i - 1][j - 1];
          } else if (p[j - 1] == '*') {
            dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
          } else {
            dp[i][j] = false;
          }
        }
      }
    }

    return dp[m][n];
  }
};
