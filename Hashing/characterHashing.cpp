//Hasing charcters 
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    string s = "MekurYeager";
    string cleaned = "";
    for(char c : s)
    {
        cleaned += tolower(c);
    }

    // cout<<cleaned;

    int hash[26]= {0};

    for(int i=0; i < s.size(); i++)
    {
        hash[ s[i] - 'a' ] += 1 ;
    }

    int q;
    cout<<"How many quries: ";
    cin>>q;

    while(q--)
    {
        char ch;
        cout<<"Enter the query: ";
        cin>>ch;
        cout<<"The letter "<<ch<<" has "<<hash[ch - 'a'];
    }
}