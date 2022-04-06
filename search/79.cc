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

  bool exist(vector<vector<char>>& board, string word) {
    if (board.empty()) return false;
    int m = board.size(), n = board[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    bool find = false;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        backtracking(i, j, board, word, find, visited, 0);
      }
    }
    return find;
  }
  // 辅函数
  void backtracking(int i, int j, vector<vector<char>>& board, string& word,
                    bool& find, vector<vector<bool>>& visited, int pos) {
    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) {
      return;
    }
    if (visited[i][j] || find || board[i][j] != word[pos]) {
      return;
    }
    if (pos == word.size() - 1) {
      find = true;
      return;
    }
    visited[i][j] = true;  // 修改当前节点状态
    // 递归子节点
    backtracking(i + 1, j, board, word, find, visited, pos + 1);
    backtracking(i - 1, j, board, word, find, visited, pos + 1);
    backtracking(i, j + 1, board, word, find, visited, pos + 1);
    backtracking(i, j - 1, board, word, find, visited, pos + 1);
    visited[i][j] = false;  // 回改当前节点状态
  }
};

int main(int argc, char const* argv[]) {
  vector<vector<char>> board = {
                                {'A', 'B', 'C', 'E' }, 
                                {'S', 'F', 'C', 'S'}, 
                                {'A', 'D', 'E', 'E'}};
  string word = "O";

  Solution sol;

  bool out = sol.exist(board, word);

  cout << out << std::endl;
}
