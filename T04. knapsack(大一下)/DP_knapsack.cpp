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
        int test[cWeight+1]={0};  //�o�ӭ��q���W���ɪ��̰�value
        for(int i=0; i<number; i++)
            cin>>weight[i]>>value[i];
        for(int i=0; i<number; i++){  //�ݨC�@�Ӫ��~�i���i�H��i�h
            for(int j=cWeight; j>=0; j--){  //���C�@�ӭ��q���W�����ɭ�
                if(j-weight[i]>=0){  //this item can be put in  //�b�o�ӭ��q���ɭԳo�Ӫ��~�i�H��i�h
                    //cout<<test[j]<<' '<<test[j-weight[i]]+value[i]<<endl;
                    test[j]=max(test[j], (test[j-weight[i]]+value[i]));  //max(�S����J���̰�value, �[�W�o�Ӫ��~�ɪ��̰�value)
                }
            }
        }
        cout<<test[cWeight];
    }
    return 0;
}
