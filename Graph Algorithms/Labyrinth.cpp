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
        char a[n][m];
        pll x,y;
        loop(0,n,i)
        {
            loop(0,m,j)
            {
                cin>>a[i][j];
                if(a[i][j]=='A') x = {i,j};
                else if(a[i][j]=='B') y = {i,j};
            }
        }
        bool vis[1001][1001];
        ll prev[1001][1001];
        queue<pll> q;
        q.push(x);
        vis[x.f][x.se] = true;
        while(!q.empty())
        {
            pll p = q.front();
            q.pop();
            loop(0,4,i)
            {
                pll tmp = {p.f + dx[i],p.se + dy[i]};
                if(tmp.f < 0 || tmp.f >= n || tmp.se < 0 || tmp.se >= m) cn;
                if(a[tmp.f][tmp.se] == '#') cn;
                if(vis[tmp.f][tmp.se]) cn;
                vis[tmp.f][tmp.se] = true;
                prev[tmp.f][tmp.se] = i;
                q.push(tmp);
            }
        }
        //  cout << (vis[y.f][y.se] ? "yes" : "no");
        vector<char> ans;
        if(vis[y.f][y.se])
        {
            cout<<"YES\n";
            while(y != x)
            {
                ll res = prev[y.f][y.se];
                if(res==0) ans.pb('U');
                else if(res==1) ans.pb('D');
                else if(res==2) ans.pb('R');
                else ans.pb('L');
                y = {y.f - dx[res],y.se - dy[res]};
            }
            reverse(all(ans));
            cout<<ans.size()<<endl;
            for(auto it:ans) cout<<it;
        }
        else cout<<"NO";
    }
 
 
cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
return 0;
}
