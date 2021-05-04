#include <climits>

using namespace std;

class Solution {
public:
  bool isPalindrome(int x) {

    if (x < 0)
      return false;
    else if (x >= 0 && x <= 9)
      return true;

    int revserve = 0, tmp = x;
    while (x != 0) {
      if (revserve > INT_MAX / 10 ||
          (revserve == INT_MAX && x % 10 > INT_MAX % 10))
        return false;
      revserve = revserve * 10 + (x % 10);
      x = x / 10;
    }

    return revserve == tmp;
  }
};
