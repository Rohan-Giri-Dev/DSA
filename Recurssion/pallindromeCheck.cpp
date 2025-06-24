// Check if a String is pallindrome or not
#include <iostream>
#include <string>
using namespace std;

int check(int i, string x, int n)
{
    if(i >= n/2 ) return true;

    if(x[i] != x[n-i-1] ) return false;

    return check(i+1, x, n);
}

int main()
{
    cout<< check(0, "Mekur", 5);
    cout<< check(0, "11211", 5);
   
}