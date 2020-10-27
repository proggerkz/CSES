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
ll bp(ll a, ll n, ll cm){
  ll r = 1;
  while(n){
    if(n & 1) r = r * a % cm;
    a = a * a % cm;
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
const int N = 2e5 + 111;
ll fen[N][2];
int n, k;
void upd(int v, int val, int id){
  for(; v <= n + 10; v += v & (-v))
    fen[v][id] += val;
}
ll get(int v, int id){
  ll sum = 0;
  for(; v > 0; v -= v & (-v))
    sum += fen[v][id];
  return sum;
}
int getMed(){
  int l = 0, r = n, ans = n ;
  while(l <= r){
    int m = l + r >> 1; 
    if(get(m, 0) < (k + 1) / 2) {
       l = m + 1;
    }else{
      ans = m, r = m - 1;
    }
  }
  return ans;
}
int val[N];
void makeIt(){
  // ++n;
  ll med = getMed();
  ll c1 = get(med , 0);
  // cout << med << '\n';
  ll res = val[med] * c1 - get(med, 1);
  ll c2 = get(n, 0) - get(med, 0);
  res +=  get(n, 1) - get(med, 1) - val[med] * c2;
  cout << max(0ll, res) << '\n';
  // --n;
}
void solve(){
  cin >> n >> k;
  int a[n];
  vector<int> b(n);
  rep(i, n) cin >> a[i], b[i] = a[i];
  sort(all(b));
  b.resize(unique(all(b)) - b.begin());
  rep(i, n) {
    int x = lower_bound(all(b), a[i]) - b.begin() + 1;
    val[x] = a[i];
    a[i] = x;
  }
 
  for(int i = 0; i < k; ++i){
    upd(a[i], 1, 0);
    upd(a[i], val[a[i]], 1);
  }
  // cout << get(3) << '\n';
  // cout << k << " " << n << ' ' << a[k - k] << '\n';
  makeIt();
  for(int i = k; i < n; ++i){
    upd(a[i - k], -1, 0);
    upd(a[i], 1, 0);
    upd(a[i - k], -val[a[i - k]], 1);
    upd(a[i], val[a[i]], 1);
    
    // cout << a[i] << " " << a[i - k] << ' ';
    makeIt();
  }
 
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