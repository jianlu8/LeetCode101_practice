#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


class Solution {
public:
    static bool cmp(const vector<int>& a,const vector<int>& b){
        return a.back()<b.back();
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),cmp);
        int i = 1;
        int count = 0, previous = intervals[0][1];
        cout << "previous = " << previous << endl;
        while(i < intervals.size()){
            
            if (previous > intervals[i][0])
            {
                cout << i << "+++" <<endl;
                cout << "test" << intervals[i][0] << endl;
                i++;
                count += 1;
                cout << count << " in if ----" <<endl;
                
            }
            else{
                previous = intervals[i][1];
                cout << "previous in else = " << previous << endl;
                i++;
            }
        }
        return count;
    }

    int eraseOverlapIntervalsAnswer(vector<vector<int>>& intervals) {
if (intervals.empty()) {
return 0;
}
int n = intervals.size();
sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b)
{
return a[1] < b[1];
});
int removed = 0, prev = intervals[0][1];
for (int i = 1; i < n; ++i) {
if (intervals[i][0] < prev) {
++removed;
} else {
prev = intervals[i][1];
}
}
return removed;
}
};


int main(int argc, char const *argv[])
{
    int result = 0;

    vector<vector<int>> intervals = {{1,2},{2,4},{1,3}};


    Solution sol;

    result = sol.eraseOverlapIntervalsAnswer(intervals);

    // cout << g[1] << endl;
    cout << result <<endl;


    return result;

}