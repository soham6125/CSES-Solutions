#include<bits/stdc++.h>
#include<vector>
#include<iostream>
#include<string>
#include <unordered_map>
#define ll long long int 
#define loop(a,b,i) for(long long int i=a;i<b;i++)
#define loopr(a,b,i) for(long long int i=n-1;i>=0;i--)
#define pb push_back
#define db double
#define mp make_pair
#define endl "\n"
#define f first
#define se second
#define all(x) x.begin(),x.end()
#define MOD 1000000007
#define N 100005
#define quick ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
ll add(ll x, ll y) {ll res = x + y; return (res >= MOD ? res - MOD : res);}
ll mul(ll x, ll y) {ll res = x * y; return (res >= MOD ? res % MOD : res);}
ll sub(ll x, ll y) {ll res = x - y; return (res < 0 ? res + MOD : res);}
ll power(ll x, ll y) {ll res = 1; x %= MOD; while (y) {if (y & 1)res = mul(res, x); y >>= 1; x = mul(x, x);} return res;}
ll mod_inv(ll x) {return power(x, MOD - 2);}
using namespace std;

set<string> st; 
 
ll fact(ll n)
{
	ll ans=1;
	if(n==0)
		ans=1;
	else
		for(ll i=1;i<=n;i++){
			ans*=i;
		}
 
	return ans;
}
 
void permutes(string a,ll l,ll r)  
{  
    if(l==r){
        st.insert(a); 
        return;
    }
    else
    {    
        for(ll i=l;i<=r;i++)  
        {    
            swap(a[l],a[i]);    
            permutes(a,l+1,r); 
            swap(a[l],a[i]);  
        }  
    } 
}
 
int main() 
{ quick;
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
	
	string s;
	cin>>s;
	ll n=s.length();
	map<char,ll> mp;
	map<char,ll> :: iterator m;
	ll ans=fact(n);
	for(ll i=0;i<n;i++)
		mp[s[i]]++;
	for(m=mp.begin();m!=mp.end();m++)
		ans=ans/fact(m->second);
	cout<<ans<<endl;
	permutes(s,0,n-1);
	for(auto it : st)
		cout<<it<<endl;
 
cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
return 0;
}
