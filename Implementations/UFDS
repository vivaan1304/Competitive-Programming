#define int ll
const ll N = 1e3+5;
struct dsu{
	int sz[N];
	int par[N];
	int c;
	void init(int n){
		FOR(i,1,n+1){
			sz[i]=1;
			par[i]=i;
		}
		c=n;
	}
	int find_par(int u){
		if(u==par[u])return u;
		return par[u]=find_par(par[u]);
	}
	void unite(int u,int v){
		u = find_par(u),v= find_par(v);
		if(u == v)return;
		if(sz[u]>sz[v])swap(u,v);
		sz[v]+=sz[u];
		par[u] =v;
		sz[u]=0;
		c--;
	}
};
