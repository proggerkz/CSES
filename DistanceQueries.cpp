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
	// x %= mod;
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
vector<int> g[N];
int tin[N], tout[N], T, used[N], up[N][20], LOG = 19, h[N];
void dfs(int v, int p){
	tin[v] = ++T;
	used[v] = 1;

	if(v != 1) h[v] = h[p] + 1;
	up[v][0] = p;
	for(int i = 1; i <= 19; ++i) up[v][i] = up[up[v][i - 1]][i - 1];
	for(int to : g[v]) if(!used[to]) dfs(to, v);
	tout[v] = ++T; 
}
bool isa(int u, int v){
	return tin[u] <= tin[v] && tout[u] >= tout[v];
}
int lca(int u, int v){
	if(isa(u, v)) return u;
	if(isa(v, u)) return v;
	for(int i = 19; i >= 0; --i){
		if(!isa(up[u][i], v)) u = up[u][i];
	}
	return up[u][0];
}
int depth(int a, int b){
	return h[a] + h[b] - 2 * h[lca(a, b)];
}
 
void solve()
{	
	int n, q;
	cin >> n >> q;
	rep(i, n - 1){
		int x, y;
		cin >> x >> y;
		g[x].pb(y);
		g[y].pb(x);
	}
	dfs(1, 1);
	while(q--){
		int x, y;
		cin >> x >> y;
		cout << depth(x, y) << endl;
	}
}
int main()
{
    Red;
  	// int T; cin >> T; while(T--)
    solve();
    return 0;
}