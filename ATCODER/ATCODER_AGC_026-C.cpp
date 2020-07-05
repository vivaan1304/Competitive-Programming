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
const ll N =(2e5+5); // TODO : change value as per problem
const ll MOD = 1e9+9;

void solve(){
    ll n;
    cin >> n;
    string s;
    cin >> s;
    map<pair<string,string>,ll> m1,m2;
    for(ll mask = 0;mask < (1ll<<n);mask++){
        string r,b;
        for(int i =0;i<n;i++){
            if(mask&(1ll<<i))
                r += s[i];
        }
        for(int j = n-1;j>=0;j--){
            if(!(mask&(1ll<<j)))
                b += s[j];
        }
        m1[mp(r,b)]++;
    }
    for(ll mask = 0;mask < (1ll<<n);mask++){
        string r,b;
        for(int i =0;i<n;i++){
            if(mask&(1ll<<i))
                r += s[i+n];
        }
        for(int j = n-1;j>=0;j--){
            if(!(mask&(1ll<<j)))
                b += s[j+n];
        }
        m2[mp(b,r)]++;
    }
    ll ans = 0;
    for(auto p:m1){
        ans += m2[p.f]*p.s;
    }
    cout << ans;
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
