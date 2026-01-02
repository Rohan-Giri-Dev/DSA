#include <iostream>
#include <vector>
#include <map>
using namespace std;

/*Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
Explanation: Your function should return k = 5,*/

int removeDuplicates(vector<int> &arr)
{
    int n = arr.size();

    int i = 0;

    for (int j = 1; j <= n - 1; j++)
    {
        if (arr[j] != arr[i])
        {
            arr[i + 1] = arr[j];
            i++;
        }
    }

    return i + 1;
}

int main(){
    vector<int> arr = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    vector<int> arr1 = {1, 1, 2};

    cout<<removeDuplicates(arr)<<endl;
    cout<<removeDuplicates(arr1)<<endl;
}