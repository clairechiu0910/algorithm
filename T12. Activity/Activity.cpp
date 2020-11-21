#include <bits/stdc++.h>

using namespace std;

struct interval{int x, y;};

int cmp(const void *a, const void *b)
{
    return ((interval *)a)->y - ((interval *)b)->y;
}

int main()
{
    int ncase;
    cin>>ncase;
    while(ncase--){
        int mseg, end, ans=1;
        cin>>mseg;
        interval time[mseg];
        for(int i=0; i<mseg; i++){
            cin>>time[i].x>>time[i].y;
            if(time[i].x>time[i].y)
                swap(time[i].x, time[i].y);
        }

        qsort(time, mseg, sizeof(interval), cmp);

        end=time[0].y;
        for(int i=1; i<mseg; i++){
            if(time[i].x>=end){
                ans++;
                end=time[i].y;
            }
        }

        cout<<ans;
        if(ncase)
            cout<<endl;
    }
    return 0;
}
