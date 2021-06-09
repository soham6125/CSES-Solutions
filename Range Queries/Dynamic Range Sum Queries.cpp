#include<bits/stdc++.h>
#include<vector>
#include<set>
#include<iostream>
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
#define MOD 1000000007
#define quick ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
ll add(ll x, ll y) {ll res = x + y; return (res >= MOD ? res - MOD : res);}
ll mul(ll x, ll y) {ll res = x * y; return (res >= MOD ? res % MOD : res);}
ll sub(ll x, ll y) {ll res = x - y; return (res < 0 ? res + MOD : res);}
ll power(ll x, ll y) {ll res = 1; x %= MOD; while (y) {if (y & 1)res = mul(res, x); y >>= 1; x = mul(x, x);} return res;}
ll mod_inv(ll x) {return power(x, MOD - 2);}
using namespace std;
const ll N = 2e5+1;
ll seg[4*N];
 
void build(ll a[],ll node,ll low,ll high)
{
	if(low==high){
		seg[node]=a[low];
	}
	else
	{
		ll mid = (low+high)/2;
		build(a,node*2,low,mid);
		build(a,node*2 + 1,mid+1,high);
		seg[node] = seg[node*2] + seg[node*2 +1];	
	}
}
 
void update(ll node,ll low,ll high,ll ind,ll val)
{
	if(low==high)
	{
		seg[node] = val;
	}
	else
	{
		ll mid=(low+high)/2;
		if(ind<=mid)
		{
			update(node*2,low,mid,ind,val);
		}
		else
		{
			update(node*2 + 1,mid+1,high,ind,val);
		}
		seg[node] = seg[node*2] + seg[node*2 + 1];
	}
}
 
ll query(ll node,ll low,ll high,ll l,ll r)
{
	if(l>r)
	{
		return 0;
	}
	else if(l<=low && r>=high)
	{
		return seg[node];
	}
	else
	{
		ll m = (low+high)/2;
		ll q1 = query(node*2 , low , m , l , min(r,m));
		ll q2 = query(node*2 + 1 , m+1 , high , max(l,m+1) , r);
		return q1 + q2;
	}
}
 
int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	
	ll n,q; cin>>n>>q;
	ll a[n];
	loop(0,n,i) cin>>a[i];
	build(a,1,0,n-1);
	while(q--)
	{
		ll x; cin>>x;
		if(x==1)
		{
			ll k,u; cin>>k>>u;
			update(1,0,n-1,k-1,u);
		}
		else
		{
			ll l,r; cin>>l>>r;
			cout << query(1,0,n-1,l-1,r-1) << endl;
		}
	}
 
	return 0;
}
