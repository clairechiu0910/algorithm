#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tcase;
    cin>>tcase;
    while(tcase--){
        int sLength, j, len=0;
        cin>>sLength;
        unsigned int seg;
        unsigned int record[sLength];
        for(int i=0; i<sLength; i++){
            record[i]=-1;
        }

        for(int i=0; i<sLength; i++){
            cin>>seg;
            for(j=0; j<len; j++){
                if(seg <= record[j])
                    break;
            }
            if(j==len)
                record[len++]=seg;
            else
                record[j]=min(record[j], seg);
        }
        cout<<len;
        if(tcase)
            cout<<endl;
    }
    return 0;
}
