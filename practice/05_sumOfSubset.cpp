#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tcase;
    cin>>tcase;
    while(tcase--){
        int nWeight, mObject, tmp, ans=0, sum=0;
        cin>>nWeight>>mObject;

        bool can[200000]={0};
        for(int i=0; i<nWeight; i++){
            cin>>tmp;
            for(int j=sum; j>=0; j--){
                if(can[j])
                    can[j+tmp]=true;
            }
            sum+=tmp;
            can[tmp]=true;
        }
        for(int i=0; i<mObject; i++){
            cin>>tmp;
            if(can[tmp])
                ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
