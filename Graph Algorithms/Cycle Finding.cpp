#include <bits/stdc++.h>
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
 
vector<pair<ll,pair<ll,ll>>> adj;
 
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
        ll n,m; cin>>n>>m;
        loop(0,m,i)
        {
            ll x,y,w; cin>>x>>y>>w;
            x--; y--;
            adj.pb({x,{y,w}});
        }
        vll dis(n+1,1e15) , par(n+1,-1);
        ll x;
        loop(0,n,i)
        {
            x = -1;
            for(auto it:adj)
            {
                if((dis[it.f] != INT_MAX) and (dis[it.f] + it.se.se < dis[it.se.f]))
                {
                    dis[it.se.f] = dis[it.f] + it.se.se;
                    par[it.se.f] = it.f;
                    x = it.se.f;
                }
            }
        }
        if(x==-1) cout<<"NO";
        else 
        {
            loop(0,n,i) x = par[x];
            vll cycle;
            for(ll v = x;; v = par[v]) 
            {
                cycle.pb(v);
                if(v==x and cycle.size()>1) break;
            }
            reverse(all(cycle));
            cout << "YES\n";
            for(auto it : cycle) cout<<it+1<<" ";
            cout << endl;
        }
    }
 
 
cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
return 0;
}
