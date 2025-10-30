#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> st;
        for(int i=0; i<n; i++){
            for(int j= i+1; j<n; j++){
                for(int k=j+1; k<n; k++){
                    for(int l=k+1; l<n; l++){
                        long long sum = nums[i]+nums[j];
                        sum += nums[k];
                        sum += nums[l];
                        if(sum == target){
                            vector<int> temp = {nums[i],nums[j],nums[k],nums[l]};
                            sort(temp.begin(), temp.end());
                            st.insert(temp);
                        }
                    }
                }
            }
        }

        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};

int main(){
    Solution s1;
    vector<int> arr = {1,0,-1,0,-2,2};

    vector<vector<int>> ans = s1.fourSum(arr,0);
    for(auto &row : ans){
        for(auto col : row){
            cout<<col<<" ";
        }
        cout<<endl;
    }

}