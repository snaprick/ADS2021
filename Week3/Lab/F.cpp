#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n,m,mn,mx;

int main()
{
    cin >> n;
    int a[n+1];
    cin >> a[0];
    mn = a[0];
    mx = a[0];
    for(int i=1;i<n;i++)
    {
        cin >> a[i];
        if(a[i]>mx)
        {
            mx = a[i];
        }
        if(a[i]<mn)
        {
            mn = a[i];
        }
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]==mx)
        {
            cout << mn << " ";
            continue;
        }
        cout << a[i] << " ";
    }
}