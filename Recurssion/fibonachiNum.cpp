//using recurssion to print fibinachi number
#include <iostream>
using namespace std;

class solution{
public:
    int fib(int n){
        if(n <= 1) return n;

        return fib(n -1) + fib(n - 2);
    }
};

int main()
{
    solution sol;
    cout<< sol.fib(6);
}