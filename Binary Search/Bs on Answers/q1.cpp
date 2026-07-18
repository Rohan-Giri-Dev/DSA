// find the root of the number
// using binary search

#include <iostream>
using namespace std;

int floor(int n){
    int low = 1, high = n;
    int ans = 1;

    while(low <= high){
        long long mid = (low+high)/2;

        if( mid * mid <= n){
            ans = mid;
            low = mid+1;
        }else{
            high = mid-1;
        }
    }

    return ans;
}