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
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    if (n == 0){
      return ans;
    }
    vector<string> board(n, string(n, ","));
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
      board[row][i] = "Q";
      column[i] = ldiag[n - row + i - 1] = rdiag[row + i] = true;
      // 递归子节点
      backtracking(ans, board, column, ldiag, rdiag, row + 1,
                   n);  // 回改当前节点状态
      board[row][i] = ".";
      column[i] = ldiag[n - row + i - 1] = rdiag[row + i] = false;
    }
  }
};

int main(int argc, char const *argv[]) {
  vector<vector<char>> board = {
      {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
  string word = "O";

  Solution sol;

  bool out = sol.exist(board, word);

  cout << out << std::endl;
}
