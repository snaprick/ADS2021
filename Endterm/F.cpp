#include <bits/stdc++.h> 

const int INF=1e7;
using namespace std;
int d[510][510],d1[510][510],a,b,n,m,used[510];
vector<int> v;
int mx=-1;
void floyd()
{
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i == used[i] && j == used[j] && k == used[k])
                {
                    d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
                } 
            }
        }
    }
}

int main()
{
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin >> d[i][j]; 
        }
        used[i]=-1;
    }
    
    for(int k=1;k<=n;k++)
    {
        int a;
        cin >> a;
        used[a]=a;
        mx = -1;
        floyd();
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if (i == used[i] && j == used[j] && mx < d[i][j])
                {
                    mx = d[i][j];
                }
            }
        }
        cout << mx << "\n";
    }
    // cout << d[17][99] << " " << d[99][17] << "\n";
}