#include <bits/stdc++.h>

using namespace std;

struct data{int height, parent, outdegree;};

int main()
{
    int tcase;
    cin>>tcase;
    while(tcase--){
        int nnode, parent, child;
        cin>>nnode;
        data node[nnode];
        for(int i=0; i<nnode; i++){
            node[i].height=node[i].outdegree=0;
            node[i].parent=-1;
        }
        for(int i=1; i<nnode; i++){
            cin>>parent>>child;
            node[child].parent=parent;
            node[parent].outdegree++;
        }

        queue<int> leaf;
        int diameter=0;
        for(int i=0; i<nnode; i++){
            if(node[i].outdegree==0)
                leaf.push(i);
        }
        while(!leaf.empty()){
            int tmp=leaf.front();
            leaf.pop();
            int tmpPar=node[tmp].parent;

            if(diameter < node[tmp].height+1+node[tmpPar].height)
                diameter = node[tmp].height+1+node[tmpPar].height;
            if(node[tmpPar].height <= node[tmp].height+1){
                node[tmpPar].height=node[tmp].height+1;
            }
            node[tmpPar].outdegree--;
            if(node[tmpPar].outdegree==0 && node[tmpPar].parent!=-1)
                leaf.push(tmpPar);
            //cout<<tmp<<' '<<node[tmp].height<<' '<<diameter<<endl;
        }
        cout<<diameter<<endl;
    }
    return 0;
}
