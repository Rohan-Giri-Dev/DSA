// 899. Orderly Queue
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string orderlyQueue(string s, int k)
    {

        if (k > 1)
        {
            sort(s.begin(), s.end());

            return s;
        }

        string result = s;
        int n = s.length(); // string length

        for (int i = 1; i <= n - 1; i++)
        {
            string temp = s.substr(i) + s.substr(0, i);

            result = min(result, temp);
        }

        return result;
    }
};

int main()
{

    Solution sol;

    // ---------------- Example 1 ----------------
    string s1 = "cba";
    int k1 = 1;

    string result1 = sol.orderlyQueue(s1, k1);

    cout << "Example 1" << endl;
    cout << "Input: s = \"" << s1 << "\", k = " << k1 << endl;
    cout << "Output: " << result1 << endl;
    cout << "Expected: acb" << endl;

    cout << "\n------------------------\n"
         << endl;

    // ---------------- Example 2 ----------------
    string s2 = "baaca";
    int k2 = 3;

    string result2 = sol.orderlyQueue(s2, k2);

    cout << "Example 2" << endl;
    cout << "Input: s = \"" << s2 << "\", k = " << k2 << endl;
    cout << "Output: " << result2 << endl;
    cout << "Expected: aaabc" << endl;

    return 0;
}