#include <limits.h>

#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() > nums2.size()) {
      return findMedianSortedArrays(nums2, nums1);
    }

    int m = nums1.size();
    int n = nums2.size();
    int left = 0, right = m;
    // median1：前一部分的最大值
    // median2：后一部分的最小值
    int median1 = 0, median2 = 0;

    while (left <= right) {
      // 前一部分包含 nums1[0 .. i-1] 和 nums2[0 .. j-1]
      // 后一部分包含 nums1[i .. m-1] 和 nums2[j .. n-1]
      int i = (left + right) / 2;
      int j = (m + n + 1) / 2 - i;

      // nums_im1, nums_i, nums_jm1, nums_j 分别表示 nums1[i-1], nums1[i],
      // nums2[j-1], nums2[j]
      int nums_im1 = (i == 0 ? INT_MIN : nums1[i - 1]);
      int nums_i = (i == m ? INT_MAX : nums1[i]);
      int nums_jm1 = (j == 0 ? INT_MIN : nums2[j - 1]);
      int nums_j = (j == n ? INT_MAX : nums2[j]);

      if (nums_im1 <= nums_j) {
        median1 = max(nums_im1, nums_jm1);
        median2 = min(nums_i, nums_j);
        left = i + 1;
      } else {
        right = i - 1;
      }
    }

    return (m + n) % 2 == 0 ? (median1 + median2) / 2.0 : median1;
  }
};

int main(int argc, char const* argv[]) {
  vector<int> nums1 = {5, 7, 7, 8, 8, 10, 10};
  vector<int> nums2 = {5, 7, 7, 8, 8, 10, 10};

  Solution sol;

  int out = sol.findMedianSortedArrays(nums1, nums2);
  std::cout << out << std::endl;
}
