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
 
const ll N=2e5+1;
ll seg[4*N];
 
void tree(ll a[],ll node,ll low,ll high)
{
	if(low==high)
	{
		seg[node]=a[low];
	}
	else
	{
		ll mid=low+(high-low)/2;
		tree(a,2*node,low,mid);
		tree(a,2*node+1,mid+1,high);
		seg[node]=min(seg[2*node],seg[2*node+1]);
	}
}
 
void update(ll a[],ll node, ll low, ll high, ll ind,ll val)
{
	if(low==high)
	{
		seg[node]=val;
		a[low]=val;
		return;
	}
	ll mid=(low+high)/2;
	if(low<=ind and ind<=mid)
		update(a,2*node,low,mid,ind,val);
	else
		update(a,2*node+1,mid+1,high,ind,val);
	seg[node] = min(seg[2*node],seg[2*node+1]);
 
}
 
ll solve(ll node,ll low,ll high,ll l,ll r)
{
	if(high<l or low>r)
		return INT_MAX;
	if(l<=low and high<=r)
		return seg[node];
	ll mid = low+(high-low)/2;
	ll lquery = solve(2*node,low,mid,l,r);
	ll rquery = solve(2*node+1,mid+1,high,l,r);
	return min(lquery,rquery);
}
 
int main()
{ quick;
 
    ll n,q; cin>>n>>q;
    ll a[n];
    loop(0,n,i) cin>>a[i];
    tree(a,1,0,n-1);
    while(q--)
    {
    	ll l,r; cin>>l>>r;
		cout << solve(1,0,n-1,l-1,r-1) << endl;
    }
 
 
 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}
