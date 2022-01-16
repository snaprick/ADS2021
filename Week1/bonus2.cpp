#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll n,m,ans,mx,pref[1111111],st[1111111],ansl,ansr;
stack <ll> st1,st2;
int main()
{
    cin >> n;
    int a[n+2],l[n+2],r[n+2];
    memset(pref,0,sizeof(pref));
    for(int i =1;i<=n;i++)
    {
        cin >> a[i];
        pref[i] = pref[i-1]+a[i];
    }
    a[n+1]=-1;
    for(int i = 1;i<=n;i++)
    {
        if(st1.empty() || a[i] > a[st1.top()])
        {
            st1.push(i);
            l[i] = i;
            continue;
        }
        if(a[i] == a[st1.top()])
        {
            continue;
        }
        st2=st1;
        while(st2.size()>=1 && a[i] < a[st2.top()])
        {
            ans = a[st2.top()]*(pref[i-1]-pref[l[st2.top()]-1]);
            if(ans > mx)
            {
                ansl = l[st2.top()];
                ansr = i-1;
                mx = ans;
            }
            st2.pop();
        }
        l[i] = l[st1.top()];
        st1.top()=i;
    }
    cout << mx << endl << ansl << " " << ansr << endl;
    while(!st1.empty())
    {
        cout << st1.top() << " ";
        st1.pop();
    }
    cout << endl;
    for(int i=1;i<=n;i++)
    {
        cout << l[i] << " ";
    }
}