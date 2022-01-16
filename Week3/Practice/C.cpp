#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n,x,y;
    cin >> n >> x >> y;
    long long l =0;
    long long r =1e18;
    while(r>l+1)
    {
        long long m=(l+r)/2;
        double s =(double)(m/x) + (m/y)+1;
        if(s>=n)
        {
            r=m;
        }
        else
        {
            l=m;
        }
    }
    cout << r + min(x,y) << "\n";
    return 0;
}