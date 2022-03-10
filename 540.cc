#include<iostream>
#include<vector>
#include<cmath>
using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while(low < high) {
            int mid = (high - low) / 2 + low;
            if (nums[mid] == nums[mid-1]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return nums[low];
    }
};


int main(int argc, char const *argv[]){

    vector<int> nums = {5,7,7,8,8,10,10};

    Solution sol;

    int out = sol.singleNonDuplicate(nums);
    std::cout << out << std::endl;


}