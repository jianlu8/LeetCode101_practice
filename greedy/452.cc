#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
    	if (points.empty())
    	{
    		return 0;
    	}
    	int n = points.size();
    	sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b){
    		return a[1] < b[1];
    	});
    	int count = 1, previous = points[0][1];
    	cout << previous << endl;
    	for (int i = 1; i < points.size(); ++i)
    	{	
    		cout << points[i][0] << ", " << points[i][1] << "points" << endl;
    		if (previous < points[i][0])
    		{
    			cout << "++++1" <<endl;
    			count += 1;
    			previous = points[i][1];
    			}
    	}
    	return count;
    }
};




int main(int argc, char const *argv[])
{
    int result = 0;

    vector<vector<int>> points = {{0,9},{1,8},{7,8},{1,6},{9,16},{7,13},{7,10},{6,11},{6,9},{9,13}};
    // vector<vector<int>> points = {{1,2},{3,4},{5,6},{7,8}};


    Solution sol;

    result = sol.findMinArrowShots(points);

    // cout << g[1] << endl;
    cout << result <<endl;


    return result;

}