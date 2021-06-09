#include <vector>

using namespace std;

class Solution {
  int charToInt(char c) { return c - '0'; }

  vector<char> possibleMove(vector<vector<char>> &board, int row, int col) {
    int memo[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

    for (int i = 0; i < 9; i++) {
      if (board[row][i] != '.') {
        memo[charToInt(board[row][i]) - 1] = 1;
      }

      if (board[i][col] != '.') {
        memo[charToInt(board[i][col]) - 1] = 1;
      }
    }

    int row_start = row / 3, col_start = col / 3;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (board[row_start * 3 + i][col_start * 3 + j] != '.') {
          memo[charToInt(board[row_start * 3 + i][col_start * 3 + j]) - 1] = 1;
        }
      }
    }

    vector<char> ret;
    for (int i = 0; i < 9; i++) {
      if (memo[i] == 0) {
        ret.push_back(i + 1 + '0');
      }
    }
    return ret;
  }

  bool helper(vector<vector<char>> &board, int idx) {
    if (idx == 81) {
      return true;
    }

    int row = idx / 9, col = idx % 9;
    if (board[row][col] != '.') {
      return helper(board, idx + 1);
    }

    vector<char> p = possibleMove(board, row, col);

    for (char c : p) {
      board[row][col] = c;
      if (helper(board, idx + 1)) {
        return true;
      }
    }
    board[row][col] = '.';

    return false;
  }

public:
  void solveSudoku(vector<vector<char>> &board) { helper(board, 0); }
};
