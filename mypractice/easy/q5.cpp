#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rotate(vector<int> &nums, int k)
{
    int n = nums.size();
    k %= n;

    reverse(nums.begin(), nums.end()); // this will reverse the whole array 1234567 -> 7654321
    reverse(nums.begin(), nums.begin()+k); // step 2: reverse till k - > 765 -> 567
    reverse(nums.begin() + k, nums.end());// step 3: reverse till k to end -> 4321 -> 1234
    
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    rotate(arr,3);

    for(auto &x : arr){
        cout<<x <<" ";
    }
}