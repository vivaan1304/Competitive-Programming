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
pair<int,int> a[N];
int t[4*N];
int t2[4*N];

int n,q;

int dis(int i,int j){
	return abs(a[i].f - a[j].f) + abs(a[i].s - a[j].s);
}
void build(int v,int l,int r){
	if(l == r){
		if(l < n) t[v] = dis(l,l+1);
		else t[v] = 0;
	}
	else{
		int m = (l+r)>>1ll;
		build(v*2,l,m);
		build(v*2+1,m+1,r);
		t[v] = t[v*2] + t[v*2+1];
	}
}
void build2(int v,int l,int r){
	if(l == r){
		if((l+2) <= n) t2[v] = dis(l,l+1) + dis(l+1,l+2) - dis(l,l+2);
		else t2[v] = 0;
	}
	else{
		int m = (l + r)>>1ll;
		build2(v*2,l,m);
		build2(v*2+1,m+1,r);
		t2[v] = max(t2[v*2] , t2[v*2+1]);
	}
}
void upd(int v,int l,int r,int idx){
	if(l == r){
		if(l < n) t[v] = dis(l,l+1);
		else t[v] = 0;
	}
	else{
		int m = (l+r)>>1ll;
		if(idx <= m)
			upd(v*2,l,m,idx);
		else upd(v*2+1,m+1,r,idx);
		t[v] = t[v*2] + t[v*2+1];
	}
}
void upd2(int v,int l,int r,int idx){
	if(l == r){
		if((l+2) <= n) t2[v] = dis(l,l+1) + dis(l+1,l+2) - dis(l,l+2);
		else t2[v] = 0;
	}
	else{
		int m = (l+r)>>1ll;
		if(idx <= m)
			upd2(v*2,l,m,idx);
		else upd2(v*2+1,m+1,r,idx);
		t2[v] = max(t2[v*2] ,t2[v*2+1]);
	}
}
int query(int v,int l,int r,int st,int en){
	if(l > en || r < st) return 0;
	if(l >= st && r <= en){
		return t[v];
	}
	int m = (l+r)>>1ll;
	return query(v*2,l,m,st,en) + query(v*2+1,m+1,r,st,en);
}

int query2(int v,int l,int r,int st,int en){
	if(l > en || r < st) return 0;
	if(l >= st && r <= en){
		return t2[v];
	}
	int m = (l+r)>>1ll;
	return max(query2(v*2,l,m,st,en) , query2(v*2+1,m+1,r,st,en));
}
void solve(){
	cin >> n >> q;
	for(int i = 1;i <= n;i++){
		cin >> a[i].f >> a[i].s;
	}

	build(1,1,n);
	build2(1,1,n);
	while(q--){
		char ch;
		cin >> ch;
		if(ch == 'Q'){
			int l,r;
			cin >> l >> r;
			int d = query(1,1,n,l,r-1);
			d -= query2(1,1,n,l,r-2);
			cout << d << endl;
		}
		else{
			int idx,x,y;
			cin >> idx >> x >> y;
			a[idx] = mp(x,y);
			for(int i = max(1ll,idx-1);i<=idx;i++){
				upd(1,1,n,i);
			}
			for(int i = max(1ll,idx-2);i<=idx;i++){
				upd2(1,1,n,i);
			}
		}
	}	

}
signed main(){
 
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
     freopen("marathon.in","r",stdin);freopen("marathon.out","w",stdout);
    
     ll tt=1;   
     // cin >> tt;
    while(tt--){    
        solve();
    }    
}
