#include <bits/stdc++.h>

using namespace std;

struct data{ int start, end, weight;};

int cmp(const void *a, const void *b)
{
    return ((data *)a)->end - ((data *)b)->end;
}

int binarySearch(const data line[], const int& index) //find the largest j line[j] < line[index]
{
    int low=0, high=index-1, mid;
    while(low<=high){
        mid=(low+high)/2;
        if(line[mid].end <= line[index].start){
            if(line[mid+1].end <= line[index].start)
                low=mid+1;
            else
                return mid;
        }
        else
            high=mid-1;
    }
    return -1;
}

int main()
{
    int tcase;
    cin>>tcase;
    while(tcase--){
        int nInterval, i;
        cin>>nInterval;
        data line[nInterval];
        for(i=0; i<nInterval; ++i)
            cin>>line[i].start>>line[i].end>>line[i].weight;

        qsort(line, nInterval, sizeof(data), cmp);

        int DP[nInterval];
        DP[0]=line[0].weight;
        for(i=1; i<nInterval; ++i){
            int choose=line[i].weight;
            int pre=binarySearch(line, i);
            if(pre!=-1)
                choose+=DP[pre];
            DP[i]=max(DP[i-1], choose);
        }

        cout<<DP[nInterval-1];
        if(tcase)
            cout<<endl;
    }
    return 0;
}
