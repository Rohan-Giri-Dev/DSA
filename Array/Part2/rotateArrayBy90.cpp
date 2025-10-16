#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // reverse the arry
        for(auto &row : matrix){
            reverse(row.begin(), row.end());
        }
    }

};

int main(){
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    Solution s;
    s.rotate(matrix);
    cout<<"Expeted output\n";
    cout<<"7 4 1\n";
    cout<<"8 5 2\n";
    cout<<"9 6 3";
    cout<<endl;
    cout<<endl;
    cout<<endl;

    for(auto r: matrix)
    {
        for(auto c: r){
            cout<<c<<" ";
        }
        cout<<endl;
    }
}


/*
Brute Force approac
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
*/