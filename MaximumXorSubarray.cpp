#include <bits/stdc++.h>

using namespace std;

int curxor = 0;
const int N = 200200 * 31;
int t[N][2];
int pos = 1;
void add(int x){
	int q = 0;
	for(int i = 31; i >= 0; --i){
		int p = (x >> i) & 1;
		if(!t[q][p]) t[q][p] = pos++;
		q = t[q][p];
	}
}
int get(int x){
	int r = 0, q = 0, nxt = 0;
	for(int i = 31; i >= 0; --i){
		int p = (x >> i) & 1;
		if(t[q][!p]){
			r += (1 << i);
			nxt = !p;
		}
		else{
			nxt = p;
		}
		q = t[q][nxt];
	}
	return r;
}
int main()
{
	int n;
	cin >> n;
	int xr = 0, res = 0;
		// pos = 1;
	for(int i = 0; i < n; ++i){
		int x;
		cin >> x;
		xr ^= x;
		add(xr);
		res = max(res, get(xr));
		res = max(res, xr);
	}
	cout << res << '\n';
	return 0;
}
