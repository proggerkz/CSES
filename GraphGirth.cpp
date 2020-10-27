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
#define setp(x) fixed << setprecision(x)
#define ordered_set tree<int , null_type,less<int >, rb_tree_tag,tree_order_statistics_node_update> 
  
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
  
const int inf = int(1e9);
const ll INF = ll(1e16);
const int mod = inf + 7;
const int N = 1e6 + 555; // TL MB
const double PI = acos(-1.0);
void mul(ll &x, ll y){
	x *= y;
	if(x >= mod) x %= mod;
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
const ll MASK = (1 << 21);
ll res[MASK], dp[MASK];
string tobin(int x){
	string t = "";
	while(x){
		t += (x % 2 + '0');
		x /= 2;
	}
	return t;
}
vector<int> g[N];
int d[N], used[N];
	int n, m;
int bfs(int v, int t){
	rep(i, n) used[i + 1] = 0, d[i + 1] = inf;
	d[v] = 0;
	queue<int> q;
	q.push(v);
	while(!q.empty()){
		int xx = q.front();
		q.pop();
		for(int to : g[xx]){
			if(d[to] == inf){
				d[to] = d[xx] + 1;
				q.push(to);
			}
		}
	}
	return d[t];
}
void solve()
{			
		cin >> n >> m;
		vector<pii> p(m);
		for(int i = 0; i < m; ++i){
			int l, r;
			cin >> l >> r;
			p[i] = mp(l, r);
		}
		int ans = inf;
		for(int i = 0; i < m; ++i){
			for(int j = 0; j < m; ++j) if(i != j) g[p[j].F].pb(p[j].S), g[p[j].S].pb(p[j].F);
			int d = bfs(p[i].F, p[i].S);
			ans = min(ans, d);
			for(int j = 1; j <= n; ++j) g[j].clear();
		}
		cout << (ans == inf ? -1 : ans + 1);
}
	
 
 
int main()
{
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
    Red;
  	int T = 1;
  	// cin >> T;
  	for(int i = 1; i <= T; ++i){
  		solve();
  	}
  	return 0;
 
}