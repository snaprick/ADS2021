#include <bits/stdc++.h>
using namespace std;
int n,k,b,x,l,r,m;
int find_upper(int *a,int n,int x)
{
    int l=-1;
    int r=n;
    while(r>l+1)
    {
        int m=(l+r)/2;
        if(a[m]<x)
        {
            l=m;
        }
        else
        {
            r=m;
        }
        
    }
    return r;
}
int find_lower(int *a,int n,int x)
{
    int l=-1;
    int r=n;
    while(r>l+1)
    {
        int m=(l+r)/2;
        if(a[m]<=x)
        {
            l=m;
        }
        else
        {
            r=m;
        }
        
    }
    return l;
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> k;
    int a[n+1];
    for(int i =0;i<n;i++)
    {
        cin >> a[i];
    }
    while(k--)
    {
        cin >> x;
        m = find_lower(a,n,x);
        if(x==a[m] && m !=-1)
        {
            cout << find_upper(a,n,x)+1 << " " << m+1 << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }
}