// Finding the Max Consecutive Ones
#include <iostream>
#include <vector>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& arr) {
    int n = arr.size();
    int count = 0;
    int maxi = 0;

    for(int i=0; i<n ; i++)
    {
        if(arr[i] == 1)
        {
            count++;
            maxi = max(maxi,count);
        }
        else count = 0;
    }

    return maxi;

}

int main()
{
    vector<int> arr = {1,1,0,1,1,1,0,1,1};
    cout<<findMaxConsecutiveOnes(arr);
}