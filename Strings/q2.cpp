// 1832. Check if the Sentence Is Pangram

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkIfPangram(string sentence)
    {
        // Store the frequency of each lowercase English letter ('a' to 'z').
        vector<int> arr(26, 0);

        for (char &ch : sentence)
        {
            // Convert the character into its zero-based alphabet index.
            int index = ch - 'a';
            arr[index]++;
        }

        for (auto &cnt : arr)
        {
            if (cnt == 0)
            {
                // A zero frequency means that at least one letter is missing.
                return false;
            }
        }

        // Every letter appears at least once, so the sentence is a pangram.
        return true;
    }
};
