// 443. String Compression

#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

class Solution
{
public:
    int compress(vector<char> &chars)
    {
        int n = chars.size();

        int index = 0;
        int i = 0;

        while (i < n)
        {
            char curr_char = chars[i];
            int cnt = 0;

            while (i < n && curr_char == chars[i])
            {
                cnt++;
                i++;
            }

            chars[index] = curr_char;
            index++;

            if (cnt > 1)
            {
                string cnt_char = to_string(cnt);
                for (auto &ch : cnt_char)
                {
                    chars[index] = ch;
                    index++;
                }
            }
        }

        return index;
    }
};

int main()
{
    Solution sol;

    // Test Case 1
    vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};

    int length = sol.compress(chars);

    cout << "Returned Length: " << length << endl;

    cout << "Compressed Array: ";
    for (int i = 0; i < length; i++)
    {
        cout << chars[i];
    }

    cout << endl;

    return 0;
}