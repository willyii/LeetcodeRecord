#include <unordered_map>

using namespace std;

class Solution {
  unordered_map<int, double> memo;

public:
  double myPow(double x, int n) {
    if (memo.find(n) != memo.end())
      return memo[n];

    if (n == 1)
      return x;
    else if (n == -1)
      return 1 / x;
    else if (n == 0)
      return 1;

    int left = n / 2, right = n - left;
    memo[n] = myPow(x, left) * myPow(x, right);
    return memo[n];
  }
};
