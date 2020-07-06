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
 
 
const ll INF = 1e7;
const ll N =(1e6+5); // TODO : change value as per problem
// const ll MOD = 1e9+9;
const ll SUM = 20005;
ll a[25];
ll dp[1ll<<22][22];
ll popcount2(ll x){
    ll co = 0;
    while(x){
        if(x%3 == 1) co+=1;
        x /= 3;
    }
    return co;
}

bool good(ll i,ll j){
    ll x = a[i];
    ll y = a[j];
    if(__builtin_popcount(x) == __builtin_popcount(y)) return true;
    if(popcount2(x) == popcount2(y))return true;
    return false;
}
vll adj[22];
void solve(){
    ll n;
    cin >> n;
    for(int i =1;i<=n;i++) cin >> a[i-1];
    for(int i =0;i<n;i++){
        for(int j = i+1;j<n;j++){
            if(good(i,j)){
                adj[i].pb(j);
                adj[j].pb(i);
            }
        }
    }
    for(ll mask = 0;mask<(1ll<<n);mask++){
        if(__builtin_popcount(mask) == 1){
            ll opt;
            for(int i = 0;i<n;i++){
                if((mask&(1ll<<i))){
                    opt =i;
                    break;
                }
            }
            dp[mask][opt] = 1;
        }
    }

    for(ll mask = 0;mask<(1ll<<n);mask++){
        if(__builtin_popcount(mask) <= 1) continue;
        for(int i = 0;i<n;i++){
            for(auto j:adj[i]){
                dp[mask][i] += dp[mask^(1ll<<i)][j];
                
            }
        }
    }
    ll ans= 0;

    for(int i = 0;i<n;i++) ans += dp[(1ll<<n) - 1][i];
    cout<<ans;
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
