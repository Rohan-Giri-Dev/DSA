//Check if the array is sorted or not
#include <iostream>
using namespace std;

int checkSorted(int arr[], int n)
{
    for(int i=1; i<n; i++)
    {
        if(arr[i] >= arr[i-1])
        {

        }
        else{
            return false;
        }
    }
    return true;

}

int main()
{
    int arr[] = {1,2,3,4,5,6};
    int arr1[] = {1,2,7,5,4,6};

    cout<<checkSorted(arr,6);
    cout<<endl;
    cout<<checkSorted(arr1,6);

}