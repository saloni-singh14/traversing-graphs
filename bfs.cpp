#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define ld long double
#define mod 1000000007
#define endl "\n"
#define pb push_back
#define mp make_pair
 
vector<vector<ll> > a(200005);
 
ll v[200005];
queue<ll> que;
void bfs()
{
	while(!que.empty())
	{
		ll x=que.front();
		cout<<x<<" ";
		v[x]=1;
		que.pop();
		for(ll i=0;i<a[x].size();i++)
		{
			if(!v[a[x][i]])
			{
                que.push(a[x][i]);
			}
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
	que.push(1);
	bfs();
}