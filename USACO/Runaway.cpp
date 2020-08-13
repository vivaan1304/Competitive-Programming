		#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
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

 
const ll INF = 1e12;
const ll N =(2e5+5); // TODO : change value as per problem
const ll MOD = 1e9+7;
const ll LOG = 20;
int n,l;
int up[N][LOG];
int sum[N][LOG];
vector<pair<int,int>> adj[N];
int st[N];
int en[N];
int par[N];
int bit[N];
int t=0;
void dfs(int u,int p){
	st[u] = ++t;
	par[u] = p;
	for(auto pp:adj[u]){
		if(pp.f == p) continue;
		dfs(pp.f,u);
	}
	en[u] = ++t;
}
bool is_ancestor(int u, int v)
{
    return st[u] <= st[v] && en[u] >= en[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}
void dfs2(ll u,ll p){
    for(auto v:adj[u]){
        if(v.f != p){
            dfs2(v.f,u);
            bit[u]+=bit[v.f];
        }
    }
}


void solve(){
	cin >> n >> l;
	for(int i = 2;i <= n;i++){
		int u,c;
		cin >> u >> c;
		adj[u].pb({i,c});
		up[i][0] = u;
		sum[i][0] = c;
	}
	for(int i =1;i <= n;i++){
		for(int j= 1;j<LOG;j++){
			up[i][j] = up[up[i][j-1]][j-1];
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j =1;j < LOG;j++){
			if(up[i][j] == 0) continue;
			sum[i][j] = sum[up[i][j-1]][j-1] + sum[i][j-1];
		}
	}
	vector<pair<int,int>> event;
	for(int i =1;i <= n;i++){
		int u = i;
		int tmp = l;
		for(int j = LOG-1;j>=0&&tmp;j--){
			if(up[u][j] != 0 && tmp >= sum[u][j]){
				tmp -= sum[u][j];
				u = up[u][j];
			}
		}
		event.pb({u,i});
	}
	dfs(1,0);
	for(auto p:event){
		int u = p.f,v = p.s;
		bit[u]++;
		bit[v]++;
		int x =lca(u,v);
		bit[x]--;
		bit[par[x]]--;
	}
	dfs2(1,0);
	for(int i =1;i<=n;i++){
		cout << bit[i] << endl;
	}
	

}
signed main(){
 
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
     freopen("runaway.in","r",stdin);freopen("runaway.out","w",stdout);
    
     ll tt=1;   
     // cin >> tt;
    while(tt--){    
        solve();
    }    
}
