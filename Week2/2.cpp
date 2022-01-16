#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main()
{
    int n,m;
    cin >> n;
    vector<char> prime (111111, true);
    prime[0] = prime[1] = false;
    for (int i=2; i<=111111; ++i)
        if (prime[i])
            if (i * 1ll * i <= 111111)
                for (int j=i*i; j<=111111; j+=i)
                {
                    prime[j] = false;
                }
    while(true)
    {
        if(prime[n]==true)
        {
            cout << n << endl;
            break;
        }
        n++;
    }
}