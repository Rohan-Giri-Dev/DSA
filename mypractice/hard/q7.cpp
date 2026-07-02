#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    // sorting make it easier to compare
    sort(intervals.begin(), intervals.end());

    int n = intervals.size();
    vector<vector<int>> ans;

    for (int i = 0; i < n; i++)
    {
        if (ans.empty() || intervals[1][0] > ans.back()[1])
        {
            // if the ans is empty then just push the element
            // or if the interval start is greater then ans back end

            ans.push_back(intervals[i]);
        }
        else
        {
            // the interval start is less then ans.back() end
            // then just update the max

            ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        }
    }

    return ans;
}   

/*
Trace: [[1,5],[2,6],[3,7]]

i=0: ans empty → push [1,5] → ans = [[1,5]]
i=1: intervals[1][0]=2, compare to ans.back()[1]=5. Is 2 > 5? No → overlap → ans.back()[1] = max(5,6) = 6 → ans = [[1,6]]
i=2: intervals[2][0]=3, compare to ans.back()[1]=6. Is 3 > 6? No → overlap → ans.back()[1] = max(6,7) = 7 → ans = [[1,7]]

Final: [[1,7]].
Trace: [[1,2],[3,4]] (no overlap case)

i=0: ans empty → push [1,2] → ans = [[1,2]]
i=1: intervals[1][0]=3, compare to ans.back()[1]=2. Is 3 > 2? Yes → no overlap → push [3,4] as new group → ans = [[1,2],[3,4]]

Final: [[1,2],[3,4]] — both preserved separately, which is correct.
*/