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

 
const ll INF = 1e18;
const ll N =(1e3+5); // TODO : change value as per problem
const ll MOD = 1e9+7;
/*
red - cant pass
pink - normal
orange - smell like oranges
blue - only pass through if smell like oranges
purple - slide in the direction until hits a non-purple tile

keep track of (x,y,dir,smell,purple)

*/

struct st{
	int dis;
	int x;
	int y;
	bool orange;
};
auto comp = [](st A,st B) {return A.dis < B.dis;};	
priority_queue<st,vector<st>,decltype(comp)> q(comp);

st d[N][N];
int a[N][N];
int n,m;
int dx[4]={0,1,-1,0};
int dy[4]={1,0,0,-1};
bool k(int i,int j){
	if(i >= 1 && i <= n && j >= 1 && j <= m) return true;
	return false;
}
void solve(){
	cin >> n >> m;
	for(int i =1;i<=n;i++){
		for(int j =1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	for(int i =1;i<=n;i++){
		for(int j =1;j<=m;j++){
			d[i][j].dis=INF;
			d[i][j].orange = false;
			d[i][j].x = i;
			d[i][j].y = j;
		}
	}
	d[1][1].dis = 0;
	q.push(d[1][1]);
	/*
red - cant pass
pink - normal
orange - smell like oranges
blue - only pass through if smell like oranges
purple - slide in the direction until hits a non-purple tile

keep track of (x,y,dir,smell,purple)

*/

	while(!q.empty()){
		st p = q.top();
		q.pop();
		cout<<p.x<<" "<<p.y<<endl;
		
		if(a[p.x][p.y] == 0 || (a[p.x][p.y] == 3 && p.orange == false)) continue;
		// cout<<"---\n---\n"
		bool f = p.orange;

		for(int l =0;l<4;l++){
			int j =l;
			if(dx[l]!=0&&dy[j]!=0)continue;
			int nx = p.x + dx[l];
			int ny = p.y + dy[j];
			if(!k(nx,ny)) continue;
			if(f){
				if(a[nx][ny] == 4){
					if(ny > p.y){
						int steps = 0;
						for(int i = p.y+1;i<=m;i++){
							if(a[p.x][i] != 4) {
								steps = i;
								break;
							}
						}		
						if(steps == 0) continue;
						if(d[p.x][steps].dis > d[p.x][p.y].dis + abs(steps - p.y)){
							d[p.x][steps].dis = d[p.x][p.y].dis + abs(steps - p.y);
							d[p.x][steps].orange = false;
							q.push(d[p.x][steps]);
						}	
					}
					else if(ny < p.y) {
						int steps = 0;
						for(int i = p.y-1;i>=1;i--){
							if(a[p.x][i] != 4) {
								steps = i;
								break;
							}
						}		
						if(steps == 0) continue;
						if(d[p.x][steps].dis > d[p.x][p.y].dis + abs(steps - p.y)){
							d[p.x][steps].dis = d[p.x][p.y].dis + abs(steps - p.y);
							d[p.x][steps].orange = false;
							q.push(d[p.x][steps]);
						}
					}
					else if(nx > p.x){
						int steps = 0;
						for(int i = p.x+1;i<=n;i++){
							if(a[i][p.y] != 4) {
								steps = i;
								break;
							}
						}		
						if(steps == 0) continue;
						if(d[steps][p.y].dis > d[p.x][p.y].dis + abs(steps - p.x)){
							d[steps][p.y].dis = d[p.x][p.y].dis + abs(steps - p.x);
							d[steps][p.y].orange = false;
							q.push(d[steps][p.y]);
						}
					}
					else{
						int steps = 0;
						for(int i = p.x-1;i>=1;i--){
							if(a[i][p.y] != 4) {
								steps = i;
								break;
							}
						}		
						if(steps == 0) continue;
						if(d[steps][p.y].dis > d[p.x][p.y].dis + abs(steps - p.x)){
							d[steps][p.y].dis = d[p.x][p.y].dis + abs(steps - p.x);
							d[steps][p.y].orange = false;
							q.push(d[steps][p.y]);
						}
					}
				}
				else if(d[nx][ny].dis > d[p.x][p.y].dis + 1){
					d[nx][ny].dis = d[p.x][p.y].dis + 1;
					d[nx][ny].orange = true;
					q.push(d[nx][ny]);
				}
			}
			else{
				if(a[nx][ny] == 4){
					if(ny > p.y){
						int steps = 0;
						for(int i = p.y+1;i<=m;i++){
							if(a[p.x][i] != 4) {
								steps = i;
								break;
							}
						}		
						if(steps == 0) continue;
						if(d[p.x][steps].dis > d[p.x][p.y].dis + abs(steps - p.y)){
							d[p.x][steps].dis = d[p.x][p.y].dis + abs(steps - p.y);
							d[p.x][steps].orange = false;
							q.push(d[p.x][steps]);
						}	
					}
					else if(ny < p.y) {
						int steps = 0;
						for(int i = p.y-1;i>=1;i--){
							if(a[p.x][i] != 4) {
								steps = i;
								break;
							}
						}		
						if(steps == 0) continue;
						if(d[p.x][steps].dis > d[p.x][p.y].dis + abs(steps - p.y)){
							d[p.x][steps].dis = d[p.x][p.y].dis + abs(steps - p.y);
							d[p.x][steps].orange = false;
							q.push(d[p.x][steps]);
						}
					}
					else if(nx > p.x){
						int steps = 0;
						for(int i = p.x+1;i<=n;i++){
							if(a[i][p.y] != 4) {
								steps = i;
								break;
							}
						}		
						if(steps == 0) continue;
						if(d[steps][p.y].dis > d[p.x][p.y].dis + abs(steps - p.x)){
							d[steps][p.y].dis = d[p.x][p.y].dis + abs(steps - p.x);
							d[steps][p.y].orange = false;
							q.push(d[steps][p.y]);
						}
					}
					else{
						int steps = 0;
						for(int i = p.x-1;i>=1;i--){
							if(a[i][p.y] != 4) {
								steps = i;
								break;
							}
						}		
						if(steps == 0) continue;
						if(d[steps][p.y].dis > d[p.x][p.y].dis + abs(steps - p.x)){
							d[steps][p.y].dis = d[p.x][p.y].dis + abs(steps - p.x);
							d[steps][p.y].orange = false;
							q.push(d[steps][p.y]);
						}
					}
				}
				else if(d[nx][ny].dis > d[p.x][p.y].dis + 1){
					d[nx][ny].dis = d[p.x][p.y].dis + 1;
					if(a[nx][ny] == 2)
						d[nx][ny].orange = true;
					q.push(d[nx][ny]);
				}
			}
		}
	
	}
	if(d[n][m].dis == INF) d[n][m].dis = -1;
	cout << d[n][m].dis << endl;
	// int A = n,B = m;
	// while(A != -1){
	// 	cout<<A << " " << B << endl;
	// 	pll lol = par[A][B];
	// 	A = lol.f;
	// 	B = lol.s;
	// }
}
signed main(){
 
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
     // freopen("dream.in","r",stdin);freopen("dream.out","w",stdout);
    
     ll tt=1;   
     // cin >> tt;
    while(tt--){    
        solve();
    }    
}
