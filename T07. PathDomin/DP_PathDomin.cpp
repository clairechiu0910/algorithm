#include <bits/stdc++.h>

using namespace std;

struct data{int value, choose;};

int main()
{
    int nInteger, line=0;
    while(1){
        cin>>nInteger;
        if(nInteger==0)
            break;
        if(line++!=0)
            cout<<endl;

        data integer[nInteger];
        for(int i=0; i<nInteger; i++)
            cin>>integer[i].value;

        integer[0].choose=integer[0].value;
        integer[1].choose=integer[1].value;
        integer[2].choose=min(integer[0].choose, integer[1].choose) + integer[2].value;
        for(int i=3; i<nInteger; i++){
            integer[i].choose=min(integer[i-3].choose, integer[i-2].choose);
            integer[i].choose=min(integer[i].choose, integer[i-1].choose);
            integer[i].choose+=integer[i].value;
            //cout<<"i="<<i<<" choose="<<integer[i].choose<<endl;
        }

        cout<<min(integer[nInteger-1].choose, integer[nInteger-2].choose);
    }
    return 0;
}
