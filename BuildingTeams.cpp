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
 
void mul(ll &x, ll y, ll md){
	x *= y;
	x %= md;
}
 
// void add(ll &x, ll y){
// 	x = x + y + mod;
// 	x %= mod;
// }
ll bp(ll a, ll n, ll md){
	ll r = 1;
	while(n){
		if(n & 1) mul(r, a, md);
		mul(a, a, md);
		n >>= 1;
	}
	return r;
}
int d[N], p[N];
int par[N];
queue<int> q;
vector<int> g[N];
int get(int v){
	return v == par[v] ? v : par[v] = get(par[v]);
}
void un(int u, int v){
	u = get(u); v = get(v);
	if(u != v){
		p[v] = u;
	}
}
void solve(){
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) d[i] = inf, par[i] = i;
	queue<int> q;
	for(int i = 0; i < m; ++i){
		int x, y;
		cin >> x >> y;
		g[x].pb(y);
		g[y].pb(x);	
	}
	set<int> a, b;
	for(int i = 1; i <= n; ++i){
		if(d[i] != inf) continue;
		q.push(i);
		d[i] = 0;
		while(!q.empty()){
			int v = q.front();
			q.pop();
			if(d[v] % 2 == 0) a.insert(v);
			else b.insert(v);
			for(int to : g[v]){
				if(d[to] == inf){
					d[to] = d[v] + 1;
					q.push(to);
					p[to] = v;
				}
			}
		}
	}
	for(auto it : a){
		for(int j = 0; j < g[it].size(); ++j){
			int to = g[it][j];
			if(a.find(to) != a.end()){
				cout << "IMPOSSIBLE" << endl;
				return;
			}
		}
	}
	for(auto it : b){
		for(int j = 0; j < g[it].size(); ++j){
			int to = g[it][j];
			if(b.find(to) != b.end()){
				cout << "IMPOSSIBLE" << endl;
				return;
			}
		}
	}
	for(int i = 1; i <= n; ++i){
		if(a.find(i) != a.end()) cout << 1;
		else cout << 2;
		cout << " ";
	}
}
 
 
int main()
{
    Red;
    solve();
    return 0;
}