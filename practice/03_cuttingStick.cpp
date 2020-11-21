#include <bits/stdc++.h>

using namespace std;

vector <int> num;
int table[1000][1000];

int cost(int x, int y)
{
    if(table[x][y]!=0)
        return table[x][y];
    int minCost=1000000, tmpCost, count=num.size();
    for(int i=0; i<count; i++){
        if(num[i]>x && num[i]<y){
            tmpCost=cost(x, num[i]) + cost(num[i], y);
            if(tmpCost<minCost)
                minCost=tmpCost;
        }
        if(num[i]>y)
            break;
    }
    if(minCost==1000000){
        table[x][y]=0;
        return 0;
    }
    minCost+=y-x;
    table[x][y]=minCost;
    return minCost;
}

int main()
{
    int length;
    while(1){
        cin>>length;
        if(length==0)
            break;

        for(int i=0; i<1000; i++){
            for(int j=0; j<1000; j++)
                table[i][j]=0;
        }
        num.clear();

        int tmp, count;
        cin>>count;

        for(int i=0; i<count; i++){
            cin>>tmp;
            num.push_back(tmp);
        }

        cout<<"The minimum cutting is "<<cost(0, length)<<"."<<endl;
    }
    return 0;
}
