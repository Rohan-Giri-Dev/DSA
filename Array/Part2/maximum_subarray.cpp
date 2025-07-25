//Finding the maximum sub array using the Kadane's Algorithm
#include <iostream>
#include <vector>
using namespace std;

int maxSubArray(vector<int>& arr) {
    long long maxi = INT_MIN;
    int sum = 0;
    int ansStart = -1, ansEnd = -1;

    for(int i=0; i<arr.size(); i++)
    {
        int start;
        if(sum == 0) start = i;
        sum += arr[i];

        if(sum > maxi)
        {
            maxi = sum ;
            ansStart = start;
            ansEnd = i;
        }

        if(sum < 0)
        {
            sum = 0;
        }
    }

    return maxi;
}

int main()
{
    vector<int> arr = {-2,1,-3,4,-1,2,1,-5,4};
    cout<<maxSubArray(arr);
}