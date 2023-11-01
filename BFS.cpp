#include<bits/stdc++.h>
using namespace std;
int main()
{
    int node,edge,start_node;
    cout<<"Enter number of nodes: ";
    cin>>node;
    cout<<"Enter number of edges: ";
    cin>>edge;

    bool visit[node+1];  //boolean type array
    vector<int> adj[node+1];   //array of vector 

    cout<<"Enter the edges: "<<endl;
    for(int i=0; i<edge; i++)
    {
        int a,b;
        cin>>a>>b;  // take edge connected two node
        adj[a].push_back(b); // push b in array of vector which is connected with node a
        adj[b].push_back(a); // push a in array of vector which is connected with node b

    }

    cout<<"Enter the starting node: "<<endl;
    cin>>start_node; //give start node

    for(int i=0; i<=node; i++)
    {
        visit[i]=false;  //all of the boolean type array element initializing false 
    }

    queue<int>q;  //declear a int type queue
    q.push(start_node); //push start node in queue
    visit[start_node]=true; //initialize start_node true
    cout<<"BFS result: "<<endl;
    while(!q.empty())
    {
        int fr=q.front();
        q.pop();
        cout<<fr<<endl; //the front element of queue
        for(int i=0; i<adj[fr].size(); i++)
        {
            if(!visit[adj[fr][i]]) //check if the adj vector element is visited
            {
                visit[adj[fr][i]]=true;
                q.push(adj[fr][i]);
            }
        }
    }

    return 0;
}
