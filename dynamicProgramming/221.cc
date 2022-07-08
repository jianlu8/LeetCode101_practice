#include <limits.h>

#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
 public:
  int maximalSquare(vector<vector<char>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) {
      return 0;
    }
    int m = matrix.size(), n = matrix[0].size(), max_side = 0;
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (matrix[i - 1][j - 1] == '1') {
          dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
        }
        max_side = max(max_side, dp[i][j]);
      }
    }
    return max_side * max_side;
  }
};



int main(int argc, char const* argv[]) {
  vector<vector<char>> n ={{'1','0','1','1'},
                           {'1','1','1','1'},
                           {'1','1','1','1'},
                           {'1','1','1','1'}};
  Solution sol;

  int out = sol.maximalSquare(n);

  cout << out << endl;
}
