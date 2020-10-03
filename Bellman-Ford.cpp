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

 
const ll INF = 1e15;
const ll N =(1e5+5); // TODO : change value as per problem
const ll MOD = 1e9+7;
int n,m;
vector<pair<pll,int>> ed;
int dis[N];
bool neg[N];
void bellman(){
	dis[1] = 0;
	for(int i =2;i<=n;i++){
		dis[i] = INF;
	}
	for(int i =2;i<=n;i++){	
		for(auto p:ed){
			int u = p.f.f;
			int v = p.f.s;
			int d = p.s;
			if(dis[v] > dis[u] + d){
				dis[v] = dis[u] + d;
			}
		}
	}
	for(auto p:ed){
		int u = p.f.f;
		int v = p.f.s;
		int d = p.s;
		if(dis[v] > dis[u] + d){
			neg[v] = true;
		}
		if(neg[u])
			neg[v]=1;
	}
	if(neg[1] || neg[n]){
		cout << "inf\n";
		return;
	}
	cout << -dis[n] << endl;
}

void solve(){
	cin >> n >> m;
	for(int i=1;i<=m;i++){
		int u,v;
		cin >> u >> v;
		int d;
		cin >> d;d*=-1;
		ed.pb(mp(mp(u,v),d));
	}
	bellman();
}
signed main(){
 
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
     // freopen(".in","r",stdin);freopen(".out","w",stdout);
    
     ll tt=1;   
     // cin >> tt;
    while(tt--){    
        solve();
    }    
}
