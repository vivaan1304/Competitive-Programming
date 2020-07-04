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
 
 
const ll INF = 1e18;
const ll N =(1e2+5); // TODO : change value as per problem
const ll MOD = 1e9+7;
ll dp[N][N][10];
ll a[N];
ll n,k;
bool vis[N][N][10];
ll DP(ll l,ll r,ll cur)
{
    if(l > r) return 0;
    if(l == r) {
        if(cur + 1 >= k) return 0;
        else return k-(cur+1);
    }
    if(vis[l][r][cur] != false) return dp[l][r][cur];
    ll ans = INF;
    if(cur < k-1) ans = min(ans,DP(l,r,cur+1) + 1);
    else if(cur == k-1) ans = min(ans,DP(l+1,r,0));
    for(int i = l+1;i<=r;i++){
        if(a[i] != a[l]) continue;
        ans = min(ans,DP(l+1,i-1,0) + DP(i,r,min(k-1,cur+1)));
    }
    vis[l][r][cur] = true;
    return dp[l][r][cur] = ans;
}

void solve(){
    cin >> n >> k;
    for(int i =1;i<=n;i++) cin >> a[i];
    cout << DP(1,n,0) << endl;
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
