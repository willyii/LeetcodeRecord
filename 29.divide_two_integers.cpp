#include <climits>

using namespace std;

int HALF_INT_MIN = INT_MIN / 2;

class Solution {
public:
  int divide(int dividend, int divisor) {
    if (dividend == INT_MIN && divisor == -1) {
      return INT_MAX;
    }

    bool neg_ans = false;
    if (dividend > 0)
      dividend = -dividend;
    else
      neg_ans = !neg_ans;

    if (divisor > 0)
      divisor = -divisor;
    else
      neg_ans = !neg_ans;

    int quotient = 0;
    while (dividend <= divisor) {
      int ans = -1;
      int value = divisor;

      while (value >= HALF_INT_MIN && value + value >= dividend) {
        ans += ans;
        value += value;
      }

      quotient += ans;
      dividend -= value;
    }

    return neg_ans ? quotient : -quotient;
  }
};
