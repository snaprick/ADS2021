#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Heap {
	ll n;
	ll a[1000000];
	Heap(ll n = 0) {
		this->n = n;
	}
	void insert(ll x) {
		ll i = n;
		a[n++] = x;
		while (i > 0 and a[i] < a[(i - 1) / 2]) {
			swap(a[i], a[(i - 1) / 2]);
			i = (i - 1) / 2;
		}
	}

	ll extractMin() {
		ll ans = a[0];
		a[0] = a[--n];
		ll i = 0;
		while (true) {
			ll j = i;
			if (i * 2 + 1 < n and a[i * 2 + 1] < a[j])
				j = i * 2 + 1;
			if (i * 2 + 2 < n and a[i * 2 + 2] < a[j])
				j = i * 2 + 2;
			if (i == j)
				break;
			swap(a[i], a[j]);
			i = j;
		}
		return ans;
	}
};
ll a[111111];
int main() {
	ll n, x;
	cin >> n;
	Heap new_heap;
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
		new_heap.insert(a[i]);
	}
	ll ans = 0, z = 0;
	for (ll i = 0; i < n-1; i++) {
		z = new_heap.extractMin() + new_heap.extractMin();
		ans += z;
		new_heap.insert(z);
	} 
    cout << ans;
}