#include<bits/stdc++.h>

using namespace std;

int mx=0;

int r,c;

pair<int,int>moved[]={ {-1,-1}, {-1,0} , {-1,1} , {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1} };

bool issafe(int x,int y)

{

    if(x>=0&&x<r &&y>=0 &&y<c)

    {
        return true;
    }

    return false;

}

void dfs(int i,int j,int &cnt,vector<vector<int>>&adj,vector<vector<bool>>&vis)

{

    vis[i][j]=true;

    for(int k=0;k<8;k++)

    {

        int n_i=i+moved[k].first;

        int n_j=j+moved[k].second;

        if(issafe(n_i,n_j) && adj[n_i][n_j]==1 && vis[n_i][n_j]==false)

        {

            cnt++;

            dfs(n_i,n_j,cnt,adj,vis);

        }

    }

}

int main()

{

    cin>>r>>c;

    vector<vector<int>>adj(r,vector<int>(c));

    for(int i=0;i<r;i++)

    {

        for(int j=0;j<c;j++)

        {

            cin>>adj[i][j];

        }

    }

    vector<vector<bool>>vis(r,vector<bool>(c,false));

    for(int i=0;i<r;i++)

    {

        for(int j=0;j<c;j++)

        {

            if(vis[i][j]==false && adj[i][j]==1)

            {

                int cnt=1;

                dfs(i,j,cnt,adj,vis);

                mx=max(mx,cnt);

            }

        }

    }

    cout<<mx<<"\n";

}
