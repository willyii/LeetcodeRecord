#include <vector>

using namespace std;

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    vector<int> ans;
    int c = 0, C = matrix[0].size() - 1;
    int r = 0, R = matrix.size() - 1;
    while (c <= C && r <= R) {
      for (int i = c; i <= C; i++)
        ans.push_back(matrix[r][i]);
      for (int i = r + 1; i <= R; i++)
        ans.push_back(matrix[i][C]);
      if (r < R)
        for (int i = C - 1; i >= c; i--)
          ans.push_back(matrix[R][i]);
      if (c < C)
        for (int i = R - 1; i > r; i--)
          ans.push_back(matrix[i][c]);

      c++;
      C--;
      r++;
      R--;
    }

    return ans;
  }
};
