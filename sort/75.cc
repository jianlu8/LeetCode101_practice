#include <limits.h>

#include <cmath>
#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    void sortColors(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i; j > 0 && nums[j] < nums[j - 1]; --j) {
                swap(nums[j], nums[j - 1]);
            }
        }
    }
};

int main(int argc, char const* argv[]) {
    vector<int> nums = {2,0,2,1,1,0};

    Solution sol;

    sol.sortColors(nums);
    for (int i = 0; i < nums.size(); ++i)
    {
        std::cout << nums[i] << std::endl;
    }
}
