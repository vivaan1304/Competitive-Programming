#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define vll vector<ll>
#define fastio ios_base::sync_with_stdio(0),cin.tie(NULL),cout.tie(NULL);
using namespace std;
const ll LMAO = 1e3+2;
const ll N = 1e4+10;
const ll MOD = 1e9+7;
ll st[N][26];
ll arr[N];
ll dp[N];
ll LOG[N];

ll query(ll l,ll r)
{
    ll j = LOG[r-l+1];
    return (max(st[l][j] , st[r-(1<<j)+1][j])*(r-l+1));
}



int main()
{    

    fastio;

    ifstream fin("teamwork.in");
    ofstream fout("teamwork.out");
    LOG[1] = 0;
    for(int i=2;i<N;i++)
    {
        LOG[i] = LOG[i/2] + 1;
    }

    ll n,k;

    fin >> n >> k;
    for(int i = 1;i<=n;i++)
        fin >> arr[i];

    for(int i = 1;i<N;i++)
    {
        st[i][0] = arr[i];
    }
    
    for(int j = 1;j<=25;j++)
    {
        for(int i = 0;i+((1<<j))<N;i++)
        {
            st[i][j] = max(st[i][j-1], st[i+(1<<(j-1))][j-1]);
        }
    }

    dp[1] = arr[1];
    for(int i =2;i<=n;i++)
    {
        for(int j = 0;j<i;j++)
        {
            if((i-j) > k) continue;
            dp[i] = max(dp[i],dp[j] + query(j+1,i));
        }
    }
 
    fout << dp[n] << endl;

       





    return 0;
    
}   
