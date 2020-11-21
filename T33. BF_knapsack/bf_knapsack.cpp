#include <bits/stdc++.h>

using namespace std;

struct data{int value, weight;};

int nItem, leastItem, wa, wb, sum;
data item[25];

void find(int count, int taken, int sumValue, int sumWeight)
{
    if(sumWeight>wb) return;
    if(count == nItem){
        if(taken>leastItem && sumWeight>wa){
            int avgValue = sumValue/sumWeight;
            if(avgValue*sumWeight != sumValue) avgValue++;
            if(avgValue>sum) sum=avgValue;
        }
        return;
    }
    find(count+1, taken+1, sumValue+item[count].value, sumWeight+item[count].weight);
    find(count+1, taken, sumValue, sumWeight);

}

int main()
{
    int finish;
    while(finish!=-1){
        scanf("%d%d%d%d", &nItem, &leastItem, &wa, &wb);
        for(int i=0; i<nItem; i++)
            scanf("%d%d", &item[i].value, &item[i].weight);

        sum=-1;
        find(0, 0, 0, 0);
        cout<<sum<<endl;
        cin>>finish;
    }
    return 0;
}
