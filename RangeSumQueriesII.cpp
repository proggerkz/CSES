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
	x = x + y + mod;
	x %= mod;
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
ll T[N];
void update(int v, int tl, int tr, int l, int r, ll x){
	if(l > tr || r < tl) return;
	if(l <= tl && tr <= r){
		T[v] = x;
		return;
	}
	int tm = tl + tr >> 1;
	update(2 * v, tl, tm, l, r, x);
	update(2 * v + 1, tm + 1, tr, l, r, x);
	T[v] = (T[v * 2] + T[v * 2 + 1]);
}
ll get(int v, int tl, int tr, int l, int r){
	if(l > tr || r < tl) return 0;
	if(l <= tl && tr <= r){
		return T[v];
	}
	int tm = tl + tr >> 1;
	return (get(2 * v, tl, tm, l, r) + get(2 * v + 1, tm + 1, tr, l, r));
}
 
 
 
void solve()
{
	ll n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; ++i){
		int x;
		cin >> x;
		update(1, 1, n, i, i, x);
	}
	for(int i = 1; i <= q; ++i){
		int type;
		cin >> type;
		ll l, r;
		cin >> l >> r;
		if(type == 1){
			update(1, 1, n, l, l, r);
		}
		else
		cout << get(1, 1, n, l, r) << endl;
	}
}
 
int main()
{
    Red;
  	// int T; cin >> T; while(T--)
    solve();
    return 0;
}