#include <bits/stdc++.h>

using namespace std;
long long n, k, a[111111];

bool f(long long val, long long sum, long long cnt) {
    for (int i = 0; i < n; i++) {
        if (val < a[i])
            return false;
        sum += a[i];
        if (sum > val){
            cnt++;
            sum = a[i];
        }
    }
    if (sum != 0)
        cnt++;
    if (k < cnt)
        return false;
    return true;
}

long long bp(long long  l, long long r) {
    while(l+1<r){
        long long m = (l+r)>>1;
        if(f(m,0,0))
            r = m;
        else
            l = m;
    }
    return r;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << bp(0,1e17) << endl;
    return 0;
}