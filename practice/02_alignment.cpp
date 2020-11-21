#include <bits/stdc++.h>

using namespace std;

int main()
{
    string a, b;
    while(getline(cin, a) != NULL){
        getline(cin, b);
        int lenA=a.size(), lenB=b.size();
        int table[500][500]={0};

        for(int i=0; i<500; i++){
            table[0][i]=(-3)*i;
            table[i][0]=(-3)*i;
        }

        for(int i=0; i<lenA; i++){
            for(int j=0; j<lenB; j++){
                if(a[i]==b[j]){
                    table[i+1][j+1]=table[i][j]+8;
                }
                else{
                    table[i+1][j+1]=max(table[i][j+1]-3, table[i+1][j]-3);
                    table[i+1][j+1]=max(table[i+1][j+1], table[i][j]-5);
                }
            }
        }

        cout<<table[lenA][lenB]<<endl;
    }
    return 0;
}
