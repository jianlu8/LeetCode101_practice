#include<iostream>
#include<vector>
#include<cmath>
#include <algorithm>
using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        sort(dictionary.begin(), dictionary.end(),[](string&a ,string& b){
            if (a.size() != b.size()) return a.size() > b.size();
            else return a < b;
        });

        for (auto d : dictionary)
        {
            int i = 0, j = 0;
            while(i<d.size() && j<s.size()){
                if (d[i] == s[j]) i++;
                j++;
            }
            if (i == d.size()) return d;
        }
        return "";

    }
};


int main(int argc, char const *argv[]){

    string s = "abpcplea";
    vector<string> dictionary = {"ale","apple","monkey","plea"} ;

    Solution sol;

    string out = sol.findLongestWord(s, dictionary);
    std::cout << out << std::endl;
    

}