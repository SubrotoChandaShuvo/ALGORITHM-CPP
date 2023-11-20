#include<bits/stdc++.h>
using namespace std;
int main()
{
    priority_queue<int>q;
    //priority_queue<int, vector<int>, greater<>> q;
    //priority_queue<int, vector<int>,greater<>> q;
    int n;
    cin>>n;
    
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
       q.push(x);
    }
    while(!q.empty())
    {
        int a=q.top();
        cout<<a<<endl;
        q.pop();
    }
    return 0;
}
