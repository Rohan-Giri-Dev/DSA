#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;

int longestConsecutive(vector<int> &arr)
{
    int n = arr.size();

    if (n == 0)
        return 0;

    unordered_set<int> st;
    int longest = 1;

    for (int i = 0; i <= n - 1; i++)
    {
        st.insert(arr[i]);
    }

    for (auto it : st)
    {
        if (st.find(it - 1) == st.end())
        {
            int x = it;
            int count = 1;

            while (st.find(x + 1) != st.end())
            {
                x = x + 1;
                count++;
            }

            longest = max(longest, count);
        }
    }

    return longest;
}

int main()
{
    // vector<int> a = {100, 4, 200, 1, 3, 2};
    vector<int> a = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};

    // Function call for longest consecutive sequence
    int ans = longestConsecutive(a);
    cout << "The longest consecutive sequence is " << ans << "\n";
    return 0;
}

/*
better approach

sort(arr.begin(), arr.end());

    int lastSmaller = INT_MIN;
    int longest = 1;
    int count = 0;

    for (int i = 0; i <= n - 1; i++)
    {
        if (arr[i] == lastSmaller)
        {
            continue;
        }
        else if (lastSmaller + 1 == arr[i])
        {
            count++;
            lastSmaller++;
        }
        else
        {
            count = 1;
            lastSmaller = arr[i];
        }

        longest = max(count, longest);
    }

    return longest;
*/