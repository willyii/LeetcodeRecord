#include <climits>
#include <string>

using namespace std;

class Solution {
public:
  int myAtoi(string s) {
    int ans = 0, idx = 0;

    // Leading whitespace
    while (idx < s.length() && s[idx] == ' ')
      idx++;

    // sign
    int sign = 1;
    if (s[idx] == '-') {
      sign = -1;
      idx++;
    } else if (s[idx] == '+') {
      idx++;
    }

    while (idx < s.length() && s[idx] >= '0' && s[idx] <= '9') {
      // if overflow
      if (ans > INT_MAX / 10 ||
          (ans == INT_MAX / 10 && s[idx] - '0' > INT_MAX % 10))
        return sign == 1 ? INT_MAX : INT_MIN;

      ans = ans * 10 + (s[idx] - '0');
      idx++;
    }

    return ans * sign;
  }
};
