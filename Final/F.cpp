#include <bits/stdc++.h>
using namespace std;
int pref (string s) {
	int n = (int) s.length();
	vector<int> pi (n);
	for (int i=1; i<n; ++i) {
		int j = pi[i-1];
		while (j > 0 && s[i] != s[j])
			j = pi[j-1];
		if (s[i] == s[j])  ++j;
		pi[i] = j;
	}
	return pi.back();
}
int main()
{
    int n,m;
    string s;
    cin >> n;
    for(int i = 1;i<=n;i++){
        cin >> s >> m;
        cout << (s.size())*m - (pref(s))*(m-1) << endl;
    }
}