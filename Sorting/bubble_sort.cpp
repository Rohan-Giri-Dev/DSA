// Bubble sort
#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
    for(int i= n-1; i >= 1; i--)
    {
        int didSwap = 0;
        for(int j=0; j < i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                didSwap = 1;
            }
        }
        if(didSwap == 0) break;
        cout<<"Swap"<<endl;

    }
}

void print_array(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}

int main()
{
    int arr[] = { 9,4,7,2,5,1,3,8,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    print_array(arr, n);
    bubbleSort(arr,n);
    print_array(arr, n);

}
