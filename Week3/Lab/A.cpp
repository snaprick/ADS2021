#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n,m,a[11111];

int main()
{
    cin >> n;
    for(int i =1;i<=n;i++)
    {
        cin >> a[i];
    }
    cin >> m;
    for(int i = 1;i<=n;i++)
    {
        if(a[i]==m)
        {
            cout << i << " ";
        }
    }
}