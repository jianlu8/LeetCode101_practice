#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using std::vector;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int pos = m-- + n-- -1;
        while (m >= 0 && n >= 0) {
            nums1[pos--] = nums1[m] > nums2[n] ? nums1[m--] : nums2[n--];
        }
        while (n >= 0){
            nums1[pos--] = nums2[n--];
        }

    }
};


int main(int argc, char const *argv[])
{
    // vector<int> result;

    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    int n = 3;
    int m = 3;


    Solution sol;

    sol.merge(nums1, m, nums2, n);
    for (int i = 0; i < nums1.size(); ++i)
    {
        std::cout << nums1[i] << std::endl;
    }
    

}