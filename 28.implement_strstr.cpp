#include <string>

using namespace std;

class Solution {
public:
  int strStr(string haystack, string needle) {
    if (haystack.size() < needle.size()) {
      return -1;
    }

    if (haystack == needle || needle.size() == 0) {
      return 0;
    }

    for (int i = 0; i < haystack.size() - needle.size() + 1; i++) {
      bool match = true;
      for (int j = 0; j < needle.size(); j++) {
        if (needle[j] != haystack[i + j]) {
          match = false;
          break;
        }
      }
      if (match) {
        return i;
      }
    }
    return -1;
  }
};
