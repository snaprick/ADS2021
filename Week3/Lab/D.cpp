#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n,m,mx=-1111,mi,mnj,cnt;

int main()
{
    cin >> n >> m;
    int sz = max(m,n);
    int mn[sz+2],mx[sz+2],a[n+2][m+2];
    memset(mn, 1111, sizeof(mn));
    memset(mx, -1111, sizeof(mx));
    for(int i = 1;i<=n;i++)
    {
        for(int j =1;j<=m;j++)
        {
            cin >> a[i][j];
            if(a[i][j]<mn[i])
            {
                mn[i]=a[i][j];
            }
        }
    }
    for(int j = 1;j<=m;j++)
    {
        for(int i =1;i<=n;i++)
        {
            if(a[i][j]>mx[j])
            {
                mx[j]=a[i][j];
            }
        }
    }
    for(int i = 1;i<=n;i++)
    {
        for(int j =1;j<=m;j++)
        {
            if(a[i][j] == mn[i] && a[i][j] == mx[j])
            {
                cnt++;
            }
        }
    }
    cout << cnt;
}