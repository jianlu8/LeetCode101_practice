#include <limits.h>

#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

    }
};

int main(int argc, char const* argv[]) {
  vector<int> nums = {5, 7, 7, 8, 8, 10, 10};
  int k = 3;

  Solution sol;

  int out = sol.findKthLargest(nums, k);
  std::cout << out << std::endl;
}
