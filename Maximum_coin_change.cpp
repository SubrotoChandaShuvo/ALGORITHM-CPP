#include<bits/stdc++.h>
using namespace std;
int main()
{
     int co;
    cout<<"Enter the number of coin : ";
    cin>>co;
    int tk;
    cout<<"Enter the Amount of TK : ";
    cin>>tk;
    int arr[co];
    for(int i=0; i<co; i++)
    {
        cout<<"Coin number "<<i+1<<" : ";
        cin>>arr[i];
    }

    int table[co+1][tk+1];
     for (int i = 0; i <= co; i++)
    {
        table[i][0] =1;
    }
    for (int i = 1; i <= tk; i++)
    {
        table[0][i] =0;
    }
     for(int i=1; i<=co; i++)
    {
        for(int j=1; j<=tk; j++)
        {
            if(arr[i-1]>j)
            table[i][j]=table[i-1][j];
            else
               table[i][j]=(table[i-1][j]+table[i][j-arr[i-1]]);
        
        }
      
    }
     cout<<endl<<"THE MAXIMUM COIN CHANGE : "<<table[co][tk]<<endl;
    for(int i=0; i<=co; i++)
    {
        for(int j=0; j<=tk; j++)
        {
            cout<<table[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
