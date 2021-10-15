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
 
const int dx[] = {-1,1,0,0,1,1,-1,-1};
const int dy[] = {0,0,1,-1,-1,1,-1,1};

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
        char a[n][n];
        ll dp[n][n];
        loop(0,n,i)
        {
            loop(0,n,j)
            {
                cin>>a[i][j];
                dp[i][j] = 0;
            }
        }  
        if(a[0][0]=='*' or a[n-1][n-1]=='*')
        {
            cout<<0; cn;
        }
        dp[0][0] = (a[0][0]=='*' ? 0 : 1);
        bool ok = false;
        for(ll i=1;i<n;i++) 
        {
            if(a[0][i]=='*') ok = true;
            if(ok) dp[0][i] = 0;
            else dp[0][i] = 1;
        }
        ok = false;
        for(ll i=1;i<n;i++) 
        {
            if(a[i][0]=='*') ok = true;
            if(ok) dp[i][0] = 0;
            else dp[i][0] = 1;
        }   
        for(ll i=1;i<n;i++)
        {
            for(ll j=1;j<n;j++)
            {
                if(a[i-1][j]=='*' and a[i][j-1]=='.') dp[i][j] = dp[i][j-1];
                else if(a[i][j-1]=='*' and a[i-1][j]=='.') dp[i][j] = dp[i-1][j];
                else if(a[i-1][j]=='*' and a[i][j-1]=='*') dp[i][j] = 0;
                else dp[i][j] = add(dp[i-1][j],dp[i][j-1]);
            }
        }
        cout << dp[n-1][n-1];
    }
 
cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
return 0;
}
