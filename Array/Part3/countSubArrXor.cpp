#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int subarraysWithXorK(vector<int> a, int k){
    int n = a.size();
    int count = 0;

    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            int xorr = 0;
            for(int k=i; k<j; k++){
                xorr = xorr ^ a[k];

                if(xorr == k){
                    count++;
                }
            }
        }
    }
    return count;
}

int main()
{
    vector<int> a = {4, 2, 2, 6, 4};
    int k = 6;
    int ans = subarraysWithXorK(a, k);
    cout << "The number of subarrays with XOR k is: "
         << ans << "\n";
    return 0;
}