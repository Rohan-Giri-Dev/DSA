#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> traingle;

        for(int i=0; i<numRows; i++){
            //create a row filled with 1's
            vector<int> row(i+1,1);

            for(int j=1; j<i; j++){
                row[j] = traingle[i-1][j-1] + traingle[i-1][j];
            }
           traingle.push_back(row);
        }
        return traingle;
    }
};

int main(){
    Solution s1;
    vector<vector<int>> arr = s1.generate(5);

    for(auto &row: arr){
        for(auto col : row){
            cout<<col<<" ";
        }
        cout<<endl;
    }
}