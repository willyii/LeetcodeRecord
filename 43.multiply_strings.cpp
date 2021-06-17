#include <string>

using namespace std;

class Solution {
  int charToInt(char c) { return c - '0'; }

  void addToAns(string &ans, int addon, int idx) {
    while (addon > 0) {
      addon += charToInt(ans[idx]);
      ans[idx] = char(addon % 10 + '0');
      idx--;
      addon /= 10;
    }
  }

public:
  string multiply(string num1, string num2) {

    if (num1 == "0" || num2 == "0") {
      return "0";
    }
    string ans = string(num1.length() + num2.length(), '0');

    for (int idx1 = num1.length() - 1; idx1 >= 0; idx1--) {
      for (int idx2 = num2.length() - 1; idx2 >= 0; idx2--) {
        int start_idx = idx1 + idx2 + 1;
        addToAns(ans, charToInt(num1[idx1]) * charToInt(num2[idx2]), start_idx);
      }
    }

    // remove leading zero
    ans.erase(0, ans.find_first_not_of("0"));

    return ans;
  }
};
