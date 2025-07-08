//Rotate array by D places
#include <iostream>
#include <vector>
using namespace std;

void arrRotate(vector<int> &arr,int d)
{
    int n = arr.size();
    d= d%n;
    vector<int> temp;
    for(int i =0 ; i<d; i++)
    {
        temp.push_back(arr[i]);
    }

    for(int i=d; i<n; i++)
    {
        arr[i-d] = arr[i];
    }

    for(int i=n-d; i<n; i++)
    {
        arr[i] = temp[i-(n-d)];
    }

    
}

void printArr(vector<int> &arr)
{
    for(auto i = arr.begin() ; i != arr.end(); i++)
    {
        cout<<*i<<" ";
    }
}

int main()
{
    vector<int> arr = {1,2,3,4,5};
    printArr(arr);
    cout<<endl;
    arrRotate(arr,3);
    printArr(arr);
}