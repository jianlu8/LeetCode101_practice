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
    int climbStairs(int n) {
      if (n<=2) return n;
      vector<int> dp(n + 1, 1);
      for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i-1] + dp[i-2];
      }
      return dp[n];
    }
};

int main(int argc, char const* argv[]) {
  int n = 3;

  Solution sol;

  int out = sol.climbStairs(n);

  cout << out << std::endl;
}
