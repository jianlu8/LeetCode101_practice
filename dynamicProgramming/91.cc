#include <limits.h>

#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            cout << "i = " << i << endl;
            if (s[i - 1] != '0') {
                dp[i] += dp[i - 1];
                cout << dp[i] << " ";
            }
            if (i > 1 && s[i - 2] != '0' && ((s[i - 2] - '0') * 10 + (s[i - 1] - '0') <= 26)) {
                dp[i] += dp[i - 2];
                cout << dp[i] << endl;
            }
        }
        return dp[n];
    }
};


int main(int argc, char const* argv[]) {
  string n = "2223";
  Solution sol;

  int out = sol.numDecodings(n);

  cout << out << endl;
}
// 2 2 2 3 
// 1 1 2
//     3 3
//       4 3