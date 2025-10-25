#include <iostream>
#include <vector>
#include <map>
using namespace std;

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
            if(it.second > n){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};

int main(){
    vector<int> arr = {1,2,2,2,1};
    Solution s1 ;
    vector<int> ans = s1.majorityElement(arr);

    for(auto it: ans){
        cout<<it;
    }
}