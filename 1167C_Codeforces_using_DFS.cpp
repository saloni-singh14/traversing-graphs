/*
In some social network, there are n users communicating with each other in m groups of friends. Let's analyze the process of distributing some news between users.

Initially, some user x receives the news from some source. Then he or she sends the news to his or her friends (two users are friends if there is at least one group such that both of them belong to this group). Friends continue sending the news to their friends, and so on. The process ends when there is no pair of friends such that one of them knows the news, and another one doesn't know.

For each user x you have to determine what is the number of users that will know the news if initially only user x starts distributing it.

Input
The first line contains two integers n and m (1≤n,m≤5⋅105) — the number of users and the number of groups of friends, respectively.

Then m lines follow, each describing a group of friends. The i-th line begins with integer ki (0≤ki≤n) — the number of users in the i-th group. Then ki distinct integers follow, denoting the users belonging to the i-th group.

It is guaranteed that ∑i=1mki≤5⋅105.

Output
Print n integers. The i-th integer should be equal to the number of users that will know the news if user i starts distributing it.
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long 
#define mod 1000000007
#define endl "\n"
#define pb push_back
#define mp make_pair
 
vector<int> a[500005] ;
ll v[500005]={0};
ll dp[500005]={0};
int n,ans=0;
int cou[500005]={0};
void dfs(int x)
{
	v[x]=ans;
	cou[ans]++;
	for(int i=0;i<a[x].size();i++)
	{
		if(v[a[x][i]]==0)
		{
			dfs(a[x][i]);
			//v[a[x][i]]=cou[ans];
			
		}
		//cou[a[x][i]]=cou[ans];
	}
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m;
    cin>>n>>m;
    int k;
    for(int i=0;i<m;i++)
    {
    	int x;
    	cin>>k;
    	if(k==n)
    	{
    	    for(int i=0;i<n;i++)
    	    cout<<n<<" ";
    	    return 0;
    	}
    	
    	else if(k>=1)
    	{
    		cin>>x;
    		for (int j = 1; j < k; j++)
    		{
    			int y;
    			cin>>y;
    			a[x].pb(y);
    			a[y].pb(x);
    		}
    	}
    	
    }
    ans++;
    for(int i=1;i<=n;i++)
    	{
    	       if(v[i]==0)
    	        dfs(i);
    	       else
    	        {
    	            cou[i]=cou[v[i]];
    	        }
    	        ans++;
    	}
    	
   	for(int i=1;i<=n;i++)
    cout<<cou[i]<<" ";
    
    return 0;
}
