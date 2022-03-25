#include <limits.h>

#include <cmath>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        int max_count = 0;
        for (const int& num : nums) {
            max_count = max(max_count, ++counts[num]);
            
        }
        std::cout << max_count << endl;
        vector<vector<int>> buckets(max_count + 1);
        for (const auto& p : counts) {
            buckets[p.second].push_back(p.first);
        }
        vector<int> ans;
        for (int i = max_count; i >= 0 && ans.size() < k; --i) {
            for (const int& num : buckets[i]) {
                ans.push_back(num);
                if (ans.size() == k) {
                    break;
                }
            }
        }
        return ans;
    }
};

int main(int argc, char const* argv[]) {
    vector<int> nums = {5,7,5, 10, 10};
    int k = 1;

    Solution sol;

    vector<int> out = sol.topKFrequent(nums, k);
    for (int i = 0; i < out.size(); ++i)
    {
        std::cout << out[i] << std::endl;
    }
    
}
