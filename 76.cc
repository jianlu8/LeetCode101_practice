#include<iostream>
#include<vector>
#include<algorithm>
#include"ListNode.h"
using std::vector;
using std::cout;
using std::endl;

class Solution {
public:
    string minWindow(string S, string T) {
        vector<int> chars(130,0);
        vector<bool> flag(130,false);
        for (int i = 0; i < T.size(); ++i)
        {
            flag[T[i]] = true;
            // cout<< T[i]<< "@@"<< chars[T[i]]<< "!!!!"<<endl;
            // cout<<chars[1]<<endl;
            ++chars[T[i]];
            // cout<< T[i]<< "@@"<< chars[T[i]]<< "!!!!"<<endl;
        }
        for (int i = 0; i < chars.size(); ++i)
        {
            cout<<chars[i];
        }

        int cnt = 0, l = 0, min_l = 0, min_size = S.size() + 1;
        for (int r = 0; r < S.size(); ++r)
        {
            if (flag[S[r]])
            {
                if (--chars[S[r]]>=0)
                {
                    ++cnt;
                }
                while(cnt == T.size()){
                    if (r-l+1<min_size)
                    {
                        min_l=l;
                        min_size=r-l+1;
                    }
                    if (flag[S[l]] && ++chars[S[l]]>0)
                    {
                        --cnt;
                    }
                    ++l;
                }
            }
        }
    return min_size > S.size() ? "":S.substr(min_l,min_size);
    }
    
};


int main(int argc, char const *argv[]){

    string S = "ADOBECODEBANC";
    string T = "AABC";

    Solution sol;

    string out = sol.minWindow(S, T);
    std::cout << out << std::endl;
    

}

