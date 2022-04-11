#include <limits.h>

#include <cmath>
#include <iostream>
#include <list>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;
//类似于在矩阵中寻找字符串，本题也是通过修改状态矩阵来进行回溯。不同的是，我们需要
//对每一行、列、左斜、
//右斜建立访问数组，来记录它们是否存在皇后。本题有一个隐藏的条件，即满足条件的结果中每一行或列有且仅有一
//个皇后。这是因为我们 一共只有 n 行和 n
//列。所以如果我们通过对每一行遍历来插入皇后，我们就不需要对行建立访问 数组了。

class Solution {
 public:
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    if (n == 0) {
      return ans;
    }
    vector<string> board(n, string(n, '.'));
    vector<bool> column(n, false), ldiag(2 * n - 1, false),
        rdiag(2 * n - 1, false);
    backtracking(ans, board, column, ldiag, rdiag, 0, n);
    return ans;
  }
  void backtracking(vector<vector<string>> &ans, vector<string> &board,
                    vector<bool> &column, vector<bool> &ldiag,
                    vector<bool> &rdiag, int row, int n) {
    if (row == n) {
      ans.push_back(board);
      return;
    }
    for (int i = 0; i < n; ++i) {
      if (column[i] || ldiag[n - row + i - 1] || rdiag[row + i]) {
        continue;
      }
      board[row][i] = 'Q';
      column[i] = ldiag[n - row + i - 1] = rdiag[row + i] = true;
      // 递归子节点
      backtracking(ans, board, column, ldiag, rdiag, row + 1,
                   n);  // 回改当前节点状态
      board[row][i] = '.';
      column[i] = ldiag[n - row + i - 1] = rdiag[row + i] = false;
    }
  }
};

int main(int argc, char const *argv[]) {
  int n = 4;

  Solution sol;

  vector<vector<string>> out = sol.solveNQueens(n);

  cout << out.size() << std::endl;
}
