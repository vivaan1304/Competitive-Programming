#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define vll vector<ll>
#define int ll
using namespace std;

const ll N = 1e5+5;
const ll MOD = 1e9+7;

int n, l;
vector<int> adj[N];
ll gg[N];
int timer;
vector<int> tin, tout;
vector<vector<int>> up;
vector<int> dis;
vector<int> par;
void dfs(int v, int p,int lvl)
{
    tin[v] = ++timer;
    up[v][0] = p;
    dis[v] = lvl;
    par[v] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v,lvl+1);
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
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

void preprocess(int root) {
    tin.resize(n+1);
    tout.resize(n+1);
    timer = 0;
    par.resize(n+1,-1);
    dis.resize(n+1);
    l = 30;
    up.assign(n+1, vector<int>(l + 1));
    dfs(root, root,0);
}
ll dist(ll a,ll b){
	return (dis[a] + dis[b] - 2LL*dis[lca(a,b)]);
}
bool cmp(ll a,ll b){
    return (dis[a] < dis[b]);
}
void dfs2(ll u,ll p){
    for(auto v:adj[u]){
        if(v != p){
            dfs2(v,u);
            gg[u]+=gg[v];
        }
    }
}
signed main()
{
    ifstream fin("maxflow.in");
    ofstream fout("maxflow.out");
	fin>>n;
    ll q;
    fin >> q;
	for(int i =2;i<=n;i++){
		ll u,v;
		fin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	preprocess(1);
    
    while(q--){
        ll u,v;
        fin>>u>>v;
        gg[u]++;
        gg[v]++;
        ll l = lca(u,v);
        gg[l]--;
        gg[par[l]]--;
    }
    dfs2(1,-1);
    ll ans = 0;
    for(int i = 1;i<=n;i++){
        ans = max(ans,gg[i]);
    }
    fout<<ans<<endl;
}