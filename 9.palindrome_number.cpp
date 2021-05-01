#include <climits>

using namespace std;
class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0)
      return false;
    if (x < 10)
      return true;

    long int pop = 0;
    long int remain = x;
    while (remain) {
      if (pop > INT_MAX / 10 ||
          (pop == INT_MAX / 10 && (remain % 10) > (INT_MAX % 10)))
        return false;
      pop = pop * 10 + (remain % 10);
      remain = remain / 10;
    }
    return pop == x;
  }
};
