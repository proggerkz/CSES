#include <bits/stdc++.h>
 
using namespace std;
 
map<pair<int, int>, int> direction;
int used[100100];
vector<int> g[100100];
void dfs(int v){
	used[v] = 1;
	for(int to : g[v]){
		if(!used[to]){
			direction[make_pair(v, to)] = 1;
			direction[make_pair(to, v)] = -1;
			dfs(to);
		}
		else if(used[to] == 1){
			direction[make_pair(v, to)] = -1;	
		}
	}
	used[v] = 2;
}
int main()
{
	int n, m;
	cin >> n >> m;
	vector<pair<int, int> > edges;
	for(int i = 1; i <= m; ++i){
		int x, y;
		cin >> x >> y;
		edges.push_back(make_pair(x, y));
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for(int i = 1; i <= n; ++i){
		if(!used[i]){
			dfs(i);
		}
	}
	for(pair<int, int> x : edges){
		if(direction[x] == -1){
			swap(x.first, x.second);
		}
		cout << x.first << ' ' << x.second << '\n';
	}
	return 0;
}