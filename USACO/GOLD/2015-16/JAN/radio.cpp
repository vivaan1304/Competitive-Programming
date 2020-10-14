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

int dp[1005][1005];
pll pre[1005][2];
int dis(int a,int b,int c,int d){
	int x = (a-c)*(a-c);
	int y = (b-d)*(b-d);
	x+=y;
	return x;
	// a= abs(a-c);
	// a*=a;
	// b = abs(b-d);
	// b*=b;
	// return a+b;
}
void solve(){
	int n,m;
	cin>>n>>m;
	int fx,fy;
	cin>>fx>>fy;
	int bx,by;
	cin>>bx>>by;
	string s,t;
	cin>>s>>t;
	s = '$'	+ s;
	t = '$' + t;
	pre[0][0]=mp(fx,fy);
	for(int i =1;i<=n;i++){
		int g=0,g2=0;
		if(s[i] == 'N') g=1;
		else if(s[i]=='S')g=-1;
		else if(s[i]=='E')g2= 1;
		else if(s[i]=='W') g2 = -1;
		pre[i][0].f = pre[i-1][0].f + g2;
		pre[i][0].s = pre[i-1][0].s + g;
	}
	pre[0][1]=mp(bx,by);

	for(int i =1;i<=m;i++){
		int g=0,g2=0;
		if(t[i] == 'N') g=1;
		else if(t[i]=='S')g=-1;
		else if(t[i]=='E')g2= 1;
		else if(t[i]=='W') g2 = -1;
		pre[i][1].f = pre[i-1][1].f + g2;
		pre[i][1].s = pre[i-1][1].s + g;
	}

	// for(int i =0;i<=m;i++){
	// 	cout<<pre[i][1].f<<" "<<pre[i][1].s<<endl;
	// }

	// dp[0][0] = d(fx,fy,bx,by);
	// dp[0][0]=INF;
	for(int i = 0;i<=n;i++){
		for(int j =0;j<=m;j++){
			if(i==0&&j==0)continue;
			int D = dis(pre[i][0].f,pre[i][0].s,pre[j][1].f,pre[j][1].s);
			// cout<<D<<endl;
			if(i==0){
				dp[i][j] = dp[i][j-1] + D;
			}
			else if(j == 0){
				dp[i][j] = dp[i-1][j] + D;
			}
			else{
				dp[i][j]=INF;
				dp[i][j] = min(dp[i][j],dp[i-1][j] + D);
				// dp[i][j] = min(min(dp[i-1][j-1],dp[i-1][j]),dp[i][j-1]) + D;
				dp[i][j]=min(dp[i][j],dp[i][j-1]+D);
				dp[i][j]=min(dp[i][j],dp[i-1][j-1]+D);
			}
		}
	}
	cout<<dp[n][m]<<endl;
	// cout<<dp[n][m]-dis(pre[n][0].f,pre[n][0].s,pre[m][1].f,pre[m][1].s)<<endl;
	// for(int i =0;i<=n;i++){
	// 	for(int j =0;j<=m;j++){
	// 		cout<<dp[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
}
signed main(){
 
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
     freopen("radio.in","r",stdin);freopen("radio.out","w",stdout);
    
     ll tt=1;   
     // cin >> tt;
    while(tt--){    
        solve();
    }    
}
