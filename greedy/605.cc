


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {

        if(flowerbed[0] == 0) flowerbed.insert(flowerbed.begin(), 0);
        if(flowerbed.back() == 0) flowerbed.push_back(0);
        int count = 0;

        for (int i = 1; i < flowerbed.size()-1; ++i)
        {
            if (flowerbed[i] ==0 && flowerbed[i-1] == 0 && flowerbed[i+1] == 0)
            {
                count += 1;
                flowerbed[i] = 1;
            }
        }
        return count >= n;
    }
};



int main(int argc, char const *argv[])
{
    bool result;

    vector<int> flowerbed = {1,0,1,0,1,0,1};


    Solution sol;

    result = sol.canPlaceFlowers(flowerbed,1);

    // cout << g[1] << endl;
    cout << result <<endl;


    return result;

}