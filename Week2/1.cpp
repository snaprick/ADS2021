#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    int a[n],cnt = m;
    for(int i =0 ;i<n;i++)
    {
        cin >> a[i];
    }
    vector<char> prime (n+1, true);
    for (int i=2; i<=m; ++i)
        if (prime[i])
            if (i * 1ll * i <= m)
                for (int j=i*i; j<=m; j+=i)
                {
                    prime[j] = false;
                    cnt--;
                }
                    
    cout << m-cnt << endl;
    for(int i=1;i<=m;i++)
    {
        if(prime[i]==true)
        {
            cout << i << endl;
        }
    }
}