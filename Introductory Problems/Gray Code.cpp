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

vector<string> gray_code(int n)
{
  if(n==1) return {"0","1"};
  vector<string> tmp = gray_code(n-1);
  vector<string> ans;
  for(int i=0;i<tmp.size();i++)
  {
    ans.pb('0'+tmp[i]);
  }
  for(int i=0;i<tmp.size();i++)
  {
    ans.pb('1'+tmp[i]);
  }
  return ans;
}

int main() 
{ quick;  
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

    int tc = 1;
    // cin>>tc;
    while(tc--)
    {
      ll n;
      cin>>n;
      vector<string> ans = gray_code(n);
      for(string x:ans) cout<<x<<endl;
    } 

cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
return 0;
}
