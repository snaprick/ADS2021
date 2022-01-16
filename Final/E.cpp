#include <bits/stdc++.h>
using namespace std;
vector<int> g[100005];
vector <int> ans,one,ans1,usd;
vector <pair<int,int>> two;
int cnt;
int used[100005];
void dfs (int v) {
	used[v] = true;
	for (auto u : g[v]) 
    {
		if (!used[u])
			dfs (u);
    }
    ans.push_back(v);
}
int main(){
    int n,m,a,b;
    cin >> n >> m;
    for(int i =0;i<m;i++){
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i = 1;i<=n;i++){
        if(!used[i]){
            dfs(i);
            cnt++;
            if(ans.size()>3){
                cout << "-1";
                return 0;
            }
            if(ans.size() == 1){
                one.push_back(ans[0]);
            }
            else if(ans.size()==2){
                two.push_back(make_pair(ans[0],ans[1]));
            }
            else{
                ans1.push_back(ans[0]);
                ans1.push_back(ans[1]);
                ans1.push_back(ans[2]);
            }
            // cout << ans.size() << endl;
            ans.clear();
        }
    }
    if(two.size()>n-ans1.size()*3-two.size()*2){
        cout << "-1";
        return 0;
    }
    int j = 0;
    for(int i = 0;i<two.size();i++){
        cout << two[i].first << " " << two[i].second << " " << one[i] << endl;
        j++;
    }
    for(int i = 0;i<ans1.size();i++){
        cout << ans1[i] << " ";
        if((i+1)%3==0)
            cout << endl;
    }
    if((one.size()-two.size())%3==0){
        for(j;j<one.size();j++){
            cout << one[j] << " ";
            if((j+1)%3==0)
                cout << endl;
        }
    }
    else{
        cout << "-1";
    }
    // cout << cnt;
}