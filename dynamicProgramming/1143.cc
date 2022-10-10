#include <limits.h>

#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
 public:
  int longestCommonSubsequence(string text1, string text2) {
    int m = text1.length(), n = text2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (text1[i - 1] == text2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
        } else {
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }
    return dp[m][n];
  }
};

int main(int argc, char const* argv[]) {
  string text1 = "acbc";
  string text2 = "abcd";
  Solution sol;

  int out = sol.longestCommonSubsequence(text1, text2);

  cout << out << endl;
}
// 1 0 0 0 0 0 0 0