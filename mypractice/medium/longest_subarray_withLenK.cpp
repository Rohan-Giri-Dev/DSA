// Find the longest subarray with len k
#include <iostream>
#include <vector>
using namespace std;

int maxLen(vector<int> &arr, int k){
    int n = arr.size();

    int left = 0, right = 0;
    long long sum = arr[0];
    int maxLen = 0;

    while( right < n){
        if(sum > k){
            sum -= arr[left];
            left++;
        }

        if(sum == k){
            maxLen = max(maxLen, right-left+1);
        }
        
        right++;

        if(right < n){
            sum += arr[right];
        }
    }
}

int main(){
    vector<int> arr = {1,2,3,1,1,1,1,3,2};
    int k = 6;

    cout<<"Ans: "<<maxLen(arr,k);
}