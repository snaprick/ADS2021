#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long w,h,n;
    cin >> w >> h >> n;
    long long l =0;
    long long r =1e18;
    while(r>l+1)
    {
        long long m=(l+r)/2;
        double s =(double)(m/w) * (m/h);
        if(s>=n)
        {
            r=m;
        }
        else
        {
            l=m;
        }

    }
    cout << r << "\n";
    return 0;
}