#include <iostream> 

using namespace std;

using ll = long long;

int a[111111],m,b,s[1111][1111];
int n, k, l, r,l1,r1,t;
bool ok;

void bp(int x, int y) {
    l = 0;
    r = m-1;
    while(l+1<r){
        int m = (l+r)>>1;
        if(x < s[y][m])
            l = m;
        else
            r = m;
    }
}

void bp2(int x, int y){
    l = 0;
    r = m-1;
    while(l+1<r){
        int m = (l+r)>>1;
        if(x >= s[y][m])
            l = m;
        else
            r = m;
    }
}

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> a[i];
    }
    cin >> n >> m;
    for(int i = 0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> s[i][j];
        }
    }
    for(int i = 0;i<t;i++){
        ok = true;
        for(int j=0;j<n;j++){
            if(j%2==0)
                bp(a[i],j);
            else
                bp2(a[i],j);
            if(s[j][l] == a[i]){
                cout << j << " " << l << endl;
                ok = false;
                break;
            }
            else if(s[j][r] == a[i]){
                cout << j << " " << r << endl;
                ok = false;
                break;
            }
        }
        if(ok){
            cout << -1 << endl;
        }
    }
    return 0;
}