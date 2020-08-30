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
const ll N =(500+5); // TODO : change value as per problem
const ll MOD = 1e9+7;

int n,m,t;
int a[N][N];
pll par[N][N];
int sz[N][N];
vector<pll> lessgo[N][N];
int val[N][N];
bool good[N][N];
int cur;
void make_set(int i,int j){
	par[i][j] = {i,j};
	lessgo[i][j].pb({i,j});
	sz[i][j] = 1;
}
pair<int,int> find_par(int i,int j){
	if(par[i][j] == mp(i,j))
		return {i,j};
	return par[i][j] = find_par(par[i][j].f,par[i][j].s);
}
void onion(int i,int j,int x,int y){
	pair<int,int> A = find_par(i,j),B = find_par(x,y);
	if(A == B) return ;
	if(lessgo[A.f][A.s].size() > lessgo[B.f][B.s].size()) swap(A,B);
	if(sz[B.f][B.s] + sz[A.f][A.s] >= t){
		if(sz[A.f][A.s] < t)
			for(auto ii:lessgo[A.f][A.s])
				if(val[ii.f][ii.s] == 0)
				val[ii.f][ii.s] = cur;
		if(sz[B.f][B.s] < t)
			for(auto ii:lessgo[B.f][B.s])

				if(val[ii.f][ii.s] == 0) 
				val[ii.f][ii.s] = cur;
	}
	sz[B.f][B.s] += sz[A.f][A.s];
	for(auto ii:lessgo[A.f][A.s]) lessgo[B.f][B.s].pb(ii);
	par[A.f][A.s] = B;
}

struct gg{
	pll from;
	pll to;
	int wt;
};
bool cmp(gg A,gg B){
	return (A.wt < B.wt);
}
vector<gg> vec;
void solve(){
	cin >> n >> m >> t;
	for(int i =1;i <= n;i++){
		for(int j = 1;j<=m;j++){
			cin >> a[i][j];
		}
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			if(j != m){
				gg x;
				x.from.f = i;
				x.from.s = j;
				x.to.f = i;
				x.to.s =j+1;
				x.wt = abs(a[i][j] - a[i][j+1]);
				vec.pb(x);
			}
			if(i != n){
				gg x;
				x.from.f = i;
				x.from.s = j;
				x.to.f = i+1;	
				x.to.s =j;
				x.wt = abs(a[i][j] - a[i+1][j]);
				vec.pb(x);
			}
		}
	}
	sort(vec.begin(),vec.end(),cmp);

	for(int i = 1;i<=n;i++){
		for(int j =1;j<=m;j++){
			int ch;
			cin >> ch;
			if(ch) 	good[i][j] = true;	
			make_set(i,j);
		}
	}
	int ans= 0;
	for(int i = 0;i<vec.size();i++){
		int j = i;
		cur = vec[i].wt;
		onion(vec[j].from.f,vec[j].from.s,vec[j].to.f,vec[j].to.s);		
	}
	for(int i =1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			if(good[i][j]){
				ans += val[i][j];
			}
		}
	}
	
	
	cout << ans << endl;
}
signed main(){
 
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
     freopen("skilevel.in","r",stdin);freopen("skilevel.out","w",stdout);
    
     ll tt=1;   
     // cin >> tt;
    while(tt--){    
        solve();
    }    
}
