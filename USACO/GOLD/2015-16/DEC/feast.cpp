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
const ll N =(5e6+5); // TODO : change value as per problem
const ll MOD = 1e9+7;

/*
3 operations :
x = max(x+a,T)
x = max(x+b,T)
x /= 2 (only once)

dp[i][0] is true if we can reach i fullness without drinking water
dp[i][0] |= dp[i-a][0]
dp[i][0] |= dp[i-b][0]

dp[i][1] |= dp[i-a][1]
dp[i][1] |= dp[i-b][1]
dp[i][1] |= dp[i*2][0]
dp[i][1] |= dp[i*2+1][0]
*/
bool dp[N][2];

void solve(){
	int t,a,b;
	cin >> t >> a >> b;
	dp[0][0]=true;
	for(int i =1;i<=t;i++){
		if(i>=a){
			dp[i][0] |= dp[i-a][0];
		}
		if(i >= b)
			dp[i][0] |= dp[i-b][0];
	}
	dp[0][1] = true;

	for(int i =1;i<=t;i++){
		if(i>=a){
			dp[i][1] |= dp[i-a][1];
		}
		if(i >= b)
			dp[i][1] |= dp[i-b][1];
		
		if((i*2) <= t)
			dp[i][1] |= dp[i*2][0];
		if((i*2) < t)	
			dp[i][1] |= dp[i*2+1][0];
	}

	int ans = 0;
	for(int i =1;i<=t;i++){
		bool g = dp[i][0] | dp[i][1];
		if(g)
			ans =max(ans,i);
	}
	cout << ans << endl;
}
signed main(){
 
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
     freopen("feast.in","r",stdin);freopen("feast.out","w",stdout);
    
     ll tt=1;   
     // cin >> tt;
    while(tt--){    
        solve();
    }    
}
