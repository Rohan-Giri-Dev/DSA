#include <iostream>
using namespace std;

int main()
{
    int arr[5] = {1,2,2,1,3};

    int hash[13] = {0};
    for(int i=0; i<5; i++)
    {
        hash[arr[i]] += 1;
    }

    // quereis the user wants to make
    int q;
    cout<<"Number of queries : ";
    cin>> q;

    while (q--)
    {
        int number;
        cout<<"Enter your query: ";
        cin>>number;
        cout<<number <<" has appeared "<<hash[number]<<" times"<<endl;
    }
    

}