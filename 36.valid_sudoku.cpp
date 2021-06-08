#include <vector>

using namespace std;

class Solution {
  int charToInt(char c) { return c - '0'; }

  bool isValidRow(vector<vector<char>> &board, int row) {
    int memo[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < 9; i++) {
      if (board[row][i] == '.') {
        continue;
      }
      int index = charToInt(board[row][i]) - 1;
      if (memo[index] != 0) {
        return false;
      }
      memo[index] += 1;
    }
    return true;
  }

  bool isValidCol(vector<vector<char>> &board, int col) {
    int memo[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < 9; i++) {
      if (board[i][col] == '.') {
        continue;
      }
      int index = charToInt(board[i][col]) - 1;
      if (memo[index] != 0) {
        return false;
      }
      memo[index] += 1;
    }
    return true;
  }

  bool isValidCorner(vector<vector<char>> &board, int row, int col) {
    int memo[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (board[row + i][col + j] == '.') {
          continue;
        }
        int index = charToInt(board[row + i][col + j]) - 1;
        if (memo[index] != 0) {
          return false;
        }
        memo[index] += 1;
      }
    }
    return true;
  }

public:
  bool isValidSudoku(vector<vector<char>> &board) {
    for (int i = 0; i < 9; i++) {
      if (isValidRow(board, i) == false) {
        return false;
      }
      if (isValidCol(board, i) == false) {
        return false;
      }
    }

    for (int i = 0; i < 9; i += 3) {
      for (int j = 0; j < 9; j += 3) {
        if (isValidCorner(board, i, j) == false) {
          return false;
        }
      }
    }
    return true;
  }
};
