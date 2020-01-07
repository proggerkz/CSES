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
// const int N = 1e6 + 555; // TL MB
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
 
int dp[1001][100100], h[1001], p[1001];
void solve()
{
	int n, s;
	cin >> n >> s;
	for(int i = 0; i < n; ++i) cin >> h[i];
	for(int i = 0; i < n; ++i) cin >> p[i];
	for(int i = 0; i < n; ++i){
		for(int j = 1; j < n; ++j){
			if(h[j - 1] > h[j]) {
				swap(h[j - 1], h[j]), swap(p[j - 1], p[j]);
			}
		}
	}
	int mx = 0;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= s; ++j){
			if(j >= h[i - 1]){
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - h[i - 1]] + p[i - 1]);
			}
			else dp[i][j] = dp[i - 1][j];
			mx = max(mx, dp[i][j]);	
		}
	}
	cout << mx << endl;
}
 
 
int main()
{
    Red;
    solve();
    return 0;
}