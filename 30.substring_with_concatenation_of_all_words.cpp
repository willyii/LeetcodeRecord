#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> findSubstring(string s, vector<string> &words) {

    int wordLength = words[0].length(), numOfWord = words.size();
    vector<int> ans;

    if (s.length() < wordLength * numOfWord) {
      return ans;
    }

    // memo
    unordered_map<string, int> memo;
    for (string word : words) {
      if (memo.find(word) == memo.end()) {
        memo[word] = 1;
      } else
        memo[word]++;
    }

    for (int i = 0; i < s.length() - (wordLength * numOfWord) + 1;
         i++) { // start index
      // check index valid or not
      unordered_map<string, int> usedWord;

      // for every single substring
      for (int j = i; j < i + (numOfWord * wordLength); j += wordLength) {
        string key = s.substr(j, wordLength);
        if (memo.find(key) == memo.end()) { // not find in memo
          break;
        }

        if (usedWord.find(key) == usedWord.end()) {
          usedWord[key] = 0;
        }
        usedWord[key]++;
      }

      if (usedWord == memo) {
        ans.push_back(i);
      }
    }
    return ans;
  }
};
