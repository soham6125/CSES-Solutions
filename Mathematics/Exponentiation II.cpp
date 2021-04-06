#include<bits/stdc++.h>
#include<vector>
#include<iostream>
#include<string>
#include<unordered_map>
#define ll long long int 
#define loop(a,b,i) for(long long int i=a;i<b;i++)
#define loopr(a,b,i) for(long long int i=a-1;i>=b;i--)
#define pb push_back
#define db double
#define mp make_pair
#define endl "\n"
#define f first
#define se second
#define vll vector<ll>
#define pll pair<ll,ll>
#define vpll vector< pair<ll,ll> >
#define all(x) x.begin(),x.end()
#define quick ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
 
const int mod = 1000000007;
ll add(ll x, ll y,ll mod) {ll res = x + y; return (res >= mod ? res - mod : res);}
ll mul(ll x, ll y,ll mod) {ll res = x * y; return (res >= mod ? res % mod : res);}
ll sub(ll x, ll y,ll mod) {ll res = x - y; return (res < 0 ? res + mod : res);}
ll power(ll x, ll y,ll mod) {ll res = 1; x %= mod; while (y) {if (y & 1)res = mul(res, x, mod); y >>= 1; x = mul(x, x, mod);} return res;}
// ll mod_inv(ll x) {return power(x, mod - 2);}
using namespace std;

int main() 
{ quick;  
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
 
    int tc = 1;
    cin>>tc;
    while(tc--)
    { 
      ll a,b,c;
      cin>>a>>b>>c;
      ll x = power(b,c,mod-1);
      cout<<power(a,x,mod)<<endl;
    }
 
cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
return 0;
}
