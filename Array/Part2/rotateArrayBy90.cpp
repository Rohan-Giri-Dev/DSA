#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // vector<vector<int>> newMatrix;
        int ansArr[n][n];

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                ansArr[j][(n-1) - i] = matrix[i][j];
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                matrix[i][j] = ansArr[i][j];
            }
        }
    }
};

int main(){
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    Solution s;
    s.rotate(matrix);

    for(auto r: matrix){
        for(auto c: r){
            cout<<c<<" ";
        }
        cout<<endl;
    }
}