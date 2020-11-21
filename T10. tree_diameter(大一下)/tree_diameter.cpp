#include <bits/stdc++.h>

using namespace std;

struct data{int parent, height, outdegree;};
//if index is root, the height of the tree

int main()
{
    //the root can't be push in the queue
    int tcase;
    cin>>tcase;
    while(tcase--){
        int nNode, parent, child;
        cin>>nNode;
        data node[nNode];
        for(int i=0; i<nNode; i++){
            node[i].parent=-1;
            node[i].height=0;
            node[i].outdegree=0;
        }
        for(int i=0; i<nNode-1; i++){
            cin>>parent>>child;
            node[child].parent=parent;
            node[parent].outdegree++;
        }

        std::queue <int> leaf;
        int diameter=0, tmp, tmpPar;
        for(int i=0; i<nNode; i++){
            if(node[i].outdegree==0)
                leaf.push(i);
        }
        while(!leaf.empty()){
            tmp=leaf.front();
            leaf.pop();
            tmpPar=node[tmp].parent;
            if(node[tmpPar].height <= node[tmp].height+1){
                if(diameter < node[tmp].height+1 + node[tmpPar].height){
                    diameter = node[tmp].height+1 + node[tmpPar].height;
                }
                node[tmpPar].height = node[tmp].height+1;
            }
            node[tmpPar].outdegree--;
            if(node[tmpPar].outdegree==0 && node[tmpPar].parent!=-1)
                leaf.push(tmpPar);
            //cout<<tmp<<" "<<node[tmp].height<<" diameter="<<diameter<<endl;
        }
        cout<<diameter;
        if(tcase)
            cout<<endl;
    }
    return 0;
}
