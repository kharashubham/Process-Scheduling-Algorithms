#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int main()
{
    int n, r, val;
    int max[10][10], allocated[10][10], need[10][10];
    int ava[10], temp[10], ans[10];
    cout<<"Enter the no. of Processes : ";
    cin>>n;
    cout<<"Enter the no. of Resources : ";
    cin>>r;
    cout<<"Enter the resources allocated to each process :\n ";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < r; j++)
        {
            cin>>val;
            allocated[i][j] = val;
        }
    }
    cout<<endl;
    cout<<"Enter the maximum resources required  by each process :\n ";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < r; j++)
        {
            cin>>val;
            max[i][j] = val;
            need[i][j] = (max[i][j] - allocated[i][j]);
        }
    }
    cout<<endl;
    cout<<"Resources required by each process are : \n\n";
    for (int i = 1; i <= r; i++)
        cout<<"\t\t"<<"R"<<i;
    cout<<"\n";
    for (int i = 0; i < n; i++)
    {
        cout<<"P"<<i+1<<"\t\t";
        for (int j = 0; j < r; j++)
        {
            cout<<need[i][j]<<"\t\t";
        }
        cout<<"\n";
    }
    cout<<"\n\nEnter the available resources : ";
    for (int j = 0; j  < r; j++)
    {
        cin>>val;
        ava[j]=(val);
    }
    cout<<endl;
    int fg = 0, pr = n, temp2 = 0;
    int c = 0;
    while (pr)
    {
    for (int i = 0; i < n; i++)
    {
        fg = temp2 = 0;
        for (int j = 0; j  < r; j++)
        {
            if (need[i][j] <= ava[j])
            {
                temp2 += temp[j] = need[i][j];
                if(j == r-1 && temp2 != 0)
                    fg = 1;
            }
            else
                break;
        }
        if (fg == 1)
        {
            ans[c] = i+1;
            c++;
            pr--;
            for (int k = 0; k  < r; k++)
            {
                need[i][k] = 0;
                ava[k] += temp[k];
            }
            memset(temp,0,sizeof(temp));
        }
    }
    }
    cout<<endl;
    cout<<"Safe sequence is : ";
    for (int i = 0; i < n; i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<"\n\n";
    return 0;
}
