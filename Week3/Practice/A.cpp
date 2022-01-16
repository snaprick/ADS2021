#include <bits/stdc++.h>
using namespace std;
int n,k,b,x,l,r;
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
    cin >> n;
    int a[n+1];
    for(int i =0;i<n;i++)
    {
        cin >> a[i];
    }
    sort(a,a+n);
    cin >> k;
    while(k--)
    {
        cin >> l >> r;
        cout << find_lower(a,n,r)-find_upper(a,n,l)+1 << "\n";
    }
}