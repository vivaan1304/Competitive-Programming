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
const ll N =(1e5+5); // TODO : change value as per problem
const ll MOD = 1e9+7;
vll adj[N];
ll c[N];
ll leader[N];
multiset<ll> se[N];// sack
ll sub[N];// subtree sum
ll ans;
ll bud;
void DFS(int x){
	int big = -1;
	for(int v : adj[x]){
		DFS(v);

		sub[x] += sub[v];
		if(big == -1 || se[v].size() > se[big].size())
			big = v;
	}

	if(big != -1){
		swap(se[x], se[big]);
		for(int v : adj[x]){
			if(v == big)
				continue;

			for(ll j : se[v])
				se[x].insert(j);
		}
	}

	se[x].insert(c[x]);
	sub[x] += c[x];

	while(sub[x] > bud){
		auto it = (--se[x].end());
		sub[x] -= *it;
		se[x].erase(it);
	}

	ans = max(ans, leader[x] * (ll) se[x].size());
}


void solve(){
	ll n;
	cin >> n >> bud;
	for(int i =1;i<=n;i++){
		ll u;
		cin >> u;
		
			adj[u].pb(i);
		cin >> c[i] >> leader[i];
	}
	DFS(1);
	
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
