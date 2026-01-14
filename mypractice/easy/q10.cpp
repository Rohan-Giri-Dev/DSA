#include <iostream>
#include <vector>
using namespace std;

int maxConectutiveLen(vector<int> arr, int k)
{
    int n = arr.size();
    int right = 0, left = 0;
    long long sum = arr[0];
    int maxLen = 0;

    while(right < n){
        while(left <= right && sum > k){
            sum -= arr[left];
            left++;
        }

        if(sum == k){
            maxLen = max(maxLen, right-left+1);
        }

        right++;
        if(right < n) {sum+=arr[right];}
    }

    return maxLen;
}

int main()
{
    vector<int> arr = {10, 5, 2, 0, 0, 7, 1, 9};
    int k = 15;

    cout<<maxConectutiveLen(arr, k);
}