#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        int rowMat[row] = {0};
        int colMat[col] = {0};
        
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(matrix[i][j] == 0){
                    rowMat[i] == 1;
                    colMat[j] == 1;
                }
            }
        }

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(rowMat[i] == 1 || colMat[j] == 1){
                    matrix[i][j] == 0;
                }
            }
        }
    }
};



int main(){
    vector<vector<int>> matrix = {
    {0,1,2,0},
    {3,4,5,2},
    {1,3,1,5}};

    Solution s1;

    s1.setZeroes(matrix);

    for(auto &row : matrix){
        for(auto col : row){
            cout<<col;
        }
        cout<<endl;
    }

}
