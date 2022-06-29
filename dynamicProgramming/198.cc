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
  // int rob(vector<int>& nums) {
  //   if (nums.empty()) return 0;
  //   int n = nums.size();
  //   vector<int> dp(n + 1, 0);
  //   dp[1] = nums[0];
  //   for (int i = 2; i <= n; ++i) {
  //     dp[i] = max(dp[i - 1], nums[i - 1] + dp[i - 2]);
  //   }
  //   return dp[n];
  // }
  int rob(vector<int>& nums) {
    if (nums.empty()) return 0;
    int n = nums.size();
    if (n == 1) return nums[0];
    int pre2 = 0, pre1 = 0, cur;
    for (int i = 0; i < n; ++i) {
      cur = max(pre2 + nums[i], pre1);
      pre2 = pre1;
      pre1 = cur;
    }
    return cur;
  }
};

int main(int argc, char const* argv[]) {
  vector<int> n = {1, 3, 2, 10, 2, 1};

  Solution sol;

  int out = sol.rob(n);

  cout << out << std::endl;
}
