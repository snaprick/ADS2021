#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int ans = 1,i=1;
int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i =0;i<n;i++){
        cin >> a[i];
    }
    sort(a,a+n,greater<int>());
    for(int i = 0;i<n;i++){
        cout << a[i] << " ";
    }
}