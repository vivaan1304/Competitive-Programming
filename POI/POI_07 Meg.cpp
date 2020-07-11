/*
When we want range updates and point queries on a BIT use the trick add(l,x) and add (r+1,-x) to update range and sum(x) for point query at position x.
Linerise the given tree to form a array.
*/

#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
// #include <cgridh>
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
#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define int ll
#define sz(x) (ll)x.size()
#define all(x) (x.begin(),x.end())
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> os;
 
 
const ll INF = 1e12;
const ll N =(3e5+5); // TODO : change value as per problem
const ll MOD = 1e9+7;

vll adj[N];
ll ft[2*N];
ll tin[N];
ll tout[N];
ll t;
ll dist[N];
ll n;
void dfs(ll u,ll p,ll h){
	dist[u] = h;
	t++;
	tin[u] = t;
	for(auto v:adj[u]){
		if(v == p) continue;
		dfs(v,u,h+1);
	}
	tout[u]=t;
}

void upd2(int x, int v){
		while(x <= n){
			ft [x] += v;
			x += x & -x;
		}
	}
int query(int x){
		int ret = 0;
		while(x){
			ret += ft[x];
			x -= x & -x;
		}
		return ret;
	}
void solve(){
	cin >> n;
	for(int i =2;i<=n;i++){
		ll u,v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
		
	}
	dfs(1,0,0);
	
	ll q;
	cin >> q;
	q += n - 1;
	while(q--){
		char ch;
		cin >> ch;
		if(ch == 'A'){
			ll u,v;
			cin >> u >> v;
			if(dist[u] > dist[v]) swap(u,v);
			// -1 in the subtree of v
			// [tin[v],tout[v]-1]
			
			upd2(tin[v],1);
			upd2(tout[v]+1,-1);
		}	
		else{
			ll x;
			cin >> x;
			cout << dist[x]- query(tin[x]) << endl;
		}

	}


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
// 1 2 1 3 1 4 5 4 1 

/*
1 1 10
2 2 3
3 4 5
4 6 9
5 7 8
*/
