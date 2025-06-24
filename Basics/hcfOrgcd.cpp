#include <iostream>
using namespace std;

class Solution {
  public:
    int gcd(int a, int b) {
        // code here
        // if( x>=1 && b>=1 && x<=)
         while( b != 0)
        {
            int temp = b;
            b = a%b;
            a = temp;
        }
        return a;
    }
};


int main()
{
    Solution sol;
    sol.gcd(3,6);
}