#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
 public:
  vector<int> direction{-1, 0, 1, 0, -1};
  // 主函数
  int shortestBridge(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    queue<pair<int, int>> points;
    bool flipped = false;
    // dfs寻找第一个岛屿，并把1全部赋值为2 bool flipped = false;
    for (int i = 0; i < m; ++i) {
      if (flipped) break;
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 1) {
          dfs(points, grid, m, n, i, j);
          flipped = true;
          break;
        }
      }
    }
    // bfs寻找第二个岛屿，并把过程中经过的0赋值为2 int x, y;
    int x, y;
    int level = 0;
    while (!points.empty()) {
      ++level;
      int n_points = points.size();
      while (n_points--) {
        auto [r, c] = points.front();
        points.pop();
        for (int k = 0; k < 4; ++k) {
          x = r + direction[k], y = c + direction[k + 1];
          if (x >= 0 && y >= 0 && x < m && y < n) {
            if (grid[x][y] == 2) {
              continue;
            }
            if (grid[x][y] == 1) {
              return level;
            }
            points.push({x, y});
            grid[x][y] = 2;
          }
        }
      }
    }
    return 0;
  }
  // 辅函数
  void dfs(queue<pair<int, int>>& points, vector<vector<int>>& grid, int m,
           int n, int i, int j) {
    if (i < 0 || j < 0 || i == m || j == n || grid[i][j] == 2) {
      return;
    }
    if (grid[i][j] == 0) {
      points.push({i, j});
      return;
    }
    grid[i][j] = 2;
    dfs(points, grid, m, n, i - 1, j);
    dfs(points, grid, m, n, i + 1, j);
    dfs(points, grid, m, n, i, j - 1);
    dfs(points, grid, m, n, i, j + 1);
  }
};

int main(int argc, char const* argv[]) {
  vector<vector<int>> grid = {{1, 1, 1, 1, 1},
                              {1, 0, 0, 0, 1},
                              {1, 0, 1, 0, 1},
                              {1, 0, 0, 0, 1},
                              {1, 1, 1, 1, 1}};

  Solution sol;

  int out = sol.shortestBridge(grid);

  cout << out << std::endl;
}
