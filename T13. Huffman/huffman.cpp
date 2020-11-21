#include <bits/stdc++.h>

using namespace std;

int main()
{
    int ncase;
    cin>>ncase;
    while(ncase--){
        int mSymbols, tmp, a, b;
        long long int sum=0;
        cin>>mSymbols;
        priority_queue <int> tree;
        for(int i=0; i<mSymbols; i++){
            cin>>tmp;
            tree.push(tmp*(-1));
        }
        if(tree.size()==1){
            sum+=tree.top()*(-1);
        }
        else{
            while(tree.size()!=1){
                a=tree.top()*(-1);
                tree.pop();
                b=tree.top()*(-1);
                tree.pop();

                tmp=a+b;
                sum+=tmp;
                tree.push(tmp*(-1));
                //cout<<"tmp="<<tmp<<"sum="<<sum<<endl;
            }
        }

        cout<<sum;
        if(ncase)
            cout<<endl;
    }
    return 0;
}
