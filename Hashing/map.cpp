//Using map to find the number of digits
#include <iostream>
#include <map>
using namespace std;

int main()
{
    int arr[] = {1,2,4,1,2,3,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    map<int , int> mpp;
    for(int i=0; i<size; i++)
    {
        mpp[arr[i]]++;
    }

    //iterate in the map
    for(auto it : mpp)
    {
        cout<<it.first << "->"<<it.second<<endl;
    }

    //query

    int q;
    cout<<"How many query: ";
    cin>>q;

    while(q--)
    {
        int num;
        cout<<"Enter your query: ";
        cin>>num;
        cout<<endl;
        cout<<"The "<<num<<" has "<<mpp[num]<<" in the array";
        cout<<endl;
    }
}