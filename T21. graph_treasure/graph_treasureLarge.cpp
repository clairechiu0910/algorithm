#include <bits/stdc++.h>

using namespace std;

int graph[5000][5000];
int main()
{
    //freopen("graph_treasureLarge.in", "r", stdin);
    while(1){
        int nCity, mRoad, tStart;
        scanf("%d%d%d", &nCity, &mRoad, &tStart);
        if(nCity==0 || mRoad==0 || tStart==0)
            break;
        int from, to;
        int value[5000], start[200], done[5000];
        for(int i=0; i<nCity; i++){
            for(int j=0; j<nCity; j++)
                graph[i][j]=0;
            done[i]=0;
        }

        for(int i=0; i<tStart; i++)
            scanf("%d", &start[i]);
        for(int i=0; i<nCity; i++)
            scanf("%d", &value[i]);
        for(int i=0; i<mRoad; i++){
            scanf("%d%d", &from, &to);
            graph[from][to]=1;
        }

        int max=0;
        for(int i=0; i<tStart; i++){
            queue<int> que;
            int tmp;

            if(done[start[i]]==0){
                que.push(start[i]);
                done[start[i]]=1;
                while(!que.empty()){
                    tmp=que.front();
                    que.pop();
                    if(value[tmp]>max)
                        max=value[tmp];

                    for(int j=0; j<nCity; j++){
                        if(graph[tmp][j] && done[j]==0){
                            //cout<<tmp<<"-"<<j<<endl;
                            que.push(j);
                            done[j]=1;
                        }
                    }
                }
            }
        }
        cout<<max<<endl;
    }
    return 0;
}
