#include <bits/stdc++.h>
using namespace std;
  
template<class T> void ckmin(T &a, T b) { a = min(a, b); }
template<class T> void ckmax(T &a, T b) { a = max(a, b); }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  
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
#define ordered_set tree<pair<long double, int> , null_type,less<pair<long double, int> >, rb_tree_tag,tree_order_statistics_node_update> 
 
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
  
const int inf = int(1e9);
const ll INF = ll(1e16);
const int mod = inf + 7;
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
template<typename T_vector> // neal
void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());
 
    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}
map<ll, int> y;
void solve(){
  ll n, x;
  cin >> n >> x;
  ll a[n];
  rep(i, n) cin >> a[i];
  vector<ll> first, second;
  for(int i = 0; i < n; ++i){
    if(i < n / 2) first.pb(a[i]);
    else second.pb(a[i]);
  } 
  ll res = 0;
  vector<ll> firstvalues;
  rep(i, 1 << sz(first)){
    if(!i) continue;
    ll sum = 0;
    rep(j, sz(first)){
      if(i >> j & 1) sum += first[j];
    }
    if(sum == x) res++; 
    firstvalues.pb(sum);
  }
  sort(all(firstvalues));
  rep(i, 1 << sz(second)){
    if(!i) continue;
    ll sum = 0;
    rep(j, sz(second)){
      if(i >> j & 1) sum += second[j];
    }
    if(sum == x) res++;
    res += 
    (upper_bound(all(firstvalues), x - sum) - begin(firstvalues)) -  
    (lower_bound(all(firstvalues), x - sum) - begin(firstvalues)); 
  }
  cout << res;
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