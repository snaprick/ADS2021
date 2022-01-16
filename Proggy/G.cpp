#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ll n,k=0,cnt=0;
    string s;
    bool ok = true;
    cin >> n;
    for(int i = 1;i<=n;i++){
        cin >> s;
        if(s.size()>=5)
            for(int j=0;j<s.size()-5;j++){
                if(s.substr(j,6)=="Proggy")
                    cnt++;
                if(cnt>2){
                    cout << "NO\n";
                    break;
                }
            }  
        if(cnt<=2)
            cout << "YES\n";
        cnt = 0;
        
    }
    
}