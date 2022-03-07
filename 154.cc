#include<iostream>
#include<vector>
#include<cmath>
using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int result = 0;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i-1] > nums[i]) {
                return nums[i];
            }
        }
        return nums[0];
    }
    int findMin2(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        while (low < high) {
            int pivot = low + (high - low) / 2;
            if (nums[pivot] < nums[high]) {
                high = pivot;
            }
            else if (nums[pivot] > nums[high]) {
                low = pivot + 1;
            }
            else {
                high -= 1;
            }
        }
        return nums[low];
    }
};


int main(int argc, char const *argv[]){

    vector<int> nums = {5,7,7,8,8,10};

    Solution sol;

    int out = sol.findMin(nums);
    std::cout << out << std::endl;


}