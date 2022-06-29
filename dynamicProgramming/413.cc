#include <limits.h>
#include <numeric>
#include <cmath>
#include <iostream>
#include <list>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int numberOfArithmeticSlices(vector<int>& nums) {
    int n = nums.size();
    if (n < 3) return 0;
    vector<int> dp(n, 0);
    for (int i = 2; i < n; ++i) {
      if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
        dp[i] = dp[i - 1] + 1;
      }
    }
    return accumulate(dp.begin(), dp.end(), 0);
  }
};

int main(int argc, char const* argv[]) {
  vector<int> n = {1,2,3,4,3,4,5};
//                 0,0,1,2,0,0,1
  Solution sol;

  int out = sol.numberOfArithmeticSlices(n);

  cout << out << std::endl;
}
