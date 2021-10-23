#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public: 
    int candy(vector<int>& ratings) {
        vector<int> candys(ratings.size(),1);
        for (int i = 0; i < ratings.size()-1; ++i)
        {
            cout << i << "----" << endl;
            if (ratings[i]<ratings[i+1])
            {
                candys[i+1]=candys[i]+1;
            }
        }
        for (int i = ratings.size()-1; i > 0; i--)
        {
            // cout << i << "----" << endl;
            if (ratings[i]<ratings[i-1])
            {
                candys[i-1]=candys[i]+1;
            }
        }

        int candys_total = accumulate(candys.begin(), candys.end(),0);
        return candys_total;
    }
};


int main(int argc, char const *argv[])
{
    vector<int> ratings_test = {1,0,2};
    Solution sol;
    int result = sol.candy(ratings_test);
    cout << "result is " << result << endl;
    
}