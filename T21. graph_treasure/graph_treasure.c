#include <stdio.h>
#define done 1
#define undo 0
#define MAXN 5000
int line[MAXN][MAXN];

int DFS(int value[MAXN], int judge[MAXN], int ncity, int start, int max)
{
    int temp, i;
    if(value[start] > max)
        max = value[start];
    judge[start] = done;
    for(i = 0; i < ncity; i++)
    {
        if(line[start][i] == 1 && judge[i] == undo)
        {
            temp = DFS (value, judge, ncity, i, max);
            if(temp > max)
                max = temp;
        }
    }
    return max;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    int ncity, mline, tstart, i, j, ufrom, vto, nextline=0;
    while(1)
    {
        scanf("%d%d%d", &ncity, &mline, &tstart);
        if(ncity == 0 || mline == 0 || tstart ==0)
            break;
        if(nextline++ != 0)  //don't forget that
            printf("\n");
        int max = 0, temp;
        int value[MAXN], judge[MAXN] = {0}, start[tstart];
        for(i = 0; i < tstart; i++)
            scanf("%d", &start[i]);
        for(i = 0; i < ncity; i++)
            scanf("%d", &value[i]);
        for(i = 0; i < MAXN; i++)
            for(j = 0; j < MAXN; j++)
                line[i][j] = 0;
        while(mline--)
        {
            scanf("%d%d", &ufrom, &vto);
            line[ufrom][vto] = 1;  //line[from][to]
        }
        for(i = 0; i < tstart; i++)
        {
            temp = DFS (value, judge, ncity, start[i], max);
            if(temp > max)
                max = temp;
        }
        printf("%d", max);
    }
    return 0;
}

