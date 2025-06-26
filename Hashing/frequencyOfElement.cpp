// You are given an integer array nums and an integer k. In one operation, you can choose an index of nums and increment the element at that index by 1.
// Return the maximum possible frequency of an element after performing at most k operations.
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution{
public:
    void maxFrequency(vector<int> &num, int k)
    {
        // num = {1,2,4} k = 5
        while (k--)
        {
            for(int i=0; i <num.size(); i++)
            {
                if(num[i] < num[i+1])
                {
                    num[i]++;
                }
            }

        }

        for(int i=0; i<num.size(); i++)
        {
            cout<<num[i]<<endl;
        }

        map<int, int> mpp;


        for(int i=0; i<num.size(); i++)
        {
            mpp[num[i]]++;
        }

        for(auto it : mpp)
        {
            cout<<it.first<<"->"<<it.second<<endl;
        }
        

    }
};

int main()
{
    vector<int> num = {1,2,4};
    Solution sol;
    sol.maxFrequency(num, 5);
}