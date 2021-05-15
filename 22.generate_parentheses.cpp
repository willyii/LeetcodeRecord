#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
  unordered_map<string, vector<string>> memo;

  vector<string> helper(int left, int right) {
    if (left == 0 && right == 0) {
      return {};
    }

    string key = to_string(left) + "," + to_string(right);
    if (memo.find(key) != memo.end()) { // visited
      return memo[key];
    }

    vector<string> value;
    // left
    if (left > 0) {
      vector<string> sub_ans = helper(left - 1, right);
      if (sub_ans.size() == 0)
        value.push_back("(");
      else {
        for (string s : sub_ans)
          value.push_back("(" + s);
      }
    }
    // right
    if (right > left) {
      vector<string> sub_ans = helper(left, right - 1);
      if (sub_ans.size() == 0)
        value.push_back(")");
      else {
        for (string s : sub_ans)
          value.push_back(")" + s);
      }
    }

    memo[key] = value;
    return value;
  }

public:
  vector<string> generateParenthesis(int n) { return helper(n, n); }
};
