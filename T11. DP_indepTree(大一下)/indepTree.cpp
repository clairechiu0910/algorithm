#include <bits/stdc++.h>

using namespace std;

struct data{int weight, parent, outdegree, choose, notChoose;};

int main()
{
    int tcase;
    cin>>tcase;
    while(tcase--){
        int nnode;
        cin>>nnode;
        data node[nnode+1];
        for(int i=0; i<nnode+1; i++){
            node[i].weight=node[i].outdegree=node[i].choose=node[i].notChoose=0;
            node[i].parent=-1;
        }
        cin>>node[1].weight;
        node[1].choose=node[1].weight;

        for(int i=2; i<nnode+1; i++){
            cin>>node[i].parent>>node[i].weight;
            node[node[i].parent].outdegree++;
            node[i].choose=node[i].weight;
        }

        queue<int> leaf;
        for(int i=2; i<nnode+1; i++)
            if(node[i].outdegree==0)
                leaf.push(i);
        while(!leaf.empty()){
            int tmp=leaf.front();
            leaf.pop();
            int tmpPar=node[tmp].parent;

            node[tmpPar].choose+=node[tmp].notChoose;
            node[tmpPar].notChoose+=max(node[tmp].choose, node[tmp].notChoose);
            //cout<<tmpPar<<' '<<node[tmpPar].choose<<' '<<node[tmpPar].notChoose<<endl;

            node[tmpPar].outdegree--;
            if(node[tmpPar].outdegree==0 && node[tmpPar].parent!=-1)
                leaf.push(tmpPar);
        }
        cout<<max(node[1].choose, node[1].notChoose)<<endl;
    }
    return 0;
}
