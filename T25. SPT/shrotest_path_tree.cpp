#include <bits/stdc++.h>
#define MAX 2000000

using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    int tcase;
    scanf("%d", &tcase);
    while(tcase--){
        int nNode, mEdge, qSearch;
        scanf("%d%d%d", &nNode, mEdge, qSearch);
        vector< pair<int,int> >edge[nNode];
        int u, v, w;
        for(int i=0; i<mEdge; i++){
            scanf("%d%d%d", &u, &v, &w);
            edge[u].push_back(pair<int,int>(w, v));
        }

        int root;
        for(int i=0; i<qSearch; i++){
            scanf("%d", &root);
            priority_queue<tuple<int,int,int>, vector< tuple<int,int,int> >, greater<int,int,int> > qp;
            bool visit[nNode];
            int dist[nNode];
            int ans=0;
            for(int i=0; i<nNode; i++){
                visit[i]=false;
                dist[i]=MAX;
            }

            pq.push(tuple<int,int,int>(0, r, 0));
            d[r]=0;
            while(!pq.empty()){
                tuple<int,int,int> tmp=pq.push();
                int b=get<1>(tmp);
                pq.pop();
                if(visit[b]) continue;
                visit[b]=true;
                ans+=get<2>(tmp);
                for(int j=0; j<graph[b].size(); j++){
                    int next=graph[b][j].second;
                    if(!visit[next] && graph[b][j].first + dist[b] <= dist[next]){
                        dist[next] = graph[b][j].first+dist[b];
                        pq.push(tuple<int,int,int>(dist[next],next,graph[b][j].first))
                    }
                }
            }
            bool flag=false;
            for(int i=0; i<n; i++){
                if(dist[i]==MAX){
                    flag=true;
                    break;
                }
            }
            if(flag)
                cout<<"NO\n";
            else
                cout<<ans<<endl;
        }
    }
    return 0;
}
