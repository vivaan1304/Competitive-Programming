const int MOD = 1e9+7; // 998244353;
const ll base = 30;// base should be > |alphabet|
#define int ll
int add(int x,int y){
	int re = (x + y) % MOD;
	if(re < 0) re += MOD;
	re %= MOD;
	return re;
}
int mult(int x,int y){
	int re = (x * y) % MOD;
	if(re < 0) re += MOD;
	re %= MOD;
	return re;
}
const int N = 2e6+5;
long long binpow(long long a, long long b) {
    a %= MOD;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = mult(res,a);
        a = mult(a,a);
        b >>= 1;
    }
    return res;
}
string s; // 1- based string indexing
int H[N];
int p[N];
int inv[N];
int n;
void init(){
	p[0] = 1;
	FOR(i,1,N){
		p[i] = mult(p[i-1],base);
	}
	int pw_inv = binpow(base,MOD-2);
	inv[0] = 1;
	FOR(i,1,N){
		inv[i] = mult(inv[i-1],pw_inv);
	}
}

void compute_hash(){
	H[1] = mult((s[1]-'A')+1,p[0]);
	FOR(i,2,n+1){
		H[i] = add(H[i-1],mult((s[i]-'A')+1,p[i-1]));
	} 
}
int get_hash(int i,int j){
	if(i == 1) return H[j];
	int gg = add(H[j],-H[i-1]);
	gg = mult(gg,inv[i-1]);
	return gg;
}
