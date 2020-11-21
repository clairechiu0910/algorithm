#include <bits/stdc++.h>
#define INF 1000000
using namespace std;

int dist[5000];

int main()
{
    //freopen("in.txt", "r", stdin);
    int tcase;
    cin>>tcase;
    while(tcase--){
        int nNode, mEdge, qSearch;
        scanf("%d%d%d", &nNode, &mEdge, &qSearch);
        vector< pair<int,int> > graph[nNode];
        int u, v, w;
        for(int i=0; i<mEdge; i++){
            scanf("%d%d%d", &u, &v, &w);
            graph[u].push_back(pair<int,int>(v, w));

        }
        int s, e;
        for(int i=0; i<qSearch; i++){
            scanf("%d%d", &s, &e);
            for(int i=0; i<nNode; i++){
                if(i==s)
                    dist[i]=0;
                else
                    dist[i]=INF;
            }
            for(int i=0; i<graph[s].size(); i++){
                dist[graph[s][i].first]=graph[s][i].second;
            }

            for(int k=1; k<nNode-1; k++){  //dist(k)                )
                for(int mid=0; mid<nNode; mid++){  //s->mid->fin
                    if(dist[mid] == INF) continue;
                    for(int i=0; i<graph[mid].size(); i++){
                        int fin = graph[mid][i].first;
                        dist[fin]=min(dist[fin], dist[mid]+graph[mid][i].second);
                    }
                }
            }
            /*for(int i=0; i<nNode; i++){
                cout<<dist[i]<<' ';
            }
            cout<<endl;*/
            bool nega=0;
            for(int k=1; k<nNode-1 && !nega; k++){  //dist(k)                )
                for(int mid=0; mid<nNode && !nega; mid++){  //s->mid->fin
                    if(dist[mid] == INF) continue;
                    for(int i=0; i<graph[mid].size() && !nega; i++){
                        int fin = graph[mid][i].first;
                        if(dist[fin]>dist[mid]+graph[mid][i].second){
                            dist[fin]=dist[mid]+graph[mid][i].second;
                            if(fin==e) nega=1;
                        }
                    }
                }
            }
            /*for(int i=0; i<nNode; i++){
                cout<<dist[i]<<' ';
            }
            cout<<endl;
            cout<<"nega="<<nega<<endl;*/
            if(dist[e]==INF || nega)
                printf("no\n");
            else
                printf("%d\n", dist[e]);
        }
    }
    return 0;
}
