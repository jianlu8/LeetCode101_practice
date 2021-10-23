#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	int maxProfit = 0;
    	for (int i = 0; i < prices.size()-1; ++i)
    	{
    		vector<int> profit(prices.size()-1);
    		profit[i] = prices[i+1] - prices[i];
    		cout << profit[i] << endl;
    		if (profit[i]>0)
    		{
    			maxProfit += profit[i];
    		}
    	}
    	return maxProfit;
    }
};



int main(int argc, char const *argv[])
{
    int result;

    vector<int> prices = {7,1,5,3,6,4};

    Solution sol;

    result = sol.maxProfit(prices);

    // cout << g[1] << endl;
    cout << result <<endl;


}