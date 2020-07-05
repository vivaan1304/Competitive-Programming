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
const ll N =(1e5+5); // TODO : change value as per problem
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
int MinimumNumIncreasingSubsequences(int arr[], int n) 
{ 
    multiset<int> last; 
  
    // last element in each  increasing subsequence  
    // found so far 
    for (int i = 0; i < n; i++) { 
  
        // here our current element is arr[i] 
        multiset<int>::iterator it = last.lower_bound(arr[i]); 
  
        // iterator to the first element larger  
        // than or equal to arr[i] 
        if (it == last.begin()) 
  
            // if all the elements in last larger 
            // than or to arr[i] then insert it into last 
            last.insert(arr[i]); 
  
        else { 
            it--; 
  
            // the largest element smaller than arr[i] is the number 
            // before *it which is it-- 
            last.erase(it); // erase the largest element smaller than arr[i] 
            last.insert(arr[i]); // and replace it with arr[i] 
        } 
    } 
    return last.size(); // our answer is the size of last 
} 
  

ll a[N];
void solve(){
    ll n;    
    cin >> n;
    for(int i =1;i<=n;i++) cin >> a[i-1];
    cout<<MinimumNumIncreasingSubsequences(a,n) << endl;

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
