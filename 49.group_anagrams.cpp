#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
  string helper(string &s) {
    string ret = "";
    vector<int> memo(26, 0);

    for (char c : s) {
      memo[c - 'a'] += 1;
    }

    // generate ret
    // 1#0#.....
    for (int count : memo) {
      ret += to_string(count) + "#";
    }

    return ret;
  }

public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    vector<vector<string>> ans;
    unordered_map<string, int> key2index; // map key to index
    for (string s : strs) {
      string key = helper(s);
      // if not visited before
      if (key2index.find(key) == key2index.end()) {
        key2index[key] = ans.size();
        ans.push_back({});
      }
      ans[key2index[key]].push_back(s);
    }
    return ans;
  }
};
