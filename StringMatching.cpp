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
 
const int N = 10000000;
 
 
vector<int> z_function (string s) {
	int n = (int) s.length();
	vector<int> z (n);
	for (int i=1, l=0, r=0; i<n; ++i) {
		if (i <= r)
			z[i] = min (r-i+1, z[i-l]);
		while (i+z[i] < n && s[z[i]] == s[i+z[i]])
			++z[i];
		if (i+z[i]-1 > r)
			l = i,  r = i+z[i]-1;
	}
	return z;
}
void solve()
{
 
	string n, m;
	cin >> n >> m;
	int s = sz(m);
	n = m + '#' + n;
	// cout << n << endl;
	vector<int> p = z_function(n);
	int res = 0;
	for(int i = 0; i < sz(p); ++i){
		if(i && p[i] == s) ++res;
	}
	cout << res;
}
 
 
int main()
{
    Red;
  	// int T; cin >> T; while(T--)
    solve();
    return 0;
}