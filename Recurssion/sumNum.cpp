// Print sum of num n times using recurssion
#include <iostream>
using namespace std;
// int sum = 0;
// void sumOfnum(int i, int n)
// {
//     if(i < 1) return;
//     sum += i;
//     sumOfnum(--i, n);
    
// }

// Solving this using functional recurssion

int dosum(int n)
{
    if( n < 1) return 0;
    return n + dosum(n-1);
}

int main()
{
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    cout<<dosum(n);
//     sumOfnum(n,n);
//     cout<<sum<<" ";
}