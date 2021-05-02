
// ----------
// 3 rows
// ----------
// 1   5   9
// 2 4 6 8 10
// 3   7   11

// ----------
// 4 rows
// ----------
// 1     7         13
// 2   6 8      12 14
// 3 5   9   11    15
// 4     10        16

// ----------
// 5 rows
// ----------
// 1       9           17
// 2     8 10       16 18
// 3   7   11    15    19
// 4 6     12 14       20
// 5       13          21

#include <string>

using namespace std;

class Solution {
public:
  string convert(string s, int numRows) {
    if (numRows == 1 || numRows >= s.length())
      return s;

    int step = (numRows - 1) * 2;
    int left_step = step, right_step = 0;
    int row = 0;

    string ans;
    while (row < numRows) {
      int idx = row;
      while (idx < s.size()) {
        if (left_step && idx < s.size()) {
          ans.push_back(s[idx]);
          idx += left_step;
        }
        if (right_step && idx < s.size()) {
          ans.push_back(s[idx]);
          idx += right_step;
        }
      }

      row++;
      left_step -= 2;
      right_step += 2;
    }

    return ans;
  }
};
