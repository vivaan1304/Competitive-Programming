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
const ll N =(22); // TODO : change value as per problem
const ll MOD = 1e9+7;

int n,X;
int dp[(1ll<<N)];
int cost[N][1005];
int a[N][1005];
int K[N];
int dur[N];

void solve(){
	cin >> n >> X;
	for(int i = 1;i<=n;i++){
		cin >> dur[i];
		int k;
		cin >> k;
		K[i] = k;
		for(int j = 1;j<=k;j++) cin >> a[i][j];
	}
	
	// calculate dp
	for(int i = 1;i<(1ll<<n);i++) dp[i] = -1;
	for(int mask = 1;mask<(1ll<<n);mask++){
		for(int i = 0;i<n;i++){
			if(mask&(1ll<<i)){
				int pmask = mask^(1ll<<i);
				// find first show which we can watch 
				if(dp[pmask] == -1) continue;
				int ok = -1,l = 1,r = K[i+1];
				while(l <= r){
					int m = (l+r)/2;
					if(a[i+1][m] <= dp[pmask]){
						ok = max(ok,m);
						l = m+1;
					}
					else r=  m-1;
				}
				if(ok!=-1 && (a[i+1][ok]+dur[i+1]) >= dp[pmask])
					dp[mask] = max(dp[mask],a[i+1][ok]+dur[i+1]);
			}
		}
	}
	// cout << dp[8] << endl;

	int ans = INF;
	for(int mask = 1;mask < (1ll<<n);mask++){
		if(dp[mask] >= X){
			ans = min(ans,(int)__builtin_popcount(mask));
		}
	}
	if(ans == INF) ans = -1;
	cout << ans << endl;
}
signed main(){
 
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
     freopen("movie.in","r",stdin);freopen("movie.out","w",stdout);
    
     ll tt=1;   
     // cin >> tt;
    while(tt--){    
        solve();
    }    
}
