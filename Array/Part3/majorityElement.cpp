#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ls;
        int n = nums.size();
        int cnt1 = 0, cnt2 = 0;

        int el1 = INT_MIN;
        int el2 = INT_MIN;

        for(int i=0; i<n; i++){
            if(cnt1 == 0 && el2 != nums[i]){
                el1 = nums[i];
                cnt1 = 1;
            }
            else if(cnt2 == 0 && el1 != nums[i]){
                el2 = nums[i];
                cnt2 = 1;
            }

            else if(el1 == nums[i]) cnt1++;
            else if(el2 == nums[i]) cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }

        // Manually checking the values
        cnt1 = 0, cnt2 = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == el1) cnt1++;
            if(nums[i] == el2) cnt2++;
        }

        int min = (n/3) + 1;

        if( cnt1 >= min) ls.push_back(el1);
        if( cnt2 >= min) ls.push_back(el2);

        return ls;
    }
};

int main(){
    vector<int> arr = {1,2};
    Solution s1 ;
    vector<int> ans = s1.majorityElement(arr);

    for(auto it: ans){
        cout<<it<<" ";
    }
}

// better solution using map
/*
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();

        map<int,int> mp;

        for(auto num : nums){
            mp[num]++;
        }

        for(auto it: mp){
            if(it.second > n/3){
                ans.push_back(it.first);
            }

        }
        return ans;
    }
};
*/