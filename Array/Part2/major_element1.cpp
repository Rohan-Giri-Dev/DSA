// Majority Element is the element that appears more than ⌊n / 2⌋ times.
//Solving using mores voting algorithm

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int majorityElement(vector<int>& arr) {
    int n = arr.size();
    int cnt = 0;
    int el;

    for(int i=0; i<n; i++)
    {
        if(cnt == 0)
        {
            cnt =1;
            el = arr[i];
        }
        else if(arr[i] == el)
        {
            cnt++;
        }
        else{
            cnt--;
        }
    }

    int cnt1=0;

    for(int i=0 ;i<n; i++)
    {
        if(arr[i] == el) cnt1++;
    }

    if(cnt1 > n/2) return el;

    return -1;

}

int main()
{
    vector<int> arr =  {2,2,1,1,1,2,2};
    vector<int> arr1 =  {3,2,3};
    cout<<majorityElement(arr);
    cout<<endl;
    cout<<majorityElement(arr1);

}