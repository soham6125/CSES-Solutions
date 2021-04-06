#include<bits/stdc++.h>
#include<vector>
#include<iostream>
#include<string>
#include<math.h>
#define ll long long int
#define loop(a,b,i) for(int i=a;i<b;i++)
#define loopr(a,b,i) for(int i=n-1;i>=0;i--)
#define pb push_back
#define db double
#define mp make_pair
#define endl "\n"
#define f first
#define se second
#define all(x) x.begin(),x.end()
#define MOD 1000000007
#define quick ios_base::sync_with_stdio(false);cin.tie(NULL)
ll add(ll x, ll y) {ll res = x + y; return (res >= MOD ? res - MOD : res);}
ll mul(ll x, ll y) {ll res = x * y; return (res >= MOD ? res % MOD : res);}
ll sub(ll x, ll y) {ll res = x - y; return (res < 0 ? res + MOD : res);}
ll power(ll x, ll y) {ll res = 1; x %= MOD; while (y) {if (y & 1)res = mul(res, x); y >>= 1; x = mul(x, x);} return res;}
ll mod_inv(ll x) {return power(x, MOD - 2);}
using namespace std;
 
int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
 
	ll n;
	cin>>n;
	ll a[n];
	ll i;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	ll ans=a[0],sum=a[0];
	for(i=1;i<n;i++)
	{
		sum=max(a[i],a[i]+sum);
		if(sum>ans)
		{
			ans=sum;
		}
	}
	cout<<ans<<endl;
  return 0;
}
