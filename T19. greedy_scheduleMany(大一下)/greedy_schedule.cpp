#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tCase;
    cin>>tCase;
    while(tCase--){
        int nJobs, mMachines, time, tmpTime;
        cin>>nJobs>>mMachines;
        std::priority_queue <int> run; //big to small
        for(int i=0; i<mMachines; i++)
            run.push(0);
        for(int i=0; i<nJobs; i++){
            cin>>time;
            tmpTime=run.top();
            run.pop();
            tmpTime-=time;
            run.push(tmpTime);
            //cout<<tmpTime;
        }
        while(!run.empty()){
            tmpTime=run.top();
            run.pop();
        }
        cout<<tmpTime*(-1);
        if(tCase)
            cout<<endl;
    }
    return 0;
}
