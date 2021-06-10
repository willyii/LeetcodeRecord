#include <string>

using namespace std;
class Solution {
public:
  string countAndSay(int n) {
    if (n == 1) {
      return "1";
    }

    string prev = countAndSay(n - 1), ans = "";
    int count = 1;
    char flag = prev[0];

    for (int i = 1; i < prev.length(); i++) {
      if (prev[i] == prev[i - 1]) {
        count++;
        continue;
      }
      ans += to_string(count);
      ans += flag;
      count = 1;
      flag = prev[i];
    }

    ans += to_string(count);
    ans += flag;

    return ans;
  }
};
