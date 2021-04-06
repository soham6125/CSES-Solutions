#include<bits/stdc++.h>
#include<vector>
#include<iostream>
#include<string>
#include <unordered_map>
#define ll long long int 
#define loop(a,b,i) for(long long int i=a;i<b;i++)
#define loopr(a,b,i) for(long long int i=a-1;i>=b;i--)
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
 
void solve(vector<ll> v)
{
	ll n=v.size();
	stack<ll> st;
	for(ll i=0;i<n;i++)
	{
		while(!st.empty() and v[st.top()]>=v[i])
			st.pop();
		if(st.empty()==true)
			cout<<"0 ";
		else
			cout<<st.top()+1<<" ";
		st.push(i);
	}
}
 
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
			vector<ll> a;
			loop(0,n,i) 
			{
				ll y;cin>>y;
				a.pb(y);
			}
			solve(a);
	// }
 
cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
return 0;
}
