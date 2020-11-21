#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

struct babysitter{int x, y;};

int cmp(const void *a, const void *b)
{
    if(((babysitter *)a)->x == ((babysitter *)b)->x) //x are equal, y: large to small
        return ((babysitter *)b)->y - ((babysitter *)a)->y;
    return ((babysitter *)a)->x - ((babysitter *)b)->x;
}

int main()
{
    //remember swap x, y if x>y
    //freopen("in.txt", "r", stdin);
    char input[100]={0};
    int mcase;
    fgets(input, 100, stdin);
    mcase=atoi(input);
    fgets(input, 100, stdin);
    while(mcase--){
        int nSitter=0;
        babysitter interval[50];

        char *pt;
        while(fgets(input, 100, stdin) != NULL){
            if(input[0]=='\n')
                break;
            interval[nSitter].x=atoi(input);
            pt=strchr(input, ' ')+1;
            interval[nSitter].y=atoi(pt);
            if(interval[nSitter].x>interval[nSitter].y){
                swap(interval[nSitter].x, interval[nSitter].y);
            }

            nSitter++;
        }

        qsort(interval, nSitter, sizeof(babysitter), cmp);

        int left=0, maxY=0, count=0, i=0;
        while(left<=199){
            for( ; i<nSitter; i++){
                if(interval[i].x > left){
                    break;
                }
                if(interval[i].y > maxY){
                    maxY=interval[i].y;
                }
            }
            //cout<<interval[maxIndex].x<<" * "<<interval[maxIndex].y<<endl;
            left=maxY+1;
            count++;
        }
        cout<<count;
        if(mcase)
            cout<<endl;
    }
    return 0;
}
