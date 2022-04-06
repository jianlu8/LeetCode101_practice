#include <limits.h>

#include <cmath>
#include <iostream>
#include <list>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;
// 怎样输出所有的排列方式呢？对于每一个当前位置i，我们可以将其于之后的任意位置交换，
// 然后继续处理位置i+1，直到处理到最后一位。为了防止我们每此遍历时都要新建一个子数组储
// 存位置i
// 之前已经交换好的数字，我们可以利用回溯法，只对原数组进行修改，在递归完成后再
// 修改回来。
// 我们以样例[1,2,3] 为例，按照这种方法，我们输出的数组顺序为[[1,2,3], [1,3,2],
// [2,1,3], [2,3,1], [3,2,1],
// [3,1,2]]，可以看到所有的排列在这个算法中都被考虑到了。
class Solution {
 public:
  // 主函数
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    backtracking(nums, 0, ans);
    return ans;
  }
  // 辅函数
  void backtracking(vector<int>& nums, int level, vector<vector<int>>& ans) {
    if (level == nums.size() - 1) {
      // printvec(nums);
      ans.push_back(nums);
      return;
    }
    cout << "level= " << level << endl;
    for (int i = level; i < nums.size(); i++) {
      swap(nums[i], nums[level]);          // 修改当前节点状态
      printvec(nums);
      backtracking(nums, level + 1, ans); 
       // 递归子节点
      swap(nums[i], nums[level]);          // 回改当前节点状态
    }
  }
  void printvec(vector<int> nums){
    for (int i = 0; i < nums.size(); ++i){
      cout << nums[i];
      /* code */
    }
    cout << "---------" << endl;
  }
};

int main(int argc, char const* argv[]) {
  vector<int> grid = {1,2,3};

  Solution sol;

  vector<vector<int>> out = sol.permute(grid);

  cout << out.size() << std::endl;
}
