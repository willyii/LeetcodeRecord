#include <vector>

using namespace std;
class Solution {
public:
  void rotate(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int mid = n / 2;
    if (n % 2) {
      mid++;
    }
    for (int i = 0; i < mid; i++) {
      for (int j = i; j < n - 1 - i; j++) {
        int tmp = matrix[i][j];
        matrix[i][j] = matrix[n - 1 - j][i];
        matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
        matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
        matrix[j][n - 1 - i] = tmp;
      }
    }
    return;
  }
};

// [1,2,3,4]
// [5,6,7,8]
// [9,10,11,12]
// [13,14,15,16]
//
// i,j = 0,1
// 0,1 -> 3,1 -> 3,3 -> 3,0
