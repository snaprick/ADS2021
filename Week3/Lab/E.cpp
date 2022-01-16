#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n,m,mx=-1111,mx2;

int main()
{
    cin >> n;
    for(int i =1;i<=n;i++)
    {
        cin >> m;
        if(m > mx)
        {
            mx2 =mx;
            mx = m;
        }
        if(m > mx2 && m < mx)
        {
            mx2=m;
        }
    }
    cout << mx2;
}