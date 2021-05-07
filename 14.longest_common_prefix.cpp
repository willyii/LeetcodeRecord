#include <string>
#include <vector>

using namespace std;

class Solution {
  string prefixOfTwo(string &w1, string &w2) {
    string ret = "";
    for (int i = 0; i < min(w1.length(), w2.length()); i++) {
      if (w1[i] == w2[i])
        ret.push_back(w1[i]);
      else
        break;
    }

    return ret;
  }

public:
  string longestCommonPrefix(vector<string> &strs) {
    if (strs.size() == 1)
      return strs[0];

    string ans = prefixOfTwo(strs[0], strs[1]);

    for (int i = 2; i < strs.size(); i++) {
      ans = prefixOfTwo(ans, strs[i]);
    }

    return ans;
  }
};
