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
