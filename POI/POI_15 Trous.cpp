/* 
    // check if subarray of size x exists s.t Sum-maxSum <= p
    // Sum = Sum of the subarray and Maxsum = maximum subarray sum of size d
*/
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
#include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
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
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> os;
 
 
const ll INF = 1e18;
const ll N =(2e6+5); // TODO : change value as per problem
const ll MOD = 1e9+7;
ll a[N];
ll sum[N];
ll n,p,d;
ll qry(ll l,ll r){
    return  sum[r]-sum[l-1];
}
bool check(ll x){
    bool ok = false;
    deque<ll> q;
    for(int i = 1;i<=x;i++){
        if((i+d-1) > x) break;
        ll new_element = qry(i,i+d-1);
        while(!q.empty() && q.back() < new_element)
            q.pop_back();
        q.pb(new_element);
    }
    if(qry(1,x) - q.front() <= p){
        return true;
    }
    for(int i =2;i<=n;i++){
        if((i + x-1) > n) break;
        ll r = i + x-1;
        ll l = r-d+1;
        ll remove_element = qry(i-1,i-1+d-1);
        if (!q.empty() && q.front() == remove_element)
            q.pop_front();
        ll new_element = qry(l,r);
        while(!q.empty() && q.back() < new_element)
            q.pop_back();
        q.pb(new_element);
        if(qry(i,i+x-1) - q.front() <= p) return true;
    }
    return false;

}
void solve(){
    cin >> n >> p >> d;
    for(int i = 1;i<=n;i++){
        cin >> a[i];
        sum[i] = sum[i-1];
        sum[i] += a[i];
    }
    ll ans;
    ll lo = d,hi = n;
    while(lo <= hi){
        ll m = (lo + hi)>>1ll;
        if(check(m)){
            ans = m;
            lo = m+1;
        }   
        else hi = m-1;
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
