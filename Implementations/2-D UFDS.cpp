struct ufds{
	int siz[N][N];
	pl p[N][N];
	void init(int n,int m){
		FOR(i,1,n+1){
			FOR(j,1,m+1){
				p[i][j] = {i,j};
				siz[i][j] = 1;
			}
		}
	}
	pl find_par(int u,int v){
		if(p[u][v] == mp(u,v))
			return {u,v};
		return p[u][v] = find_par(p[u][v].f,p[u][v].s);
	}
	void unite(pl u,pl v){
		u = find_par(u.f,u.s),v = find_par(v.f,v.s);
		if(u == v) return;
		if(siz[u.f][u.s]>siz[v.f][v.s]) swap(u,v);
		siz[v.f][v.s] += siz[u.f][u.s];
		siz[u.f][u.s] = 0;
		p[u.f][u.s] = v;
	}
	int find_sz(int u,int v){
		pl p = find_par(u,v);
		return siz[p.f][p.s];
	}
};
