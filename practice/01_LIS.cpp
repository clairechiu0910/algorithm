#include <bits/stdc++.h>

using namespace std;

int main()
{
    string a, b;
    while(getline(cin, a) != NULL){
        getline(cin, b);
        int lenA=a.size(), lenB=b.size();
        int table[500][500]={0};

        for(int i=0; i<lenA; i++){
            for(int j=0; j<lenB; j++){
                if(a[i]==b[j]){
                    table[i+1][j+1]=table[i][j]+1;
                }
                else{
                    table[i+1][j+1]=max(table[i][j+1], table[i+1][j]);
                }
            }
        }

        cout<<table[lenA][lenB]<<endl;
    }
    return 0;
}
