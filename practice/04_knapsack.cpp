#include <bits/stdc++.h>

using namespace std;

struct data{int weight, value;};

int main()
{
    int nObject, consWeight;
    while(1){
        cin>>nObject;
        if(nObject==0)
            break;

        cin>>consWeight;
        data object[600];
        for(int i=0; i<nObject; i++){
            cin>>object[i].weight>>object[i].value;
        }

        int record[100000]={0};
        for(int i=0; i<nObject; i++){
            for(int j=consWeight; j-object[i].weight>=0; j--){
                if(j-object[i].weight>=0){
                    record[j]=max(record[j], record[j-object[i].weight] + object[i].value);
                }
            }
        }
        cout<<record[consWeight]<<endl;
    }
    return 0;
}
