#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n,m,mx=-1111,mi;

int main()
{
    cin >> n;
    for(int i =1;i<=n;i++)
    {
        cin >> m;
        if(m>mx)
        {
            mx = m;
            mi = i;
        }
    }
    cout << mi;
}