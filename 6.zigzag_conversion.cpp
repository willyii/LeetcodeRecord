// -----------
// 3 rows
// -----------
// 0   1   2
//     3
// 4   5   6
//     7
// 8   9   10

// -----------
// 4 rows
// -----------
// 0   1   2   3
//         4
//     5
// 6   7   8   9
//         10
//    11
// 12  13  14  15
//
// n rows, index change (n-1) * 2

#include <string>

using namespace std;

class Solution {
public:
  string convert(string s, int numRows) {

    if (numRows == 1 || numRows >= s.length())
      return s;

    string ans = "";
    int left_step = (numRows - 1) * 2, right_step = 0;

    for (int i = 0; i < numRows; i++) {
      int idx = i;
      while (idx < s.length()) {
        if (left_step != 0 && idx < s.length()) {
          ans.push_back(s[idx]);
          idx += left_step;
        }
        if (right_step != 0 && idx < s.length()) {
          ans.push_back(s[idx]);
          idx += right_step;
        }
      }
      left_step -= 2;
      right_step += 2;
    }
    return ans;
  }
};
