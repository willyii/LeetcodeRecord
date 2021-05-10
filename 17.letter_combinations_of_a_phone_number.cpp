#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  unordered_map<char, vector<string>> keyboard;
  void initKeyboard() {
    keyboard['2'] = {"a", "b", "c"};
    keyboard['3'] = {"d", "e", "f"};
    keyboard['4'] = {"g", "h", "i"};
    keyboard['5'] = {"j", "k", "l"};
    keyboard['6'] = {"m", "n", "o"};
    keyboard['7'] = {"p", "q", "r", "s"};
    keyboard['8'] = {"t", "u", "v"};
    keyboard['9'] = {"w", "x", "y", "z"};
  }

  vector<string> helper(string digits) {
    if (digits.length() == 0)
      return {};
    else if (digits.length() == 1)
      return keyboard[digits[0]];

    vector<string> ans;
    vector<string> sub_ans = helper(digits.substr(1, digits.length()));
    for (string prefix : keyboard[digits[0]]) {
      for (string suffix : sub_ans) {
        ans.push_back(prefix + suffix);
      }
    }
    return ans;
  }

public:
  vector<string> letterCombinations(string digits) {
    initKeyboard();
    return helper(digits);
  }
};
