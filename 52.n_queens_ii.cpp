#include <string.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
  bool isValid(int row, int col, vector<bool> &cols, vector<bool> &plus,
               vector<bool> &minus) {
    int minus_idx = row - col;
    if (minus_idx < 0)
      minus_idx += minus.size();
    return !cols[col] && !plus[row + col] && !minus[minus_idx];
  }

  void placeQueen(int row, int col, vector<vector<int>> &queens,
                  vector<bool> &cols, vector<bool> &plus, vector<bool> &minus) {
    queens.push_back({row, col});
    cols[col] = true;
    plus[row + col] = true;

    int minus_idx = row - col;
    if (minus_idx < 0)
      minus_idx += minus.size();
    minus[minus_idx] = true;

    return;
  }

  void removeQueen(int row, int col, vector<vector<int>> &queens,
                   vector<bool> &cols, vector<bool> &plus,
                   vector<bool> &minus) {
    queens.pop_back();
    cols[col] = false;
    plus[row + col] = false;

    int minus_idx = row - col;
    if (minus_idx < 0)
      minus_idx += minus.size();
    minus[minus_idx] = false;

    return;
  }

  void helper(int row, vector<bool> &cols, vector<bool> &plus,
              vector<bool> &minus, vector<vector<int>> &queens, int &ans) {
    for (int col = 0; col < cols.size(); col++) {
      if (isValid(row, col, cols, plus, minus)) {
        placeQueen(row, col, queens, cols, plus, minus);
        if (row + 1 == cols.size()) {
          ans++;
        } else {
          helper(row + 1, cols, plus, minus, queens, ans);
        }
        removeQueen(row, col, queens, cols, plus, minus);
      }
    }
    return;
  }

public:
  int totalNQueens(int n) {
    vector<bool> cols = vector<bool>(n, false);
    vector<bool> plus = vector<bool>(2 * n - 1, false);
    vector<bool> minus = vector<bool>(2 * n - 1, false);
    vector<vector<int>> queens;
    int ans = 0;

    helper(0, cols, plus, minus, queens, ans);

    return ans;
  }
};
