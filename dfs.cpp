#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define mod 1000000007
#define endl "\n"
#define pb push_back
#define mp make_pair
 
vector<vector<ll> > a(500005) ;
ll v[100005]={0};
 
void dfs(ll x)
{
	cout<<x<<" ";
	v[x]=1;
	for(ll i=0;i<a[x].size();i++)
	{
		if(!v[a[x][i]])
		{
			dfs(a[x][i]);
		}
	}
}
 
int main()
{
	ll n,x,y,m;
	cin>>n>>m;
	while(m--)
	{
		cin>>x>>y;
		a[x].pb(y);
		a[y].pb(x);
	}
	dfs(1);
}