// Union of an array
#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> unionArr(vector<int> &a1, vector<int> &a2)
{
    vector<int> temp;
    int n1 = a1.size();
    int n2 = a2.size();

    set<int> st;
    for(int i=0; i<n1; i++)
    {
        st.insert(a1[i]);
    }
    for(int i=0; i<n2; i++)
    {
        st.insert(a2[i]);
    }

    for(auto it : st)
    {
        temp.push_back(it);
    }

    return temp;
}

int main()
{
    vector<int> a1 = {1,2,4,4,5,5,7};
    vector<int> a2 = {1,2,5,5,6,9};

    vector<int> temp = unionArr(a1,a2);

    cout<<"Union ";
    for(auto it : temp)
    {
        cout<<it<<" ";
    }

    cout<<endl;
}