// Reversing array with recurrsion function

#include <iostream>
using namespace std;

void revArr(int i, int arr[], int n)
{
    if( i >= n/2) return;
    swap(arr[i], arr[n-i-1]);
    revArr(i+1, arr, n);
}

int main()
{
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int arr[n];
    for(int i=0; i < n; i++)
    {
        cout<<"Enter value at " <<i+1<<" ";
        cin>>arr[i];
    }

    revArr(0, arr, n);

    for(int i=0; i<n; i++)
    {
        cout<<arr[i];
        cout<<endl;
    }
}