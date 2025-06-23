#include <iostream>
using namespace std;

class solution
{
public:
    int reverse(int x)
    {
        long long newNum = 0;
        while( x != 0)
        {
            int r = x%10;
            newNum = newNum * 10 + r;
            x = x/10; 

        }

        return newNum;
    }
};

int main()
{
    solution sol;
    cout<< sol.reverse(123);
}
