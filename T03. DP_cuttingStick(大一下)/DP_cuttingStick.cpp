#include <iostream>

using namespace std;

int table[1000][1000], cutPlace[100];

int Cutting(int i, int j, int nCut)
{
    //cout<<"i="<<i<<" j="<<j<<" table="<<table[i][j]<<endl;
    if(table[i][j]!=-1)
        return table[i][j];
    int cost, mincost=1000000;
    for(int k=0; k<nCut; k++){
        if(cutPlace[k]<=i)
            continue;
        if(cutPlace[k]>=j)
            break;
        cost=Cutting(i, cutPlace[k], nCut) + Cutting(cutPlace[k], j, nCut);
        if(cost<mincost)
            mincost=cost;
    }
    if(mincost==1000000){
        table[i][j]=0;
        //cout<<"after: i="<<i<<" j="<<j<<" table="<<table[i][j]<<endl;
        return 0;
    }
    mincost+=j-i;
    table[i][j]=mincost;
    //cout<<"after: i="<<i<<" j="<<j<<" table="<<table[i][j]<<endl;
    return mincost;
}

int main()
{
    int length, line=0;
    while(1){
        cin>>length;
        if(length==0)
            break;
        if(line++!=0)
            cout<<endl;

        int nCut;
        for(int i=0; i<=length; i++)
            for(int j=0; j<=length; j++)
                table[i][j]=-1;

        cin>>nCut;
        for(int i=0; i<nCut; i++)
            cin>>cutPlace[i];
        cout<<"The minimum cutting is "<<Cutting(0, length, nCut)<<".";
    }
    return 0;
}
