#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
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
#define int ll
#define sz(x) (ll)x.size()
#define all(x) (x.begin(),x.end())
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> os;
 
 
const ll INF = 1e12;
const ll N =(1e7+5); // TODO : change value as per problem
const ll MOD = 1e9+7;
ll a[N];
ll b[N];
ll pre[N];
ll suf[N];
pll v[N];
bool cmp(pll x,pll y){
	return ((x.f - x.s) > (y.f-y.s));
}

void solve(){
 	ll n,m,S;
 	cin >> n >> m >> S;
 	for(int i= 1;i<=n;i++){
 		cin >> a[i] >> b[i];
 		v[i].f = a[i];
 		v[i].s = b[i];
 	}
 	sort(v+1,v+n+1,cmp);
 	priority_queue<ll,vector<ll>,greater<ll>> pq;
 	ll sum = 0;
 	for(int i = 1;i<=m;i++){
 		pq.push(v[i].f);
 		sum += v[i].f;
 	}
 	pre[m] = sum;
 	for(int i= m+1;i<=n;i++){
 		ll add = v[i].f;
 		ll x = pq.top();
 		if(add > x){
 			sum -= x;
 			sum += add;
 			pq.pop();
 			pq.push(add);
 		}
 		pre[i] = sum;
 	}
 	while(!pq.empty())
 		pq.pop();
 	sum = 0;
 	ll dumb = -1;
 	for(int i = n,j =1;j<=S;j++,i--){
 		sum += v[i].s;
 		pq.push(v[i].s);
 		if(j == S){
 			suf[i] = sum;
 			dumb = i;
 		}
 	}
 	for(int i = dumb-1;i>=1;i--){
 		ll add = v[i].s;
 		ll x = pq.top();
 		if(add > x){
 			sum -= x;
 			sum += add;
 			pq.pop();
 			pq.push(add);
 		}
 		suf[i] = sum;
 	}
 	ll ans= 0;
 	for(int i =m;i<=n;i++){
 		if((n-i) >= S){
 			ans = max(ans,pre[i] + suf[i+1]);
 		}
 		else break;
 	}
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
