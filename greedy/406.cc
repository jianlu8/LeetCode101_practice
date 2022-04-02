#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


class Solution {
public:
inline
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](vector<int>& a, vector<int>& b){
            return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
        });
        // cout << people[0][1] << endl;
        for (int i = 0; i < people.size(); ++i)
        {
            cout << people[i][0] <<"," << people[i][1] << endl;

        }        
        vector<vector<int>> queue;    
        for (int i = 0; i < people.size(); ++i)
        {
            queue.insert(queue.begin() + people[i][1], people[i]);
            cout << queue.begin()[0][0] << "!!!!" << people[i][1];
        }
        return queue;
    }
    
};



int main(int argc, char const *argv[])
{
    vector<vector<int>> result;

    vector<vector<int>> people = {{9,0},{7,0},{1,9},{3,0},{2,7},{5,3},{6,0},{3,4},{6,2},{5,2}};

    Solution sol;

    result = sol.reconstructQueue(people);

    cout << "---!!!!!!!!!!!!!!-----" << endl;
    for (int i = 0; i < result.size(); ++i)
    {
        cout << result[i][0] <<"," << result[i][1] << endl;

    }
    

}