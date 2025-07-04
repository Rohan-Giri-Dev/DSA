#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int sLargest(vector<int> &arr, int n)
{
    int largest = arr[0];
    int sndlargest = -1;

    for(int i = 1; i < n; i++)
    {
        if(arr[i] > largest)
        {
            sndlargest = largest;
            largest = arr[i];
        }
        else if(arr[i] < largest && arr[i] > sndlargest)
        {
            sndlargest = arr[i];
        }
    }

    return sndlargest;
}
int sSmallest(vector<int> &arr, int n)
{
    int smallest = arr[0];
    int sndSmallest = INT_MAX;
    for(int i=1; i<n; i++)
    {
        if(arr[i] < smallest)
        {
            sndSmallest =  smallest;
            smallest = arr[i];
        }
        else if(arr[i] != smallest && arr[i] < sndSmallest)
        {
            sndSmallest = arr[i];
        }

    }
    return sndSmallest;


}

vector<int> getSecondOrderElement(vector<int> &arr, int n)
{
    int ndLargest = sLargest(arr,n);
    int ndSmallest = sSmallest(arr,n);

    return {ndLargest, ndSmallest};
}

int main()
{
    vector<int> arr = {1,2,3,4,5,6,7};

    vector<int> result = getSecondOrderElement(arr,arr.size());
    cout<<"Second largest: "<<result[0];
    cout<<"Second smallest: "<<result[1];
    
}
