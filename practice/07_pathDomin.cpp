#include <bits/stdc++.h>

using namespace std;

int main()
{
    int ncase;
    while(1){
        cin>>ncase;
        if(ncase==0)
            break;

        int element[ncase]={0}, sum[ncase]={0};
        for(int i=0; i<ncase; i++){
            cin>>element[i];
        }
        sum[0]=element[0];
        sum[1]=element[1];
        sum[2]=min(sum[0], sum[1])+element[2];
        for(int i=3; i<ncase; i++){
            sum[i]=min(sum[i-3], sum[i-2]);
            sum[i]=min(sum[i-1], sum[i]);
            sum[i]+=element[i];
        }
        cout<<min(sum[ncase-1], sum[ncase-2])<<endl;
    }
    return 0;
}
