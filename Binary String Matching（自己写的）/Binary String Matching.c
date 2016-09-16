#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ASIZE   11
#define BSIZE   1001
#define N       100

struct ab{
    a[ASIZE];
    b[BSIZE];
};

int main()
{
    int i,con;
    scanf("%d",&con);
    struct ab buff[con];
    for(i = 0;i < con;i++)
    {
           scanf("%s",buff[i].a);
           scanf("%s",buff[i].b);
    }

    exit(0);
}
