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

int a[20][20];
void solve(){
	int n,k;
	cin >> n >> k;
	for(int i= 1;i<=n;i++){
		for(int j= 1;j<=n;j++){
			cin >> a[i][j];
		}
	}
	int ans = INF;
	int maxi = 1ll<<(n-1);
	for(int msk = 0;msk < maxi;msk++){
		if(__builtin_popcount(msk) > k){
			continue;
		}
		set<int> v;
		for(int i = 0;i<n;i++){
			if(msk&(1ll<<i)){
				v.in(i+1);
			}
		}
		v.in(n);
		int vert = __builtin_popcount(msk) + 1;
		int cst[21][21];
		for(int i = 0;i<=20;i++){
			for(int j =0;j<=20;j++){
				cst[i][j]=0;
			}
		}
		for(int i =1;i<=n;i++){
			vector<int> co(vert+1,0);
			
			for(int j =i;j<=n;j++){
				int l = 0;
				for(int x = 1;x<=n;x++){
					co[l+1]+=a[j][x];
					if(v.count(x)){
						l++;
					}

				}
				cst[i][j]= 0;
				for(int x = 1;x<=vert;x++) {
					cst[i][j]=max(cst[i][j],co[x]);
				}
			}
		}
		int dp[21][50];
		for(int i =0;i<=20;i++){
			for(int j =0;j<50;j++){
				dp[i][j]=INF;
			}
		}		
		// dp[row][placed]
		for(int i =1;i<=n;i++){
			dp[i][0] =cst[1][i];
		}
		for(int i =1;i<=n;i++){
			for(int j = 1;j<i;j++){
				dp[i][j] = INF;
				for(int x = 1;x<i;x++){
					dp[i][j] = min(max(dp[x][j-1],cst[x+1][i]),dp[i][j]);
				}
			}
		}
		for(int i = (k-__builtin_popcount(msk));i<=(k-__builtin_popcount(msk));i++)
		ans = min(ans,dp[n][i]);
	}
	cout << ans << endl;

}
signed main(){
 
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
     freopen("partition.in","r",stdin);freopen("partition.out","w",stdout);
    
     ll tt=1;   
     // cin >> tt;
    while(tt--){    
        solve();
    }    
}
