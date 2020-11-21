#include <iostream>
#include <cstdlib>

using namespace std;

int cmp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}
int main()
{
    int tcase;
    cin>>tcase;
    while(tcase--){
        int nBox;
        cin>>nBox;
        long long int sum=0;
        int time[nBox]={0};

        for(int i=0; i<nBox; i++)
            cin>>time[i];

        qsort(time, nBox, sizeof(int), cmp);
        for(int i=0; i<nBox; i++){
            sum+=time[i]*(nBox-i-1)*2 + time[i];
        }
        cout<<sum;
        if(tcase)
            cout<<endl;
    }
    return 0;
}
