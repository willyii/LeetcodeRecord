#include <algorithm>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
  int longestValidParentheses(string str) {
    int ans = 0;
    stack<int> s;
    s.push(-1);

    for (int i = 0; i < str.length(); i++) {
      if (str[i] == '(') {
        s.push(i);
      } else { // s[i] == ')'
        s.pop();
        if (s.empty()) {
          s.push(i);
        }
        ans = max(ans, i - s.top());
      }
    }
    return ans;
  }
};
