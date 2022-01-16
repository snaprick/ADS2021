#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int binpow (int a, int n) {
	int res = 1;
	while (n) {
		if (n & 1)
			res *= a;
		a *= a;
		n >>= 1;
	}
	return res;
}

int main()
{
    ll n;
    cin >> n;
    cout << binpow(2,n);
}