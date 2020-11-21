#include <bits/stdc++.h>

using namespace std;

//struct data{int weight, parent, sum;};
//data node[50000];

int weight[50000], parent[50000];

int findChange(int a){
    int root=a, tmp;
    while(parent[root]>=0)
        root=parent[root];
    //cout<<"root="<<root<<endl;
    while(parent[a]>0){
        tmp=parent[a];
        parent[a]=root;
        a=tmp;
    }
    return root;
}

int main()
{
    int tcase;
    scanf("%d", &tcase);
    while(tcase--){
        int nNode, mEdge;
        scanf("%d%d", &nNode, &mEdge);
        for(int i=0; i<nNode; i++){
            scanf("%d", &weight[i]);
            parent[i]=-1;
        }

        for(int i=0; i<mEdge; i++){
            int a, b;
            scanf("%d%d", &a, &b);

            a=findChange(a);
            b=findChange(b);
            //cout<<a<<'\t'<<b<<endl;
            if(a!=b){
                weight[a]+=weight[b];
                parent[b]=a;
            }
        }
        int ans=0;
        for(int i=0; i<nNode; i++){
            if(weight[i]>ans)
                ans=weight[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}
