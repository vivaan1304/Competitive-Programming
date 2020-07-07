/*
Very Intresting Problem
Idea:
  make a dp[u][k] which tells us the maximum value of k nodes we can choose in the subtree of u such that we dont pick any descendants. The Dp can be constructed
  by making 2 cases : 
    a) We pick some node u: if we pick some node u then we cannot pick anything in its subtree so we have to go the next node not in its subtree.
    b) We dont pick node u: then we can just simply go into the next node in the subtree of u
  This can be solved using DP easily.
*/

#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <ratio>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <climits>
#include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back
#define in insert
#define vll vector<ll>
#define endl "\n"
#define pll pair<ll,ll>
#define f first
#define s second
#define int ll
#define sz(x) (ll)x.size()
#define all(x) (x.begin(),x.end())
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> os;
 
 
const ll INF = 1e12;
const ll N =(2e5+5); // TODO : change value as per problem
// const ll MOD = 1e9+9;
const ll SUM = 20005;
ll a[N];
vll adj[N];
ll k;
ll dp[N];
ll dp2[N];
ll inv[N];
ll jump[N]; 
ll counter = 0;
void dfs(ll u,ll p){
    ll pre = counter;
    inv[pre] = u;
    counter++;
    for(auto v:adj[u]){
        if(v==p) continue;
        dfs(v,u);
    }
    jump[pre] = counter;
}
void solve(){
    ll n;
    cin >> n >> k;    
    ll r = 0;
    for(int i =1;i<=n;i++){
        ll u;
        cin >> u >> a[i-1];
        if(u == 0) {r=i-1;continue;} 
        u--;
        adj[u].pb(i-1);
    }
    dfs(r,-1);
    
    for(int i =0;i<=n;i++)dp[i] = -INF;
    dp[0] = 0;
    for(int j =0;j<k;j++){
        for(int i = 0;i<=n;i++) dp2[i] = -INF;
        for(int i =0;i<n;i++){
            dp[i+1] = max(dp[i+1],dp[i]);
            dp2[jump[i]] = max(dp2[jump[i]],dp[i] + a[inv[i]]);
        }
        for(int i =0;i<=n;i++) dp[i] = dp2[i]; 
    }
    ll ans = 0;
    for(int i =0;i<=n;i++) ans = max(ans,dp[i]);
    cout << ans << endl;

}

signed main(){

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    

 
     ll tt=1;   
     // cin >> tt;
    while(tt--){    
        solve();
    }    
}
