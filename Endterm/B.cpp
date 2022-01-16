#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


vector<int> g[1111111];
vector<bool> used;
vector<int> col, ans;
int n, m, l;


bool cycle(int v) {
    col[v] = 1;
    for (int u : g[v]) {
        if (col[u] == 0) {
                if (cycle(u))  
                    return true;
        }             
        else if (col[u] == 1) 
            return true;
    }
    col[v] = 2;
    return false;
}

bool has_cycle() {
    bool ok = false;
    for (int v = 0; v < n; v++) {
        if (!used[v]) {
            if (cycle(v)) {
                ok = true;
                break;
            }
        }
    }
    return ok;
}

void dfs(int v) {
    used[v] = true;
    for (int u : g[v])
        if (!used[u]) 
                dfs(u);
    ans.push_back(v + 1);
}

int main() {
    cin >> n >> m;
    used.resize(n, false);
    col.resize(n, 0);
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
    }
    if (has_cycle()) 
            cout << "Impossible\n";
    else {
        for (int v = 0; v < n; v++) 
            if (!used[v]) 
                    dfs(v);
        reverse(ans.begin(), ans.end());
        cout << "Possible\n";
        for (int v : ans)
            cout << v << " ";
    }
    return 0;
}