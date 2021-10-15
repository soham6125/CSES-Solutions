#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10, LG = 18;

vector<int> g[N];
int par[N][LG + 1], dep[N], sz[N];

void dfs(int u, int p = -1) 
{
  par[u][0] = p;
  dep[u] = dep[p] + 1;
  sz[u] = 1;
  for (int i = 1; i <= LG; i++) par[u][i] = par[par[u][i - 1]][i - 1];
  for (auto v: g[u]) if (v != p) {
    dfs(v, u);
    sz[u] += sz[v];
  }
}

int lca(int u, int v) 
{
  if (dep[u] < dep[v]) swap(u, v);
  for (int k = LG; k >= 0; k--) if (dep[par[u][k]] >= dep[v]) u = par[u][k];
  if (u == v) return u;
  for (int k = LG; k >= 0; k--) if (par[u][k] != par[v][k]) u = par[u][k], v = par[v][k];
  return par[u][0];
}

int kth(int u, int k) 
{
  assert(k >= 0);
  for (int i = 0; i <= LG; i++) if (k & (1 << i)) u = par[u][i];
  return u;
}

signed main() 
{
  int n,q; cin >> n >> q;
  for(int i = 1; i < n; i++) {
    int x; cin >> x;
    g[i+1].push_back(x);
    g[x].push_back(i+1);
  }
  dfs(1);
  while (q--) 
  {
    int u, v; cin >> u >> v;
    int ans = kth(u, v);
    if(ans<=0) ans = -1;
    cout << ans << "\n";
  }
  return 0;
}
