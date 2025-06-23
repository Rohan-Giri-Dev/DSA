// Printing number using recurssion but in opposite way
#include <iostream>
using namespace std;

void numPrint(int i, int n)
{
    if(i < 1 ) return;
    cout<<i<<" ";
    numPrint(i-1, n);
}

int main()
{
    int n;
    cout<<"Enter num: ";
    cin>>n;

    numPrint(n,n);
}