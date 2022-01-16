#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int t,n,k,cnt;
string s;
vector <string> v;
int main()
{
    cin >> t;
    for(int i=0;i<t;i++){
        cin >> s;
        sort(s.begin(),s.end());
        v.push_back(s);
    }
    sort(v.begin(),v.end());
    for(int i =0;i<v.size()-1;i++)
    {
        if(v[i]!=v[i+1]){
            cnt++;
        }
    }
    cout << cnt+1;
}