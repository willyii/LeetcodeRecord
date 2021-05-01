#include <climits>
#include <string>

using namespace std;

class Solution {
public:
  int myAtoi(string s) {
    int ans = 0;
    int sign = 1;
    int idx = 0;

    while (idx < s.length() && s[idx] == ' ')
      // leading whitespace
      idx++;

    // leading sign
    if (s[idx] == '-') {
      sign = -1;
      idx++;
    } else if (s[idx] == '+') {
      idx++;
    }

    while (idx < s.length() && s[idx] >= '0' && s[idx] <= '9') {

      // overflow
      if (ans > INT_MAX / 10 ||
          (ans == INT_MAX / 10 && s[idx] - '0' > INT_MAX % 10)) {
        return (sign == 1) ? INT_MAX : INT_MIN;
      }
      ans = ans * 10 + (s[idx++] - '0');
    }

    return ans * sign;
  }
};
