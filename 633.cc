#include<iostream>
#include<vector>
#include<cmath>
using std::vector;
using std::cout;
using std::endl;

class Solution {
public:
    bool judgeSquareSum(int c) {
        long left = 0, right = sqrt(c);
        cout<<right<<endl;
        while(left<=right){
            long sum = left*left+right*right;
            if (sum == c)
            {
                return true;
            }else if (sum>c)
            {
                right--;
            }else{
                left++;
            }

        }
        return false;
    }

};


int main(int argc, char const *argv[]){

    int c = 2;

    Solution sol;

    bool out = sol.judgeSquareSum(c);
    std::cout << out << std::endl;
    

}