#include <stack>
#include <string>

using namespace std;

class Solution {
public:
  bool isValid(string s) {
    stack<char> memo;
    for (char c : s) {
      if (c == '(' || c == '[' || c == '{') {
        memo.push(c);
      } else if (c == ')') {
        if (!memo.empty() && memo.top() == '(')
          memo.pop();
        else
          return false;
      } else if (c == ']') {
        if (!memo.empty() && memo.top() == '[')
          memo.pop();
        else
          return false;
      } else if (c == '}') {
        if (!memo.empty() && memo.top() == '{')
          memo.pop();
        else
          return false;
      }
    }
    return memo.empty();
  }
};
