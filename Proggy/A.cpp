#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int ans = 1,i=1;
int main()
{
    int x;
    cin >> x;
    if(x==1 || x == 0){
        cout << 1;
        return 0;
    }
    while(ans<x){
        ans*=i;
        i++;
    }
    if(ans==x){
        cout << --i;
    }
    else
        cout << 0;
}