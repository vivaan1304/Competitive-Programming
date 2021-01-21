const int N = 2e5+5;
const int MOD = 1e9+7; // 998244353;
const ll base = 30;// base should be > |alphabet|

const int MOD2 = 1e9+9; // 998244353;
const ll base2 = 31;// base should be > |alphabet|

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

int add2(int x,int y){
	int re = (x + y) % MOD2;
	if(re < 0) re += MOD2;
	re %= MOD2;
	return re;
}
int mult2(int x,int y){
	int re = (x * y) % MOD2;
	if(re < 0) re += MOD2;
	re %= MOD2;
	return re;
}

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

long long binpow2(long long a, long long b) {
    a %= MOD2;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = mult2(res,a);
        a = mult2(a,a);
        b >>= 1;
    }
    return res;
}

string t,s; // 1- based string indexing
int H[N],H2[N];
int pre[N][30];
int p[N],p2[N];
int inv[N],inv2[N];
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
	H[1] = mult((s[1]-'a')+1,p[0]);
	FOR(i,2,n+1){
		H[i] = add(H[i-1],mult((s[i]-'a')+1,p[i-1]));
	} 
}
int get_hash(int i,int j){
	if(i == 1) return H[j];
	int gg = add(H[j],-H[i-1]);
	gg = mult(gg,inv[i-1]);
	return gg;
}

void init2(){
	p2[0] = 1;
	FOR(i,1,N){
		p2[i] = mult2(p2[i-1],base2);
	}
	int pw_inv = binpow2(base2,MOD2-2);
	inv2[0] = 1;
	FOR(i,1,N){
		inv2[i] = mult2(inv2[i-1],pw_inv);
	}
}

void compute_hash2(){
	H2[1] = mult2((s[1]-'a')+1,p2[0]);
	FOR(i,2,n+1){
		H2[i] = add2(H2[i-1],mult2((s[i]-'a')+1,p2[i-1]));
	} 
}
int get_hash2(int i,int j){
	if(i == 1) return H2[j];
	int gg = add2(H2[j],-H2[i-1]);
	gg = mult2(gg,inv2[i-1]);
	return gg;
}
