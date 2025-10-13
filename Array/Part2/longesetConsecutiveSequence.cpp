#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        sort(nums.begin(),nums.end());
        int longest = 0;
        int count = 1;

        for(int i=0; i<nums.size(); i++){
            if((nums[i+1] - nums[i]) == 1) count++;

            longest = max(longest,count);
        }

        return longest;
    }
};

int main(){

    Solution s1;
    vector<int> a = {100, 200, 1, 2, 3, 4};
    vector<int> a1 = {0,3,7,2,5,8,4,6,0,1};

    int ans = s1.longestConsecutive(a);
    int ans1 = s1.longestConsecutive(a1);
    cout<<"Longest Consecutive: "<<ans<<endl;
    cout<<"Longest Consecutive: "<<ans1;
}