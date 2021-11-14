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

  void addAns(vector<vector<int>> &queens, vector<vector<string>> &ans) {
    int n = queens.size();
    vector<string> board_str;
    for (int i = 0; i < n; i++) {
      string row_str(n, '.');
      row_str[queens[i][1]] = 'Q';
      board_str.push_back(row_str);
    }
    ans.push_back(board_str);
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
              vector<bool> &minus, vector<vector<int>> &queens,
              vector<vector<string>> &ans) {
    for (int col = 0; col < cols.size(); col++) {
      if (isValid(row, col, cols, plus, minus)) {
        placeQueen(row, col, queens, cols, plus, minus);
        if (row + 1 == cols.size()) {
          addAns(queens, ans);
        } else {
          helper(row + 1, cols, plus, minus, queens, ans);
        }
        removeQueen(row, col, queens, cols, plus, minus);
      }
    }
    return;
  }

public:
  vector<vector<string>> solveNQueens(int n) {
    vector<bool> cols = vector<bool>(n, false);
    vector<bool> plus = vector<bool>(2 * n - 1, false);
    vector<bool> minus = vector<bool>(2 * n - 1, false);
    vector<vector<int>> queens;
    vector<vector<string>> ans;

    helper(0, cols, plus, minus, queens, ans);

    return ans;
  }
};
