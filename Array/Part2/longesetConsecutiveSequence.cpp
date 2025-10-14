#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        sort(nums.begin(),nums.end());
        int longest = 1;
        int count = 1;

        for(int i=1; i<nums.size(); i++){
            if(nums[i] == nums[i-1]) continue;
            else if((nums[i] - nums[i-1]) == 1) count++;
            else count = 1;

            longest = max(longest,count);
        }

        return longest;
    }
};

int main(){

    Solution s1;
    vector<int> a = {100, 200, 1, 2, 3, 4};
    vector<int> a1 = {1,0,1,2};

    int ans = s1.longestConsecutive(a);
    int ans1 = s1.longestConsecutive(a1);
    cout<<"Longest Consecutive: "<<ans<<endl;
    cout<<"Longest Consecutive: "<<ans1;
}