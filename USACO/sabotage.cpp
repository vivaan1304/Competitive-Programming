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
int n;
int a[N];


bool ok(long double x){
	vector<ld> suff(n+1);
	vector<ld> v(n+1);
	ld S2 = 0;
	for(int i = n;i>1;i--){
		ld k = (ld)(n-i+1);
		S2 += a[i];
		v[i] = x*k - S2;
	}
	// for(int i = n;i>=1;i--){
	// 	cout << fixed << v[i] << endl;
	// }
	suff[n] = v[n];
	for(int i= n-1;i>=1;i--){
		if(suff[i+1] > v[i]) suff[i] = suff[i+1];
		else suff[i] = v[i];
	}
	// for(int i = n;i>=1;i--){
	// 	cout << fixed << suff[i] << endl;
	// }
	ld S= 0 ;
	for(int i = 1;i<n-1;i++){
		S += a[i];
		ld k = (ld)i;
		ld gg = S - x*k;
		if(gg <= suff[i+2]){
			return true;
		}
	}
	

	return false;
}
void solve(){
	cin >> n;
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
	}
	int iter = 0;
	long double lo = 0.0,hi = 1e15;
	while(iter <= 100){
		long double mid = lo + (hi-lo)  / 2.0;
		if(ok(mid)) {
			hi = mid;
		}
		else lo = mid;
		iter++;
	}
	cout << fixed << setprecision(3) << lo << endl;
}
signed main(){
 
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
     freopen("sabotage.in","r",stdin);freopen("sabotage.out","w",stdout);
    
     ll tt=1;   
     // cin >> tt;
    while(tt--){    
        solve();
    }    
}
