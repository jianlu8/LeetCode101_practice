#include <limits.h>

#include <cmath>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>

using namespace std;

class Solution {
   public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        int max_count = 0;
        for (auto ch : s) {
            max_count = max(max_count, ++mp[ch]);
        }
        // std::cout << max_count << endl;
        vector<list<char>> buckets(max_count + 1);
        for (const auto& p : mp) {
            buckets[p.second].push_back(p.first);
        }
        string ans;
        for (int i = max_count; i >= 0 ; --i) {
            for (auto j : buckets[i]) {
                auto temp = i;
                while(temp != 0){
                    temp--;
                    ans += j;
                }
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[]) {
    string s = "tree";

    Solution sol;

    string out = sol.frequencySort(s);

    cout << out << std::endl;
}
