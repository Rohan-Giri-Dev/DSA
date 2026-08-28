// 1662. Check If Two String Arrays are Equivalent
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2)
    {
        string str1 = "";
        string str2 = "";

        for (auto &ch : word1)
        {
            str1 += ch;
        }

        for (auto &ch : word2)
        {
            str2 += ch;
        }

        if (str1 == str2)
            return true;

        return false;
    }
};

int main()
{
    Solution sol;

    // Example 1
    vector<string> word1_1 = {"ab", "c"};
    vector<string> word2_1 = {"a", "bc"};

    cout << "Example 1:" << endl;
    cout << "Expected: true" << endl;
    cout << "Output:   "
         << (sol.arrayStringsAreEqual(word1_1, word2_1) ? "true" : "false")
         << endl;

    cout << "------------------------" << endl;

    // Example 2
    vector<string> word1_2 = {"a", "cb"};
    vector<string> word2_2 = {"ab", "c"};

    cout << "Example 2:" << endl;
    cout << "Expected: false" << endl;
    cout << "Output:   "
         << (sol.arrayStringsAreEqual(word1_2, word2_2) ? "true" : "false")
         << endl;

    cout << "------------------------" << endl;

    // Example 3
    vector<string> word1_3 = {"abc", "d", "defg"};
    vector<string> word2_3 = {"abcddefg"};

    cout << "Example 3:" << endl;
    cout << "Expected: true" << endl;
    cout << "Output:   "
         << (sol.arrayStringsAreEqual(word1_3, word2_3) ? "true" : "false")
         << endl;

    return 0;
}