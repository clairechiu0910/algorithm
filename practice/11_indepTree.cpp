#include <bits/stdc++.h>

using namespace std;

struct data{int parent, value, outdegree, choose, notChoose;};

int main()
{
    int ncase;
    cin>>ncase;
    while(ncase--){
        int nNOde;
        cin>>nNOde;

        data node[nNOde+1];
        for(int i=0; i<=nNOde; i++)
            node[i].notChoose=node[i].outdegree=0;

        node[1].parent=-1;
        cin>>node[1].value;
        node[1].choose=node[1].value;
        for(int i=2; i<=nNOde; i++){
            cin>>node[i].parent>>node[i].value;
            node[i].choose=node[i].value;
            node[node[i].parent].outdegree++;
        }

        queue<int> leaf;
        for(int i=1; i<=nNOde; i++){
            if(node[i].outdegree==0)
                leaf.push(i);
        }

        while(!leaf.empty()){
            int tmp=leaf.front();
            int parent=node[tmp].parent;
            leaf.pop();

            node[parent].choose+=node[tmp].notChoose;
            node[parent].notChoose+=max(node[tmp].notChoose, node[tmp].choose);

            node[parent].outdegree--;
            if(node[parent].outdegree==0)
                leaf.push(parent);
        }
        cout<<max(node[1].choose, node[1].notChoose)<<endl;
    }
    return 0;
}
