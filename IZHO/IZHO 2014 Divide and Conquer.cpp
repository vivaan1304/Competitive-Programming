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
const ll N =(1e5+5); // TODO : change value as per problem
const ll MOD = 1e9+7;

struct nice
{   
    ll x;
    ll g;
    ll e;
};
nice a[N];
ll gold[N];
ll energy[N];
pll diff[N];
ll pos[N];
bool cmp(nice b, nice c){
    return (b.x < c.x);
}
bool cmp2(pll gg,pll gg2){
    return gg.s < gg2.s;
}
ll t[4*N];
void build(ll node,ll l,ll r){
    if(l == r){
        t[node] = diff[l].f;
    }
    else{
        ll m = (l+r)>>1ll;
        build(node*2,l,m);
        build(node*2+1,m+1,r);
        t[node] = max(t[node*2],t[node*2+1]);
    }
}
ll query(ll node,ll l,ll r,ll st,ll en){
    if(l > en || r < st){
        return 0;
    }
    if(l >= st && r <= en){
        return t[node];
    }
    ll m = (l+r)>>1ll;
    ll p1 = query(node*2,l,m,st,en);
    ll p2 = query(node*2+1,m+1,r,st,en);
    return max(p1,p2);
}

void solve(){
    ll n;
    cin >> n;

    for(int i =1;i<=n;i++){
        cin >> a[i].x >> a[i].g >> a[i].e;
        
    }
    sort(a+1,a+n+1,cmp);
    for(int i =1;i<=n;i++){
        gold[i] = gold[i-1] + a[i].g;
        energy[i] = energy[i-1] + a[i].e;
    }
    for(int i =1;i<=n;i++) diff[i] =mp(i, energy[i] - a[i].x);
    sort(diff+1,diff+n+1,cmp2);
    
    build(1,1,n);
    ll ans = 0;
    for(ll l = 1;l<=n;l++){
        ll tote = energy[l-1] - a[l].x;
        ll lo = 1,hi = n;
        ll gg = INF;
        while(hi>=lo){
            ll m = (lo+hi)>>1ll;
            if(diff[m].s >= tote){
                gg = min(gg,m);
                hi = m-1;
            }
            else lo = m+1;
        }
        if(gg == INF) continue;
        ll idx = query(1,1,n,gg,n);
        if(idx != 0) ans = max(ans,gold[idx]-gold[l-1]);
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
/*
Pick a Range [L,R] such that :
	a) The sum of energy levels in the range >= R-L+1
	b) Sum of Gold is maximal Possible 


	
*/
