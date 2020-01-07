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
	x += y;
	if(x >= mod) x -= mod;
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
int ceilElement(int a[],int start,int end,int key){
    while(end-start > 1){
         int mid = start +(end - start)/2;
         if(a[mid]>=key){
             end = mid;
         }
         else{
             start = mid;
         }
    }
	return end;
}
 
int longestIncreasingSubsequence(int input[], int size)
{
     if(!size)
         return 0;
 
     int a[size];
     int length=1;
 
     a[0] = input[0];
 
     for(int i=1; i<size; i++)
     {
          if(input[i]< a[0]){
               a[0]=input[i];
          }
          else if(input[i]>a[length-1]){
               a[length++]=input[i];
          }
          else {
          a[ ceilElement(a,-1,length-1,input[i]) ]= input[i];
          }
      }
     return length;
}
 
void solve()
{
	int n;
	cin >> n;
 
	int a[n];
	rep(i, n) cin >> a[i];
	cout << longestIncreasingSubsequence(a, n);
 
 
}
 
 
int main()
{
    Red;
	solve();
    return 0;
}