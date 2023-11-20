#include<bits/stdc++.h>
#define sz 200005
using namespace std;

vector<int>adj[sz],cost[sz];
int vis[sz];

priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int> > > >pq;

int prims(int st)
{
    for (int i = 0; i<adj[st].size(); i++)
        pq.push({cost[st][i], {st,adj[st][i]}});

    vector<pair<int,pair<int,int> > >ans;
    vis[st]=1;
    int c, u, v, tot=0;
    while(!pq.empty())
    {
        c = pq.top().first;
        u = pq.top().second.first;
        v = pq.top().second.second;
        pq.pop();
        if(!vis[u] || !vis[v])
        {
            ans.push_back( {c, {u,v} } );
            tot+=c;
            if(vis[u]==1)
                u = v;

            vis[u]=1;
            for (int i = 0; i<adj[u].size(); i++)
            {
                if(! vis[adj[u][i]])
                    pq.push({cost[u][i],{u,adj[u][i]}});
            }
        }
    }

    for (int i = 0; i<ans.size(); i++)
    {
        cout<<i<<":"<<ans[i].first<<" -> ("<<ans[i].second.first << "," <<ans[i].second.second << ")"<<endl;
    }
    return tot;
}
int main()
{
    int st,n,m,x,y,z; //n=node  m=edges
    cin>>n>>m;
    for (int i = 0; i<m; i++)
    {
        cin>>x>>y>>z;
        adj[x].push_back(y);
        cost[x].push_back(z);
        adj[y].push_back(x);
        cost[y].push_back(z);
    }
    cin>>st;
    cout<<"Total Cost of MST = "<<prims(st)<<"\n";
    return 0;
}

/*
9 14
0 1 4
0 7 8
1 2 8
2 3 7
3 4 9
7 6 1
6 5 2
5 4 10
7 8 7
2 8 2
8 6 6
2 5 4
3 5 14
1 7 11
0
*/
/*
4 6
1 2 2
1 3 1
1 4 3
2 3 4
2 4 1
3 4 2
1
*/
