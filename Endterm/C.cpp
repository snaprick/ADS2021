#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,k;
vector<int> g[505];
int col[505];
void dfs(int v){
	col[v]=2;
	for(auto u : g[v]){
		if(col[u]==2) 
            ++k;
		else 
            if(!col[u]) 
                dfs(u);
	}
	col[v]=1;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin >> a >> b;
		g[a].push_back(b);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
            col[j]=0;
		k=0;
		dfs(i);
		if(k<=1){
			cout<<"YES"<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;
	return 0;
}