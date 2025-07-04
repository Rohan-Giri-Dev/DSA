// FInd the largest element in the array
#include <iostream>
using namespace std;

int largestElement(int arr[],int n){

    int largest = arr[0];
    for(int i =1; i<n; i++)
    {
        if(arr[i] > largest)
        {
            largest = arr[i];
        }
    }

    return largest;

}

int main()
{
    int arr[] = {1,6,2,4,3,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<largestElement(arr,n);

}