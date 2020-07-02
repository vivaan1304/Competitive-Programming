/* The main idea of the problem was quite simple which was that you can uniquely determine the entire sequence once you fix the first gondola. Checking for valid sequence and replacemnt is easy. For Counting the Replacement sequences notice that a gondola > n can be a replacement for any value < gondola value.*/
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
#include <gondola.h>
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
// #define int ll
#define sz(x) (ll)x.size()
#define all(x) (x.begin(),x.end())
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> os;
 
 
const ll INF = 1e18;
const ll N =(1e5+5); // TODO : change value as per problem
const ll MOD = 1e9+9;
    ll power(ll a, ll b)    //a is base, b is exponent
    {
        if(b==0)
            return 1;
        if(b==1)
            return a;
        if(b%2 == 1)
            return (power(a,b-1)*a)%MOD;
        ll q = power(a,b/2);
        return (q*q)%MOD;
    }

int valid(int n, int a[]){
    
    
    ll idx = 0;
    bool original = 0;
    for(int i =0;i<n;i++){
        if(a[i] <= n){
            idx =i;
            original = true;
            break;
        }   
   }
    if(original == false){
        set<ll> se;
        for(int i = 0;i<n;i++) se.in(a[i]);
        if(sz(se) == n){
            return 1;
        }
        else return 0;
    }
    int b[n];
    vector<int> ans;
    vector<pair<int,int>> gg;
    ll count = 1;
    ll nxt = a[idx];
    if(original == false) nxt = 1; 
    while(count <= n){
        
            b[idx] = nxt;
            nxt++;
            idx++;
            if(nxt > n) nxt = 1;
            if(idx >= n) idx = 0;
            count++;
        
    }
    set<ll> se;
    for(int i =0;i<n;i++){
        if(a[i] <= n && b[i] != a[i]){
            return 0;
        }
        else
            se.in(a[i]);
    }
    if(sz(se) != n) return 0;
    return 1;
}
int replacement(int n, int a[], int replacementSeq[]) {
    ll idx = 0;
    bool original = 0;
    for(int i =0;i<n;i++){
        if(a[i] <= n){
            idx =i;
            original = true;
            break;
        }
    }
 
    int b[n];
    vector<int> ans;
    vector<pair<int,int>> gg;
    ll count = 1;
    ll nxt = a[idx];
    if(original == false) nxt = 1; 
   
    while(count <= n){
        
            b[idx] = nxt;
            nxt++;
            idx++;
            if(nxt > n) nxt = 1;
            if(idx >= n) idx = 0;
            count++;
        
    }
    ll sp = n+1;
    for(int i =0;i<n;i++){
        if(a[i] > n)
            gg.pb({a[i],b[i]});
    }
    sort(gg.begin(),gg.end());
    for(int i = 0;i<sz(gg);i++){
        ans.pb(gg[i].s);
        ll x = sp;
        while(x != gg[i].f){
            ans.pb(x);
            x++;
        }
        sp = gg[i].f+1;
        
    }
    for(int i = 0;i<sz(ans);i++) replacementSeq[i] = ans[i];
    return sz(ans);

}
int countReplacement(int n, int inputSeq[]) {
    if(!valid(n,inputSeq)) return 0;
    ll special = 0;
    vll v;
    for(int i =0;i<n;i++){
        if(inputSeq[i] > n){
            special += 1;
            v.pb(inputSeq[i]);
        }
    }
    if(special == 0) return 1;
    ll ans = n;
    if(special != n) ans = 1;
    sort(v.begin(),v.end());
    ll maxi = n+1;
    ll r = sz(v);
    for(int i = 0;i<sz(v);i++){
      ans = (ans * power(r,v[i]-maxi))%MOD;
      r--;
      maxi = v[i]+1;
    }
    return ans;
}
