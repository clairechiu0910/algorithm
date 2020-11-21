#include <iostream>

using namespace std;

int main()
{
    int line=0;
    while(1){
        int ncase;
        cin>>ncase;
        if(ncase==0)
            break;
        if(line++!=0)
            cout<<endl;

        int value, pick=0, unPick=0, tmpPick=0, tmpUnPick=0;
        while(ncase--){
            cin>>value;
            tmpUnPick=max(pick, unPick);
            tmpPick=unPick+value;

            pick=tmpPick;
            unPick=tmpUnPick;
            //cout<<pick<<" "<<unPick<<endl;
        }
        cout<<max(pick, unPick);
    }
    return 0;
}
