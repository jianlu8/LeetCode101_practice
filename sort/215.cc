#include <limits.h>

#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int findKthLargest(vector<int>& nums, int k) {
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i; j > 0 && nums[j] < nums[j - 1]; --j) {
                swap(nums[j], nums[j - 1]);
            }
        }
        return nums[nums.size()-k];
    }
};

int main(int argc, char const* argv[]) {
    vector<int> nums = {5, 7, 7, 8, 8, 10, 10};
    int k = 2;

    Solution sol;

    int out = sol.findKthLargest(nums, k);
    std::cout << out << std::endl;
}
