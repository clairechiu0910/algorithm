#include <iostream>

using namespace std;

int main()
{
    int line=0;
    while(1){
        int number, cWeight;
        cin>>number;
        if(number==0)
            break;
        if(line++!=0)
            cout<<endl;
        cin>>cWeight;

        int value[number]={0}, weight[number]={0};
        int test[cWeight+1]={0};  //這個重量為上限時的最高value
        for(int i=0; i<number; i++)
            cin>>weight[i]>>value[i];
        for(int i=0; i<number; i++){  //看每一個物品可不可以放進去
            for(int j=cWeight; j>=0; j--){  //測每一個重量為上限的時候
                if(j-weight[i]>=0){  //this item can be put in  //在這個重量的時候這個物品可以放進去
                    //cout<<test[j]<<' '<<test[j-weight[i]]+value[i]<<endl;
                    test[j]=max(test[j], (test[j-weight[i]]+value[i]));  //max(沒有放入的最高value, 加上這個物品時的最高value)
                }
            }
        }
        cout<<test[cWeight];
    }
    return 0;
}
