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
        int test[cWeight+1]={0};  //硂秖程蔼value
        for(int i=0; i<number; i++)
            cin>>weight[i]>>value[i];
        for(int i=0; i<number; i++){  //–珇ぃ秈
            for(int j=cWeight; j>=0; j--){  //代–秖
                if(j-weight[i]>=0){  //this item can be put in  //硂秖硂珇秈
                    //cout<<test[j]<<' '<<test[j-weight[i]]+value[i]<<endl;
                    test[j]=max(test[j], (test[j-weight[i]]+value[i]));  //max(⊿Τ程蔼value, 硂珇程蔼value)
                }
            }
        }
        cout<<test[cWeight];
    }
    return 0;
}
