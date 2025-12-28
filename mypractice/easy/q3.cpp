#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool check(vector<int> &nums)
    {
        int n = nums.size();
        

        // vector<int> sortArr = nums;
        // sort(sortArr.begin(), sortArr.end()); // this will store the sorted array
        vector<int>v;
        int ind = -1;
        for(int i=0; i<= n-2; i++){
            if(nums[i] > nums[i+1]){
                ind = i;
                v.insert(v.begin(),nums.begin()+ind+1,nums.end());
                reverse(v.begin(), v.end());
                v.insert(v.end(),nums.begin(),nums.begin()+ind+1);
                break;
            }
        }

        for(int i=0 ; i<=v.size()-2; i++){
            if(v[i] > v[i+1]){
                cout<<"Not sorted";
                return false;
            }
        }

        return true;
    }
};

int main()
{
    vector<int> arr = {3, 4, 5, 2, 1};
    // 1 2 3 4 5 9 6
    // vector<int> arr1 = {5, 6, 7, 8, 4, 3, 2, 1};
    Solution s1;
    cout<<s1.check(arr);
}