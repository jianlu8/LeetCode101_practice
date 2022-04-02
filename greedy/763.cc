#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {

    	map<char, int> m;
        for (int i = 0; i < s.size(); i++){
            m[s[i]] = i;
        	// cout << m[s[i]] << endl;
        }
        int i = 0, j = 0, start = 0;
        vector<int> a;
        while (i < s.size()) {
            j = max(j, m[s[i]]);
            cout << m[s[i]] << endl;
            if (i == j) {
                a.push_back(i - start + 1);
                start = i + 1;
            }
            i++;

        }
        
            return a;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> result;

    string s = "ababcbacadefegdehijhklij";
    // vector<vector<int>> points = {{1,2},{3,4},{5,6},{7,8}};


    Solution sol;

    result = sol.partitionLabels(s);

    // cout << g[1] << endl;
    cout << result[2] <<endl;


}