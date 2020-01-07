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
 
// void add(ll &x, ll y){
// 	x = x + y + mod;
// 	x %= mod;
// }
ll bp(ll a, ll n){
	ll r = 1;
	while(n){
		if(n & 1) mul(r, a);
		mul(a, a);
		n >>= 1;
	}
	return r;
}
// vector <ll > t[N];
ll t[1001][1001];
int n, q;
 
ll get (int x, int y)
{
	ll result = 0;
	for (int i = x; i >= 0; i = (i & (i+1)) - 1)
		for (int j = y; j >= 0; j = (j & (j+1)) - 1)
			result += t[i][j];
	return result;
}
 
void inc (int x, int y, ll delta)
{
	for (int i = x; i < n; i = (i | (i+1)))
		for (int j = y; j < n; j = (j | (j+1)))
			t[i][j] += delta;
}
 
vector<int> g[N], gr[N], comps;
 
int used[N], dp[N];
 
void dfs(int v){
	used[v] = 1;
	for(int to : g[v]) if(!used[to]) dfs(to);
	comps.pb(v);
}
void solve()
{
	int n;
	cin >> n;
	for(int i = 2; i <= n; ++i){
		int x;
		cin >> x;
		g[x].pb(i);
		gr[i].pb(x);
	}
	dfs(1);
	// reverse(all(comps));
	for(int i = 0; i < sz(comps); ++i){
		int v = comps[i];
		for(int to : gr[v]){
			dp[to] += dp[v] + 1;
		}
	}
	for(int i = 1; i <= n; ++i){
		cout << dp[i] << " ";
	}
}
 
int main()
{
    Red;
  	// int T; cin >> T; while(T--)
    solve();
    return 0;
}