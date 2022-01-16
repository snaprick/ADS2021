#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int t,n,k;
int main()
{
    cin >> t;
    for(int i =0;i<t;i++){
        cin >> n >> k;
        bool ok = (n%k ==0 || n%k%2==1);
        if(k%2==0 && n/k%2==1)
            ok = !ok;
        if(ok)
            cout << "Proggy\n";
        else
            cout << "Buggy\n";
    }
    
}