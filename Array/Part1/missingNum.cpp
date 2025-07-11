// Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.
//Input: nums = [9,6,4,2,3,5,7,0,1]
//Output: 8
//Explanation:
//n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 8 is the missing number in the range since it does not appear in nums.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// int missingNumber(vector<int>& arr) {
//     int n = arr.size();
//     int count = 0;
//     sort(arr.begin(), arr.end());

//     for(int i=0 ; i<=n; i++)
//     {
//         if(arr[i]  == count)
//         {
//             count++;
//         }
//         else{
//             return i;
//         }
//     }

//     return 0;
// }

// optimal solution
int missingNumber(vector<int>& arr) {
    int n = arr.size();
    int sum = n*(n+1)/2; // Total sum

    int res = 0;
    for(int i=0; i<n; i++)
    {
        res += arr[i]; // sum of all the value of array
    }

    return sum-res;
}

int main()
{
    vector<int> arr = {9,6,4,2,3,5,7,0,1};
    vector<int> arr1 = {3,0,1};
    vector<int> arr2 = {0,1};
    cout<< missingNumber(arr)<<endl;
    cout<< missingNumber(arr1)<<endl;
    cout<< missingNumber(arr2)<<endl;

}

