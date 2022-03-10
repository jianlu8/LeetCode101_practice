#include<iostream>
#include<vector>
#include<cmath>
using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

    }
};


int main(int argc, char const *argv[]){

    vector<int> nums1 = {5,7,7,8,8,10,10};
    vector<int> nums2 = {5,7,7,8,8,10,10};

    Solution sol;

    int out = sol.findMedianSortedArrays(nums1, nums2);
    std::cout << out << std::endl;


}