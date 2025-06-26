// Finding the highest and lowest frequency element in an array
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class solution{
public:
    int maxFrequency(vector<int>& num, int k){
        map<int ,int> mpp;

        for(int i=0; i<num.size(); i++)
        {
            mpp[num[i]]++;
        }

        return mpp[k];

        // for(auto it : mpp)
        // {
        //     cout<<it.first << "->" << it.second;
        //     cout<<endl;
        // }

        // for(int i=0 ; i<mpp.size(); i++)
        // {
        //     if(mpp[i] == k)
        //     {
        //         return mpp[i];
        //     }
        // }
        // return 0;

        // return mpp[k];
    }

};

int main()
{
    solution sol;
    vector<int> num = {1,2,2,3,4,2};

    cout<<sol.maxFrequency(num,2);

}

