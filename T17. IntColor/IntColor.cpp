#include <bits/stdc++.h>

using namespace std;

struct interval{int x, y;};

int cmp(const void *a, const void *b)
{
    return ((interval *)a)->x - ((interval *)b)->x;
}

int main()
{
    int ncase;
    cin>>ncase;
    while(ncase--){
        int mseg;
        cin>>mseg;
        interval time[mseg];
        for(int i=0; i<mseg; i++){
            cin>>time[i].x>>time[i].y;
            if(time[i].x>time[i].y)
                swap(time[i].x, time[i].y);
        }

        qsort(time, mseg, sizeof(interval), cmp);

        std::priority_queue <int> timeEnd;
        int color=0, point=time[0].x, tmp;
        timeEnd.push(time[0].y*(-1));
        for(int i=1; i<mseg; i++){
            point=time[i].x;
            timeEnd.push(time[i].y*(-1));
            while(1){
                tmp=timeEnd.top()*(-1);
                //cout<<"tmp="<<tmp<<" point="<<point<<endl;
                if(tmp<point){
                    timeEnd.pop();
                    //cout<<"delete: tmp="<<tmp<<" point="<<point<<endl;
                }
                else
                    break;
            }
            if(timeEnd.size()>color)
                color=timeEnd.size();
        }
        cout<<color;
        if(ncase)
            cout<<endl;
    }
    return 0;
}
