#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	inline
    vector<int> twoSum(vector<int>& numbers, int target) {
    	int begin = 0, end = numbers.size()-1, sum;
    	while(begin<end){
    		sum = numbers[begin] + numbers[end];
    		cout << numbers[begin] << "-------" << numbers[end] << sum << endl;
    		if (sum == target)
    		{
    			break;
    		}if (sum < target)
    		{
    			begin++;
    		}else{
    			end--;
    		}
    	}
    	return vector<int> {begin+1, end+1};
    }
};

int main(int argc, char const *argv[])
{
	vector<int> result;

    vector<int> numbers = {2,7,11,15};
    int target = 9;

    Solution sol;

    result = sol.twoSum(numbers, target);
    cout << result[0] << "  " << result[1];

}