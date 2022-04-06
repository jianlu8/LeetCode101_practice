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
  // 主函数

  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ans;
    vector<int> comb(k, 0);
    int count = 0;
    backtracking(ans, comb, count, 1, n, k);
    return ans;
  }
  // 辅函数
  void backtracking(vector<vector<int>>& ans, vector<int>& comb, int count,
                    int pos, int n, int k) {
    if (count == k) {
      ans.push_back(comb);
      return;
    }
    for (int i = pos; i <= n; ++i) {
      comb[count++] = i;                            // 修改当前节点状态
      backtracking(ans, comb, count, i + 1, n, k);  // 递归子节点
      --count;                                      // 回改当前节点状态
    }
  }
};

int main(int argc, char const* argv[]) {
  int n = 4, k = 1;

  Solution sol;

  vector<vector<int>> out = sol.combine(n, k);

  cout << out.size() << std::endl;
}
