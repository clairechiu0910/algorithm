#include <bits/stdc++.h>
#define INF 1000000
using namespace std;

int dist[1500][1500];

int main()
{
    //freopen("in.txt", "r", stdin);
    int tcase;
    cin>>tcase;
    while(tcase--){
        int nNode, mEdge;
        scanf("%d%d", &nNode, &mEdge);

        int u, v;
        for(int i=0; i<nNode; i++){
            for(int j=0; j<nNode; j++){
                if(i==j)
                    dist[i][j]=0;
                else
                    dist[i][j]=INF;
            }
        }
        for(int i=0; i<mEdge; i++){
            scanf("%d%d", &u, &v);
            scanf("%d", &dist[u][v]);
        }

        for(int k=0; k<nNode; ++k){
            for(int i=0; i<nNode; ++i){
                for(int j=0; j<nNode; ++j){
                    dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
                }
            }
        }

        int sum[nNode];
        for(int i=0; i<nNode; i++){
            sum[i]=0;
            for(int j=0; j<nNode; j++){
                sum[i]+=dist[i][j];
            }
        }

        int index, min=INF;
        for(int i=0; i<nNode; i++){
            if(sum[i]<min){
                min=sum[i];
                index=i;
            }
        }
        cout<<index<<endl;
    }
    return 0;
}
