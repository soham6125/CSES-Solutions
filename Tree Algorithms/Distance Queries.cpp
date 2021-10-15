#include<bits/stdc++.h>
using namespace std;
 
const int N = 200005, LG = 20;
 
vector<int> g[N];
int par[N][LG + 1], dep[N];
 
void dfs(int u, int p = 0) 
{
  par[u][0] = p;
  dep[u] = dep[p] + 1;
  for (int i = 1; i <= LG; i++) par[u][i] = par[par[u][i - 1]][i - 1];
  for (auto v: g[u]) if (v != p) {
    dfs(v, u);
  }
}
 
int lca(int u, int v) 
{
  if (dep[u] < dep[v]) swap(u, v);
  for (int k = LG; k >= 0; k--) if(dep[par[u][k]] >= dep[v]) u = par[u][k];
  if (u == v) return u;
  for (int k = LG; k >= 0; k--) if(par[u][k] != par[v][k]) u = par[u][k], v = par[v][k];
  return par[u][0];
}
 
signed main() 
{
  int n,q; cin >> n >> q;
  for(int i = 1; i < n; i++) {
    int x,y; cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(1);
  while (q--) 
  {
    int u, v; cin >> u >> v;
    int l = lca(u, v);
    int ans = dep[u] + dep[v] - 2*dep[l];
    cout << ans << "\n";
  }
  return 0;
}
