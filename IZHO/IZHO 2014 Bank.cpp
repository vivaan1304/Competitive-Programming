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
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/trie_policy.hpp>
#define ll int
#define endl "\n"
// #define int 
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> os;
 
 
// const ll INF = 1e12;
const ll N =(22); // TODO : change value as per problem
// const ll MOD = 1e9+7;


ll a[N];
ll b[N];
vector<ll> nice[N];
ll dp[N][(1<<22) + 5];
ll n,m;
inline ll recurse(ll i,ll j){
    if(i > n) {
        cout << "YES\n";
        exit(0);
    }
    if(dp[i][j]!=-1) return dp[i][j];
    
    for(auto k:nice[i]){
        if(!(k & j) && recurse(i+1,j ^ k)) {
            return dp[i][j] = 1;
        }
        
    }
    return dp[i][j] = 0;
}

void solve(){
    cin >> n >> m;    
    for(int i = 1;i<=n;i++) cin >> a[i];
    for(int i= 1;i<=m;i++) cin >> b[i];
    for( int i = 0 ; i < ( 1<<m ) ; i++ ) {
        int sum = 0;
        for( int j = 0 ; j < m ; j++ ) if( i & ( 1<<j ) ) sum += b[j+1];
        for( int j = 0 ; j < n ; j++ ) if( a[j+1] == sum ) nice[j+1].emplace_back( i );
    }
    for(int i =1;i<=n;i++){
        for(int j =0;j<(1<<m);j++) dp[i][j] = -1;
    }
    bool gg = recurse(1,0);
    if(gg) cout << "YES\n";
    else cout << "NO\n";
    // cout << recurse(1,0) << endl;
    // cout << ans << endl;
}

signed main(){

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    

 
     ll tt=1;   
    while(tt--){    
        solve();
    }    
}
