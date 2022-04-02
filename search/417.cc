#include <limits.h>

#include <cmath>
#include <iostream>
#include <list>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> direction{-1, 0, 1, 0, -1};
  // 主函数
  vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) {
      return {};
    }
    vector<vector<int>> ans;
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<bool>> can_reach_p(m, vector<bool>(n, false));
    vector<vector<bool>> can_reach_a(m, vector<bool>(n, false));
    for (int i = 0; i < m; ++i) {
      dfs(matrix, can_reach_p, i, 0);
      dfs(matrix, can_reach_a, i, n - 1);
    }
    for (int i = 0; i < n; ++i) {
      dfs(matrix, can_reach_p, 0, i);
      dfs(matrix, can_reach_a, m - 1, i);
    }
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; ++j) {
        if (can_reach_p[i][j] && can_reach_a[i][j]) {
          ans.push_back(vector<int>{i, j});
        }
      }
    }
    return ans;
  }
  // 辅函数
  void dfs(const vector<vector<int>>& matrix, vector<vector<bool>>& can_reach,
           int r, int c) {
    if (can_reach[r][c]) {
      return;
    }
    can_reach[r][c] = true;
    int x, y;
    for (int i = 0; i < 4; ++i) {
      x = r + direction[i], y = c + direction[i + 1];
      if (x >= 0 && x < matrix.size() && y >= 0 && y < matrix[0].size() &&
          matrix[r][c] <= matrix[x][y]) {
        dfs(matrix, can_reach, x, y);
      }
    }
  }
};

int main(int argc, char const* argv[]) {
  vector<vector<int>> grid = {{1, 2, 2, 3, 5},
                              {3, 2, 3, 4, 4},
                              {2, 4, 3, 5, 1},
                              {6, 7, 1, 4, 5},
                              {5, 1, 1, 2, 4}};

  Solution sol;

  vector<vector<int>> out = sol.pacificAtlantic(grid);

  cout << out.size() << std::endl;
}
