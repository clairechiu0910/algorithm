#include <iostream>
#include <cstdlib>

using namespace std;

struct interval{unsigned int x, y;};

int cmp(const void *a, const void *b)
{
    if(((interval *)a)->x == ((interval *)b)->x)
        return ((interval *)b)->y - ((interval *)a)->y; //large to small
    return ((interval *)a)->x - ((interval *)b)->x;  //small to large
}
int main()
{
    int ncase;
    cin>>ncase;
    while(ncase--){
        int mSeg;
        cin>>mSeg;
        interval line[mSeg];
        for(int i=0; i<mSeg; i++)
            cin>>line[i].x>>line[i].y;

        qsort(line, mSeg, sizeof(interval), cmp);

        //remember unsigned and long long
        unsigned int start=line[0].x, end=line[0].y;
        long long sum=0;
        for(int i=1; i<mSeg; i++){
            if(line[i].x==start)
                continue;
            if(line[i].x>end){
                sum+=end-start;
                start=line[i].x;
                end=line[i].y;
            }
            else{
                if(line[i].y > end)
                    end=line[i].y;
            }
        }
        sum+=end-start;
        cout<<sum;
        if(ncase)
            cout<<endl;
    }
    return 0;
}
