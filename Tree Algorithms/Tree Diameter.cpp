#include<bits/stdc++.h>
#define ll               long long int 
#define loop(a,b,i)      for(long long int i=a;i<b;i++)
#define loopr(a,b,i)     for(long long int i=a;i>=b;i--)
#define cn               continue;
#define pb               push_back
#define db               double
#define mp               make_pair
#define endl             "\n"
#define lb               lower_bound
#define ub               upper_bound
#define f                first
#define se               second
#define vll              vector<ll>
#define pll              pair<ll,ll>
#define vpll             vector< pair<ll,ll> >
#define all(x)           x.begin(),x.end()
#define pi               3.14159265358979323846
#define quick            ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
 
const ll mod = 1e9 + 7;
const ll MAX  = 8000000000000000064LL;
const ll MIN  = -8000000000000000064LL;
ll add(ll x, ll y) {ll res = x + y; return (res >= mod ? res - mod : res);}
ll mul(ll x, ll y) {ll res = x * y; return (res >= mod ? res % mod : res);}
ll sub(ll x, ll y) {ll res = x - y; return (res < 0 ? res + mod : res);}
ll power(ll x, ll y) {ll res = 1; x %= mod; while (y) {if (y & 1)res = mul(res, x); y >>= 1; x = mul(x, x);} return res;}
ll mod_inv(ll x) {return power(x, mod - 2);}
ll gcd(ll a,ll b) {if(b==0)return a; return gcd(b,a%b);}
ll lcm(ll x, ll y) { ll res = x / gcd(x, y); return (res * y);}
// ll nCr(ll n,ll r){ll ans=fact[n]; ans*=mod_inv(fact[n-r]);ans%=mod; ans*=mod_inv(fact[r]);ans%=mod; return ans;}
using namespace std; 
 
const ll dx[] = {-1,1,0,0,1,1,-1,-1};
const ll dy[] = {0,0,1,-1,-1,1,-1,1};
 
bool isprime(ll n){  
    if(n<=1) return false; 
    if(n==2) return true;
    if(n%2==0 and n!=2) return false;
    for(ll i=2;i<=sqrt(n);i++) 
        if(n%i==0) 
            return false; 
    return true; 
} 
 
bool isPowerOfTwo(ll n){
   if(n==0) return false; 
   return (ceil(log2(n)) == floor(log2(n)));  
}
 
const int N = 2e5;
vll adj[N+1] , dis(N+1,0);
vector<bool> vis(N+1,false);
 
void bfs(ll x)
{
    queue<ll> q;
    q.push(x);
    dis[x] = 0;
    vis[x] = true;
    while(!q.empty())
    {
        ll x = q.front();
        q.pop();
        for(ll u=0;u<adj[x].size();u++)
        {
            if(!vis[adj[x][u]])
            {
                q.push(adj[x][u]);
                dis[adj[x][u]] = dis[x]+1;
                vis[adj[x][u]] = true;
            }
        }
    }
}
 
signed main() 
{ quick; 
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
      
    int tc = 1;
    // cin>>tc;
    while(tc--)
    {
        ll n; cin>>n;
        if(n==1)
        {
            cout<<0; cn;
        }
        loop(2,n+1,i)
        {
            ll a,b; cin>>a>>b;
            adj[a].pb(b);
            adj[b].pb(a);
        }
        bfs(1);
        ll mx = 0, ind = -1;
        loop(1,n+1,i) 
        {
            if(dis[i]>mx)
            {
                mx = dis[i];
                ind = i;
            }
        }
        vll dis1(n+1,0);
        vector<bool> vis1(n+1,false);
        queue<ll> q1;
        q1.push(ind);
        dis1[ind] = 0;
        vis1[ind] = true;
        while(!q1.empty())
        {
            ll x = q1.front();
            q1.pop();
            for(ll u=0;u<adj[x].size();u++)
            {
                if(!vis1[adj[x][u]])
                {
                    q1.push(adj[x][u]);
                    dis1[adj[x][u]] = dis1[x]+1;
                    vis1[adj[x][u]] = true;
                }
            }
        }
        ll ans = 0;
        loop(1,n+1,i) ans=max(ans,dis1[i]);
        cout << ans;
    }
 
 
cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
return 0;
}
