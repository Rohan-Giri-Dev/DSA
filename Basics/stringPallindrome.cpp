#include <iostream>
#include <string>
#include <cctype> 
using namespace std;

class solution{
public:
    bool isPallindrome(string s)
    {

        if(s == "") return true;

        string cleaned = "";
        for( char c : s){
            if( isalpha(static_cast <unsigned char> (c)) || isdigit(static_cast <unsigned int> (c)) )
            {
                cleaned += tolower(static_cast <unsigned char> (c));
            }
        }

        cout<<endl<<cleaned<<endl;

        for(int i = 0; i < cleaned.size(); i++)
        {
            if(cleaned[i] != cleaned[cleaned.size() - i - 1]){
                return false;
            }
        }

        return true;

    }
};

int main()
{
    solution sol;
    cout<<sol.isPallindrome("A man, a plan, a canal: Panama");
    cout<<sol.isPallindrome("race a car");
    cout<<sol.isPallindrome("0P");
    cout<<sol.isPallindrome("R1");
}