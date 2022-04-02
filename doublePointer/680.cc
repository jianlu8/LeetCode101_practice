#include<iostream>
#include<vector>
#include<cmath>
using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
    bool checkPalindrome(const string& s, int head, int tail) {
        for (int i = head, j = tail; i < j; ++i, --j){
            if (s[i] != s[j]){
                return false;
            }
        }
        return true;

    }
    bool validPalindrome(string s) {
        int head = 0, tail = s.size()-1;
        while(head<tail){
            char c1 = s[head], c2 = s[tail];
            if (c1==c2){
                ++head;
                --tail;
            }else{
                return checkPalindrome(s,head,tail-1) || checkPalindrome(s,head+1,tail);
            }

        }
        return true;
    }
};


int main(int argc, char const *argv[]){

    string s = "aba";

    Solution sol;

    bool out = sol.validPalindrome(s);
    std::cout << out << std::endl;
    

}