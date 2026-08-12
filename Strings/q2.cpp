// 1832. Check if the Sentence Is Pangram

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkIfPangram(string sentence)
    {
        vector<int> arr(26, 0); // created an array of size 26 and assigning value to 0

        for (char &ch : sentence)
        {
            int index = ch - 'a'; // as all are lowercase. So we can just find the index
            arr[index]++;         // then do ++. To count
        }

        for (auto &cnt : arr)
        {
            if (cnt == 0)
            {
                // if any char is not their then its index will be zero
                return false;
            }
        }

        return true;
    }
};