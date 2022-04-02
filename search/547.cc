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
  int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size(), count = 0;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; ++i) {
      if (!visited[i]) {
        dfs(isConnected, i, visited);
        ++count;
      }
    }
    return count;
  }
  void dfs(vector<vector<int>>& isConnected, int i, vector<bool>& visited) {
    visited[i] = true;
    for (int k = 0; k < isConnected.size(); ++k) {
      if (isConnected[i][k] == 1 && !visited[k]) {
        dfs(isConnected, k, visited);
      }
    }
  }
};

int main(int argc, char const* argv[]) {
  vector<vector<int>> isConnected = {{1, 1, 0},
                                     {1, 1, 0},
                                     {0, 0, 1}};

  Solution sol;

  int out = sol.findCircleNum(isConnected);

  cout << out << std::endl;
}
