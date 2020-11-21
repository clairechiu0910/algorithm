#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    int line=0;
    string a, b;
    while(getline(cin, a)){
        getline(cin, b);
        if(line++!=0)
            cout<<endl;

        int lenA=a.length(), lenB=b.length();
        int match[600][600]={0};
        for(int i=0; i<600; i++)
            match[i][0]=-3*i;
        for(int j=0; j<600; j++)
            match[0][j]=-3*j;

        for(int i=0; i<lenA; i++){
            for(int j=0; j<lenB; j++){
                if(a[i]==b[j]){
                    match[i+1][j+1]=match[i][j]+8;
                }
                else{
                    match[i+1][j+1]=max(match[i][j+1]-3, match[i+1][j]-3);
                    match[i+1][j+1]=max(match[i+1][j+1], match[i][j]-5);
                }
            }
        }
        /*for(int i=0; i<=lenA; i++){
            for(int j=0; j<=lenB; j++){
                cout<<match[i][j]<<" ";
            }
            cout<<endl;
        }*/
        cout<<match[lenA][lenB];
    }
    return 0;
}
