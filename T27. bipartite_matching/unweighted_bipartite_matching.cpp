#include <bits/stdc++.h>

using namespace std;

vector< vector<int> > edge;
int xMatch[1000], yMatch[1000];
bool yDone[1000];

bool dfs(int x)
{
    int y, size=edge[x].size();
    for(int i=0; i<size; i++){
        y=edge[x][i];
        if(yDone[y] == false){
            yDone[y]=true;
            if(yMatch[y]==-1 || dfs(yMatch[y])){
                yMatch[y]=x;
                xMatch[x]=y;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    int ncase;
    scanf("%d", &ncase);
    while(ncase--){
        int x, y, mEdge, a, b;
        scanf("%d%d%d", &x, &y, &mEdge);

        for(int i=0; i<x; i++)  xMatch[i]=-1;
        for(int i=0; i<y; i++)  yMatch[i]=-1;
        edge.clear();
        edge.resize(x);
        for(int i=0; i<mEdge; i++){
            scanf("%d%d", &a, &b);
            edge[a].push_back(b);
        }

        int ans=0;
        for(int i=0; i<x; i++){
            for(int j=0; j<y; j++)
                yDone[j]=false;
            if(dfs(i)) ans++;
        }
        //getchar();
        /*for(int i=0; i<x; i++)
            cout<<xMatch[i]<<' ';
        cout<<endl;
        for(int i=0; i<y; i++)
            cout<<xMatch[i]<<' ';
        cout<<endl;*/S
        cout<<ans<<endl;
    }
    return 0;
}
