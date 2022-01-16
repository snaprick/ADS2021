#include <iostream> 

using namespace std;

using ll = long long;

int n,m,sum[111111],a[600][600],s[600],sumj,sumj1;

bool f(int a1, int a2, int sumj,int sumj1){
    if(sumj==sumj1){
        for(int k=0;k<m;k++){
            if(a[a1][k]!=a[a2][k]){
                return a[a1][k]>a[a2][k];
            }
        }
    }   
    return sumj<sumj1;
}
int main()
{
    cin >> n >> m;
    for(int i =0;i<n;i++){
        s[i]=i;
    }
    for(int i=0;i<n;i++)
    {
        for(int j =0;j<m;j++)
        {
            cin >> a[i][j];
            sum[i]+=a[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(f(s[j],s[j+1],sum[s[j]],sum[s[j+1]])){
                swap(s[j],s[j+1]);
            }
                
        }
    }
    for(int i=0;i<n;i++){
        for(int j =0;j<m;j++){
            cout <<  a[s[i]][j] << " ";
        }
        cout << endl;
    }
}