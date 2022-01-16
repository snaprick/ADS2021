#include <bits/stdc++.h>
using namespace std;
int used[100000],cnt[100];
int main(){
int n; cin>>n;
string s;
cin>>s;
stack <char> st,st1;
for(int i=0;i<n;i++){
    if(s[i]=='S'){
        st.push(s[i]);
    }
    else{
        st1.push(s[i]);
    }
}
while(!st.empty() && !st1.empty())
{
    for(int i=0;i<n;i++){
        if(s[i] == 'S'){
            if(cnt['K']>0){
                cnt['K']--;
                st.pop();
            }
            else
                cnt[s[i]]++;
        }
        else
        {
            if(cnt['S']>0){
                cnt['S']--;
                st1.pop();
            }
            else
                cnt[s[i]]++;
        }
        if(st.empty() or st1.empty())
            break;
    }  
    cnt['S']=0;
    cnt['K']=0; 
}
if(st.empty())
    cout << "KATSURAGI"; 
else
    cout << "SAKAYANAGI";
}