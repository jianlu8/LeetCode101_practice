#include <limits.h>

#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    int max_length = 0, n = nums.size();
    if (n <= 1) return n;
    vector<int> dp(n, 1);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (nums[i] > nums[j]) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }
      max_length = max(max_length, dp[i]);
    }
    return max_length;
  }
};

int main(int argc, char const* argv[]) {
  vector<int> nums = {2,3,8,4,5};
  Solution sol;

  int out = sol.lengthOfLIS(nums);

  cout << out << endl;
}
// 1 0 0 0 0 0 0 0