//Recurssive Bubble Sort
#include <iostream>
using namespace std;

void sortBuuble(int arr[], int n)
{
    if(n == 1) return;

    for(int i= 0; i < n-1; i++)
    {
        if(arr[i] > arr[i+1])
        {
            int temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
        }
        
    }

    sortBuuble(arr, n-1);
} 

void printArray(int arr[], int n){
    for(int i=0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main()
{
    int arr[] = {2,5,1,3,4};
    int n = sizeof(arr)/sizeof(arr[0]);

    printArray(arr,n);
    cout<<endl;
    sortBuuble(arr,n);
    printArray(arr,n);

}