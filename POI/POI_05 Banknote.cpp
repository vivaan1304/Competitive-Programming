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
#define ll int
#define ld long double
#define mp make_pair
#define pb push_back
#define in insert
#define vll vector<ll>
#define endl "\n"
#define pll pair<ll,ll>
#define f first
#define s second
// #define int ll
#define sz(x) (ll)x.size()
#define all(x) (x.begin(),x.end())
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> os;
 
 
const ll INF = 1e7;
const ll N =(200+5); // TODO : change value as per problem
// const ll MOD = 1e9+9;
const ll SUM = 20005;
ll b[N];ll c[N];
ll dp[SUM];
ll par[N][SUM];
void solve(){
    ll n;
    cin >> n;
    for(int i = 1;i <= n;i++) 
        cin >> b[i];
    for(int i = 1;i <= n;i++)
        cin >> c[i];
    ll sum;
    cin >> sum;

    for(int k = 1;k<=sum;k++){
        dp[k] = INF;
        ll opt = -1;
        for(int i = 1;i<=n;i++){
            if(k-b[i] < 0 || par[i][k-b[i]] >= c[i]) continue;
            if(dp[k] >= dp[k-b[i]] + 1){
                dp[k] = dp[k-b[i]] + 1;
                opt = i;
            }
        }
        if(opt != -1){
            for(int i = 1;i<=n;i++){
                par[i][k] = par[i][k-b[opt]];
                if(opt == i) par[i][k]++; 
            }
        }
    }
    cout << dp[sum] << endl;
    for(int i =1;i<=n;i++) cout << par[i][sum] << " ";cout<<"\n";
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
