#include <iostream>

using namespace std;

int main()
{
    int ncase;
    cin>>ncase;
    while(ncase--){
        int nWeight, mObject, weight, object, sum=0, count=0;
        cin>>nWeight>>mObject;
        int can[300000]={0};
        for(int i=0; i<nWeight; i++){
            cin>>weight;
            for(int j=sum; j>=0; j--){
                if(can[j])
                    can[j+weight]=1;
            }
            can[weight]=1;
            sum+=weight;
        }
        for(int i=0; i<mObject; i++){
            cin>>object;
            if(can[object])
                count++;
        }
        cout<<count;
        if(ncase)
            cout<<endl;
    }
    return 0;
}
