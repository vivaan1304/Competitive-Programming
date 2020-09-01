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
const ll N =(1e5+5); // TODO : change value as per problem
const ll MOD = 1e9+7;
vector<int> adj[N],rev[N],cond[N],cond2[N];
bool vis[N];
stack<int> st;
int comp;
int col[N];
pair<int,int> ed[N];
int sz[N];
int ans[N],ans2[N]; // ans[u] = maximum value we can obtain on the path from ans[u]
void dfs(int u){
	vis[u] = true;
	for(auto v:adj[u]){
		if(vis[v] == false){
			dfs(v);
		}
	}
	st.push(u);
}
void dfs2(int u){
	vis[u] = true;
	col[u] = comp;
	sz[comp]++;
	for(auto v:rev[u]){
		if(vis[v] == false)
			dfs2(v);
	}
}

void dfs3(int u){
	vis[u] = true;
	for(auto v:cond[u]){
		if(vis[v] == false){
			dfs3(v);
		}
	}
	st.push(u);
}

void dfs4(int u){
	vis[u] = true;
	for(auto v:cond2[u]){
		if(vis[v] == false){
			dfs4(v);
		}
	}
	st.push(u);
}
void solve(){
	int n,m;
	cin >> n >> m;	
	for(int i = 1;i<=m;i++){
		int u,v;
		cin >> u >> v;
		adj[u].pb(v);
		rev[v].pb(u);
		ed[i] = {u,v};
	}
	for(int i = 1;i<=n;i++){
		if(vis[i] == false)
			dfs(i);
	}
	for(int i =1;i<=n;i++) vis[i] = false;
	while(!st.empty()){
		int u = st.top();
		st.pop();
		if(vis[u] == true) continue;
		comp++;
		dfs2(u);
	}
	vector<pll> vec;
	for(int i = 1;i<=m;i++){
		int u = ed[i].f, v = ed[i].s;
		if(col[u] != col[v]){
			cond[col[u]].pb(col[v]);
			cond2[col[v]].pb(col[u]);
			vec.pb({col[u],col[v]});
		}
	}
	for(int i =1;i<=comp;i++) ans[i] = -1,ans2[i]=-1;
	for(int i= 1;i<=comp;i++) vis[i] = false;
	int src = col[1];
	dfs3(src);
	bool ok = false;
	if(st.top() == src){
		ok = true;
		ans[src] = sz[src];
	}
	st.pop();
	while(!st.empty()){
		if(!ok) continue;
		int u = st.top();
		st.pop();
		if(u == src) ok = true;
		for(auto v:cond2[u]){
			if(ans[v] != -1)
			ans[u] = max(ans[u],ans[v] + sz[u]);
		}
	}
	for(int i= 1;i<=comp;i++) vis[i] = false;
	dfs4(src);
	
	ok = false;
	if(st.top() == src){
		ok = true;
		ans2[src] = sz[src];
	}
	st.pop();
	while(!st.empty()){
		if(!ok) continue;
		int u = st.top();
		st.pop();
		if(u == src) ok = true;
		for(auto v:cond[u]){
			if(ans2[v] != -1)
			ans2[u] = max(ans2[u],ans2[v] + sz[u]);
		}
	}
	int go = 0;
	for(auto p:vec){
		int u = p.f;
		int v = p.s;
		if(ans2[u] != -1 && ans[v] != -1)
			go = max(go,ans[v] + ans2[u] - sz[src]);
	}
	for(int i = 1;i<=comp;i++){
		if(ans[i] != -1 && ans2[i] != -1)
			go = max(go,ans[i] + ans2[i] - sz[i] - sz[src]);
	}
	
	cout << go << endl;

}
signed main(){
 
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
     freopen("grass.in","r",stdin);freopen("grass.out","w",stdout);
    
     ll tt=1;   
     // cin >> tt;
    while(tt--){    
        solve();
    }    
}
