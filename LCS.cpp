#include <bits/stdc++.h>
using namespace std;
int main()
{
    string a, b;
    cin >> a >> b;
    int al = a.size();
    int bl = b.size();
    // cout<<al<<" "<<bl<<endl;
    int table[al + 1][bl + 1];
    for (int i = 0; i <= al; i++)
    {
        table[i][0] = 0;
    }
    for (int i = 0; i <= bl; i++)
    {
        table[0][i] = 0;
    }
    for (int i = 1; i <= al; i++)
    {
        for (int j = 1; j <= bl; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                table[i][j] = (table[i - 1][j - 1] + 1);
                // cout<<table[i][j]<<endl;
            }
            else
            {
                if (table[i - 1][j] >= table[i][j - 1])
                    table[i][j] = table[i - 1][j];
                else
                    table[i][j] = table[i][j - 1];
            }
        }
    }
    cout << "Length: " << table[al][bl] << endl;
    for (int i = 0; i <= al; i++)
    {
        for (int j = 0; j <= bl; j++)
        {
            cout << table[i][j] << " ";
        }
        cout << endl;
    }
    int i = al, j = bl;
    int n = table[al][bl];
    char arr[n];

    int k = 0;
    while (i > 0 && j > 0)
    {
        if (table[i][j] == table[i - 1][j - 1] + 1)
        {
            // cout<<a[i-1]<<" ";
            arr[k]=a[i-1];
            k++;
            i--;
            j--;
        }
        else if (table[i][j] == table[i - 1][j])
        {
            i--;
        }
        else
            j--;
    }
    for(int i=n-1; i>=0; i--)
    {
        cout<<arr[i]<<" ";
    }
}
