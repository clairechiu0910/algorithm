#include <bits/stdc++.h>

using namespace std;

struct data{int rate, parent, outdegree, choose, notChoose;};
int main()
{
    int tcase;
    cin>>tcase;
    while(tcase--){
        int nPeople;
        cin>>nPeople;
        data people[nPeople+1];
        for(int i=0; i<=nPeople; i++){
            people[i].choose=people[i].outdegree=people[i].notChoose=0;
            people[i].parent=people[i].rate=-1;
        }
        cin>>people[1].rate;
        people[1].choose=people[1].rate;
        for(int i=2; i<=nPeople; i++){
            cin>>people[i].parent>>people[i].rate;
            people[i].choose=people[i].rate;
            people[people[i].parent].outdegree++;
        }

        std::queue <int> leaf;
        int tmp, parent;
        for(int i=1; i<=nPeople; i++){
            if(people[i].outdegree==0)
                leaf.push(i);
        }
        while(!leaf.empty()){
            tmp=leaf.front();
            leaf.pop();
            parent=people[tmp].parent;
            people[parent].choose+=people[tmp].notChoose;
            people[parent].notChoose+=max(people[tmp].choose, people[tmp].notChoose);
            people[parent].outdegree--;

            if(people[parent].outdegree==0 && people[parent].parent!=-1)
                leaf.push(parent);
            //cout<<"tmp="<<tmp<<" parent="<<parent<<" choose:"<<people[parent].choose<<" "<<people[parent].notChoose<<endl;
        }
        cout<<max(people[1].choose, people[1].notChoose);
        if(tcase)
            cout<<endl;
    }
    return 0;
}
