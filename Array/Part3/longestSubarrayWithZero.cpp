#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
    public:
    int largestSub(vector<int> arr){
        int n = arr.size();
        int maxi = 0, sum = 0;
        map<int,int> mpp;

        for(int i=0; i<n; i++){
            sum += arr[i];
            if(sum == 0){
                maxi = i+1;
            }
            else if(mpp.find(sum) != mpp.end()){
                maxi = max(maxi, i - mpp[sum]);
            }
            else {
                mpp[sum] = i;
            }

        }

        return maxi;
    }
};

int main()
{
    Solution s1;
    vector<int> arr = {9,-3,3,-1,6,-5};

    int ans = s1.largestSub(arr);
    cout<<ans;

}