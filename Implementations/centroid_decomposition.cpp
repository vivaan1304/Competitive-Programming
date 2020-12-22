#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pl = pair<ll,ll>;
using vl = vector<ll>; 
#define mp make_pair
#define f first
#define s second
 
// vectors
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define ins insert 
#define pf push_front 
#define pb push_back
 
// loops
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)
 
const int MOD = 1e9+7; // 998244353;
const ll INF = 1e18; // not too close to LLONG_MAX

#define int ll
const int xd[4] = {1,0,-1,0}, yd[4] = {0,1,0,-1}; // for every grid problem!!
const int N = 1e6+5;
const int LOGN = 25;

int n;
vector<pl> g[N];
int par[N];// parent in centroid tree
int dist[N]; // distance in centroid tree
int sub[N];
int d[LOGN][N]; // neat trick 
// d[i][j] : represents the distance between and i and j when i is the centroid
// but what i am doing is utilising this strategy that for all the centroids on level c all other nodes would be in a subtree of <= 1 of those nodes so basically for every node we can figure out which is that node which is at that level so
// d[lvl][i] : represents the distance between the centroid at depth = lvl such that i is in the subtree of that centroid
bool deleted[N];
int current_tree = 0;
int LCA(int u,int v){
	// finds LCA in of u and v in the centroid tree
	while(u != v){
		if(dist[u] < dist[v])
			v = par[v]; // get v a level up
		else
			u = par[u]; // get u a level up
	}
	return u;
}
void find_subtree(int u,int p){
	sub[u] = 1;
	current_tree ++;
	trav(P,g[u]){
		int v = P.f;
		if(deleted[v] == 0 && v != p){
			find_subtree(v,u);
			sub[u] += sub[v];
		}
	}
}
int find_centroid(int u,int p){
	trav(P,g[u]){
		int v = P.f;
		int w = P.s;
		if(deleted[v] == 0 && v != p && sub[v] > (current_tree / 2)) 
			return find_centroid(v,u);
	}
	return u;
}
void dfs(int u,int p,int lvl,int dd){
	d[lvl][u] = dd;
	trav(P,g[u]){
		int v = P.f;
		int w = P.s;
		if(deleted[v] == 0 && v != p){
			dfs(v,u,lvl,dd+w);
		}
	}
}

void decompose(int root,int p){
	current_tree = 0; // number of nodes in the current tree
	find_subtree(root,p); // find subtree sizes
	int cen = find_centroid(root,p); // find centroid
	if(p != -1){
		par[cen] = p;
		dist[cen] = dist[p] + 1;
	}
	else dist[cen] = 0;
	dfs(cen,0,dist[cen],0);
	// decompose the rest of centroid tree now
	deleted[cen] = 1;
	trav(P,g[cen]){
		int v = P.f;
		if(deleted[v] == 1) continue;
		decompose(v,cen);
	}
}

void solve(){
	cin >> n;
	FOR(i,2,n+1){
		int u,v,w;
		cin >> u >> v >> w;u++,v++;
		g[u].pb(mp(v,w));
		g[v].pb(mp(u,w));
	}
	// now answer for a query between u and v is nothing but d[dist[lca(u,v)]][u] + d[dist[lca(u,v)]][v]
	decompose(1,-1);

	int Q;
	cin >> Q;
	while(Q--){
		int u,v;
		cin >> u >> v;	u++,v++;
		int lc = dist[LCA(u,v)];
		cout << d[lc][u] + d[lc][v] << endl;
		// cout << LCA(u,v) << endl;
	}
}	
signed main() {
	cin.tie(0)->sync_with_stdio(0);

	// you should actually read the stuff at the bottom
	int t=1;
	// cin >> t;
	while(t--){
		solve();
	}
}
/* stuff you should look for
	* read the probem 3 more times in case of WA :)
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/
