#include <iostream>
using namespace std;

class solution{
public:
    bool isPrime(int x)
    {
        if(x <= 1 )
        {
            return false;
        }
        else if ( x == 2 || x == 3)
        {
            return true;
        }

        for(int i = 5; (i * i) <= x; i += 6)
        {
            if( x % i == 0 || x % (i + 2) == 0)
            {
                return false;
            }
        }
        return true;

    }
};

int main()
{
    solution sol;
    cout<< sol.isPrime(17);
}