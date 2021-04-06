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
ll add(ll x, ll y) {ll res = x + y; return (res >= mod ? res - mod : res);}
ll mul(ll x, ll y) {ll res = x * y; return (res >= mod ? res % mod : res);}
ll sub(ll x, ll y) {ll res = x - y; return (res < 0 ? res + mod : res);}
ll power(ll x, ll y) {ll res = 1; x %= mod; while (y) {if (y & 1)res = mul(res, x); y >>= 1; x = mul(x, x);} return res;}
ll mod_inv(ll x) {return power(x, mod - 2);}
using namespace std;
 
const int N = 1e6;
ll spf[N+1];
 
void prime_factors()
{
  for(ll i=0;i<N+1;i++)
  {
    spf[i]=i;
  }
  for(ll i=2;i<=N;i++)
  {
    if(spf[i]==i)
    {
      for(ll j=i*i;j<=N;j+=i)
      {
        if(spf[j]==j)
          spf[j]=i;
      }
    }
  }
}
 
ll count_divisors(ll n)
{
  ll ans = 1;
  while(n!=1)
  {
    ll y = spf[n];
    ll x = 1;
    while(n%y==0)
    {
      x++;
      n /= y;
    }
    ans *= x;
  }
  return ans;
}
 
int main() 
{ quick;  
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
 
    prime_factors();
    int tc = 1;
    cin>>tc;
    while(tc--)
    { 
      ll n;
      cin>>n;
      cout<<count_divisors(n)<<endl;
    }
 
cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
return 0;
}
