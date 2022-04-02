
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int g_ = 0, s_ = 0;
        while(g_< g.size() && s_< s.size()){
            if(g[g_] <= s[s_])
                ++g_;
            ++s_;
        }
        return g_;
    }


    int findContentChildren_2(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end(),greater<int>());
        sort(s.begin(),s.end(),greater<int>());
        

        int g_ = 0, s_ = 0, j = 0;
        int count = 0;
        

        for (int i = 0; i < g.size(); i++){
             cout << i << "test i ---" << endl;
             int z = j;
            while (z < s.size()){
                cout << j << "test j start" << endl;
                if (g[i] <= s[z])
                {
                    cout << s[j] << "test sj" << endl;
                    count++;
                    j++;
                    break;
                }
                cout << j << "test j" << endl;
                z++;
                
            }
        }
        return count;
    }
};

int main(int argc, char const *argv[])
{
    int result = 0, result_2 = 0;
    vector<int> g = {1,2,4,4,8,4,6,7,3};
    vector<int> s = {1,1,8,7,2,45,3};
    Solution sol;
    result = sol.findContentChildren(g,s);
    result_2 = sol.findContentChildren_2(g,s);
    // cout << g[1] << endl;
    cout << result <<endl;
    cout << result_2 << endl;

    return result;

}