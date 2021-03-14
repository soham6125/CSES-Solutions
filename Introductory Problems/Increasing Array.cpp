#include<bits/stdc++.h>
#include<vector>
#include<iostream>
#include<set>
#include<string>
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
#define mod 1000000007
#define quick ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
ll add(ll x, ll y) {ll res = x + y; return (res >= mod ? res - mod : res);}
ll mul(ll x, ll y) {ll res = x * y; return (res >= mod ? res % mod : res);}
ll sub(ll x, ll y) {ll res = x - y; return (res < 0 ? res + mod : res);}
ll power(ll x, ll y) {ll res = 1; x %= mod; while (y) {if (y & 1)res = mul(res, x); y >>= 1; x = mul(x, x);} return res;}
ll mod_inv(ll x) {return power(x, mod - 2);}
using namespace std;
 
int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
 
    // ll t;
    // cin>>t;
    // while(t--)
    // {
    	ll n;
    	cin>>n;
    	ll a[n];
    	loop(0,n,i){
    		cin>>a[i];
    	}
    	ll ans=0,mx=a[0];
    	for(ll i=1;i<n;i++)
    	{
    		if(a[i]<mx)
    		{
    			ans = (ans + (mx-a[i]));
    		}
    		else if(a[i]>mx)
    		{
    			mx=a[i];
    		}
    	}
    	cout<<ans;
    // }
    return 0;
}
