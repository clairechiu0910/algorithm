#include <bits/stdc++.h>

using namespace std;

struct data{int a, b, weight;};

data edge[500000];
int parent[10000];

int cmp(const void *a, const void *b){
    return ((data *) a)->weight - ((data *) b)->weight;
}

int find(int a){
    while(parent[a]!=a)
        a=parent[a];
    return a;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    int tcase;
    scanf("%d", &tcase);
    while(tcase--){
        int nnode, medge, parA, parB, sum=0;
        scanf("%d%d", &nnode, &medge);
        for(int i=0; i<nnode; i++)
            parent[i]=i;
        for(int i=0; i<medge; i++)
            scanf("%d%d%d", &edge[i].a, &edge[i].b, &edge[i].weight);

        qsort(edge, medge, sizeof(data), cmp);
        //for(int i=0; i<medge; i++)
            //cout<<edge[i].a<<edge[i].b<<edge[i].weight<<endl;

        for(int i=0, count=0; i<medge && count<nnode-1; ++i){
            parA=find(edge[i].a);
            parB=find(edge[i].b);
            if(parA==parB)
                continue;

            parent[parB]=parA;
            sum+=edge[i].weight;
            count++;
        }
        cout<<sum<<endl;
    }
    return 0;
}
