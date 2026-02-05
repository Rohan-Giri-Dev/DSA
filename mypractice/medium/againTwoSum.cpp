#include <iostream>
#include <map>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> ans;
    map<int, int> mpp;

    for(int i=0; i<n; i++){
        int a = arr[i];
        int more = k - a;

        if(mpp.find(more) != mpp.end()){
            ans.push_back(i);
            ans.push_back(mpp[more]);
            return ans;
        }

        mpp[a] = i;
    }

    return {};
}

int main()
{
    vector<int> arr1 = {2, 7, 11, 15};
    int k1 = 9;

    vector<int> res1 = twoSum(arr1, k1);
    if (!res1.empty())
    {
        cout << "Example 1: indices = " << res1[0] << ", " << res1[1] << "\n";
        cout << "values  = " << arr1[res1[0]] << ", " << arr1[res1[1]] << "\n";
    }
    else
    {
        cout << "Example 1: No pair found\n";
    }
}