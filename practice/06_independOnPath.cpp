#include <bits/stdc++.h>

using namespace std;

int main()
{
    while(1){
        int ncase;
        cin>>ncase;
        if(ncase==0)
            break;

        int tmp, choose=0, notChoose=0, tmpChoose, tmpNot;
        for(int i=0; i<ncase; i++){
            cin>>tmp;
            tmpChoose=tmp+notChoose;
            tmpNot=max(choose, notChoose);

            choose=tmpChoose;
            notChoose=tmpNot;
        }
        cout<<max(choose, notChoose)<<endl;
    }
    return 0;
}
