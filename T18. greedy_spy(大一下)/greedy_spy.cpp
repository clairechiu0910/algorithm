#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int tCase;
    cin>>tCase;
    while(tCase--){
        int nSpy, sum=0;
        cin>>nSpy;
        int leader[nSpy], phone[nSpy];
        leader[0]=-1;
        phone[0]=0;
        for(int i=1; i<nSpy; i++){
            cin>>leader[i];
            phone[i]=0;
        }

        for(int i=nSpy-1; i>0; i--){
            if(phone[i]==0){
                phone[leader[i]]=1;
            }
        }
        for(int i=0; i<nSpy; i++){
            if(phone[i])
                sum++;
        }
        cout<<sum;
        if(tCase)
            cout<<endl;
    }
    return 0;
}
