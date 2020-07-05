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
const ll p = 1000003;
long long compute_hash(vll v){
    ll ans = 0;
    ll p_pow = 1;
    for(int i =0;i<5;i++){
        ans = (ans + v[i] * p_pow) % MOD;
        p_pow = (p_pow * p)%MOD;
    }
    return ans;
}
void solve(){
    ll a,b;
    cin >> a >> b;
    if(a<=0 && b >=0) {
        cout << "Zero"<< endl;
        return;
    }
    if(a < 0){
        if((b-a+1) & 1) cout << "Negative\n";
        else cout << "Positive\n";
        return;
    }
    else if(a > 0){
        cout << "Positive\n";
    }
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
