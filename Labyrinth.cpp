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
 
 
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int n, m, used[1001][1001];
pii p[1001][1001];
bool check(int x, int y){
	return x >= 0 && x < n && y >= 0 && y < m;
}
void solve(){
	cin >> n >> m;
	char c[n][m];
	int fx, fy, sx, sy;
	rep(i, n) rep(j, m){
		cin >> c[i][j];
		p[i][j] = {inf, inf};
		if(c[i][j] == 'A') fx = i, fy = j;
		if(c[i][j] == 'B') sx = i, sy = j;
	}	
	queue<pii> q;
	q.push({fx, fy});
	used[fx][fy] = 1;
	while(!q.empty()){
		int x = q.front().F, y = q.front().S;
		// cout << x << ' ' << y << endl;
		q.pop();
		for(int i = 0; i < 4; ++i){
			int xx = x + dx[i], yy = y + dy[i];
			if(check(xx, yy) && c[xx][yy] != '#' && !used[xx][yy]){
				p[xx][yy] = {x, y};
				used[xx][yy] = 1;
				q.push({xx, yy});
			}	
		}
	}
	if(p[sx][sy].F == inf && p[sx][sy].S == inf) cout << "NO";
	else{
		cout << "YES\n";
		string ans = "";
		while(!(sx == fx && sy == fy)){
			int le = sx - p[sx][sy].F;
			int ri = sy - p[sx][sy].S;
			if(le == 1) ans += 'D';
			if(le == -1) ans += 'U';
			if(ri == 1) ans += 'R';
			if(ri == -1) ans += 'L';
			int tox = sx;
			sx = p[tox][sy].F;
			sy = p[tox][sy].S;
		}
		reverse(all(ans));
		cout << sz(ans) << endl << ans;
	}
}
 
 
int main()
{
    Red;
    solve();
    return 0;
}