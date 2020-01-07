#include <bits/stdc++.h>
  
using namespace std;
  
template<class T> void ckmin(T &a, T b) { a = min(a, b); }
template<class T> void ckmax(T &a, T b) { a = max(a, b); }
  
#define pb push_back
#define mp make_pair
#define cotu cout
#define itn int
#define Red ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define F first
#define S second
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for(int i = 0; i < n; ++i)
#define repr(i,n) for(int i = n - 1; i >= 0; --i)
#define Rep(i, a, n) for(int i = (a); i <=(n); ++i)
#define repst(i, n) for(auto it = n.begin(); it != n.end(); ++it)
#define Repr(i, a, n) for(int i = (n); i >= (a); --i)
  
#define ordered_set tree<int , null_type,less<int >, rb_tree_tag,tree_order_statistics_node_update> 
  
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
  
const int inf = int(1e9);
const int mod = inf + 7;
const int N = 1e6 + 555; // TL MB
const double PI = acos(-1.0);
 
void mul(ll &x, ll y){
	x *= y;
	x %= mod;
}
 
void add(ll &x, ll y){
	x += y;
	if(x >= mod) x -= mod;
}
ll bp(ll a, ll n){
	ll r = 1;
	while(n){
		if(n & 1) mul(r, a);
		mul(a, a);
		n >>= 1;
	}
	return r;
}
ll cnt[26], fact[N], invFact[N];
void solve()
{
	string s;
	cin >> s;
	int n = sz(s);
	fact[0] = 1;
	invFact[0] = bp(1, mod - 2);
	for(int i = 1; i <= n; ++i){
		fact[i] = i;
		mul(fact[i], fact[i - 1]);
		invFact[i] = bp(fact[i], mod - 2);
	}
	rep(i, sz(s)) cnt[s[i] - 'a']++;
	ll ans = 1, all = fact[n];
	rep(i, 26){
		if(cnt[i] == 0) continue;
		ans = ans * fact[n] % mod * invFact[cnt[i]] % mod * invFact[n - cnt[i]] % mod;
		n -= cnt[i];
		ans %= mod;
	}
	cout << ans;
 
}
 
int main()
{
    Red;
	solve();
    return 0;
}