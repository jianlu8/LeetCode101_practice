#include<iostream>
#include<vector>
#include<cmath>
using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
    int mySqrt(int a)
    {
      if (a == 0) return a;
      int l = 1, r = a, mid, sqrt;
      while (l <= r) {
        mid = l + (r - l) / 2;
        sqrt = a / mid;
        if (sqrt == mid) {
          return mid;
        }
        else if (mid > sqrt)
        {
          r = mid - 1;
        }
        else
        {
          l = mid + 1;
        }
      }
      return r;
    }
};


int main(int argc, char const *argv[]){

    int a = 18;

    Solution sol;

    int out = sol.mySqrt(a);
    std::cout << out << std::endl;
    

}