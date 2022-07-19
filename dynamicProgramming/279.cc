#include <limits.h>

#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
 public:
  int numSquares(int n) {
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {

      cout << "---------the " << i << " round-------" << endl;
      for (int j = 1; j * j <= i; ++j) {
        dp[i] = min(dp[i], dp[i - j * j] + 1);
        cout << j << " time dp " << dp[j] <<  " value is " << dp[i] << endl;
      }
    }
    return dp[n];
  }
};

int main(int argc, char const* argv[]) {
  int n = 9;
  Solution sol;

  int out = sol.numSquares(n);

  cout << out << endl;
}
