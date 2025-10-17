#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int l = 0; //left
        int r = m-1; //right
        int t = 0; // top
        int b = n-1; //bottom

        vector<int> ans;

        while( t <= b && l <= r){
        for(int i = l; i<=r; i++){
            ans.push_back(matrix[t][i]);
        }
        t++;

        for(int i= t; i<= b; i++){
            ans.push_back(matrix[i][r]);
        }
        r--;

        if(t<=b){
            for(int i = r; i>=l; i--){
                ans.push_back(matrix[b][i]);
            }
            b--;
        }

        if(l<=r){
            for(int i= b; i>=t; i--){
                ans.push_back(matrix[i][l]);
            }
            l++;
        }
        
    }
    return ans;
    }

};

int main(){
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};

    Solution s1;

    vector<int> ans;
    ans = s1.spiralOrder(matrix);

    for(auto x : ans){
        cout<<x<<" ";
    }

}