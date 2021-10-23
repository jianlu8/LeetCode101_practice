#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;


class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int count = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) {
                if (i == 1 || nums[i] >= nums[i - 2]) {
                    nums[i - 1] = nums[i];
                } else {
                    nums[i] = nums[i - 1];
                }
                count ++;
            }
        }
        return count <= 1;
    }
};



int main(int argc, char const *argv[])
{
    bool result;

    vector<int> nums = {3,4,2,3};

    Solution sol;

    result = sol.checkPossibility(nums);

    // cout << g[1] << endl;
    cout << result <<endl;


}