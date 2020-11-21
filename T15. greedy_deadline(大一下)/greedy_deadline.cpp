#include <iostream>
#include <cstdlib>

using namespace std;

struct jobStruct
{
    int time, deadline;
};

int cmp(const void *a, const void *b)
{
    return ((jobStruct*)a)->deadline - ((jobStruct*)b)->deadline;
}

int main()
{
    int tcase;
    cin>>tcase;
    while(tcase--){
        int nJob;
        bool ans=1;
        cin>>nJob;
        jobStruct jobs[nJob];
        long long int time=0;

        for(int i=0; i<nJob; i++)
            cin>>jobs[i].time;
        for(int i=0; i<nJob; i++)
            cin>>jobs[i].deadline;

        qsort(jobs, nJob, sizeof(jobStruct), cmp);
        for(int i=0; i<nJob && ans; i++){
            time+=jobs[i].time;
            if(jobs[i].deadline<time)
                ans=0;
        }
        if(ans)
            cout<<"Yes";
        else
            cout<<"No";
        if(tcase)
            cout<<endl;
    }
    return 0;
}
