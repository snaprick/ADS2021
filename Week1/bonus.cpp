#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll n,m,ans,mx,pref[1111111],st[1111111],ansl,ansr;
int main()
{
    cin >> n;
    int a[n+2],l[n+2],r[n+2];
    memset(pref,0,sizeof(pref));
    for(int i =0;i<n;i++)
    {
        cin >> a[i];
        
        pref[i] = pref[i-1]+a[i];
    }
    a[n+1]=-1;
    ll top = 0;
    for(int i =1;i<=n;i++)
    {
        if(top == 0 || a[i] > a[st[top-1]])
        {
            st[top] = i;
            l[i] = i;
            top++;
            continue;
        }
        if(a[i] == a[st[top-1]])
        {
            continue;
        }
        while(top >=1 && a[i] < a[st[top-1]])
        {
            top--;
            ans = a[st[top]]*(pref[i-1]-pref[l[st[top]]-1]);
            if(ans > mx)
            {
                ansl = l[st[top]];
                ansr = i-1;
                mx = ans;
            }
        }
        l[i] = l[st[top]];
        st[top]=i;
        top++;
    }
    cout << ans << endl << ansl << " " << ansr; 
}