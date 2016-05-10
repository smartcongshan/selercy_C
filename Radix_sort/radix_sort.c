#if 1
#include <stdio.h>
#include <stdlib.h>

int maximum;

void radix_sort(int *a,int size)
{
    int temp[10][size];
    int order[10] = {0};
    int n;
    int i,j,k;
    int p;
    n=1;
    while(n <= 100)
    {
        for(i = 0;i < size;i++)
        {
            k = (a[i]/n)%10;
            temp[k][order[k]] = a[i];
            order[k]++;
        }

        p = 0;

        for(j = 0;j < 10;j++)
        {
            if(order[j] != 0)
            {
                for(i = 0;i < order[j];i++)
                {
                    a[p] = temp[j][i];
                    p++;
                }
              order[j] = 0;
            }
        }
        n = n*10;
    }

}

int main()
{
    int i;
    int a[10] = {100,112,59,60,1,0,456,789,234,684};
    int *b;
    maximum = 100;
    radix_sort(a,10);
    for(i = 0;i < 10;i++)
    printf("%d ",a[i]);
    printf("\n");
    exit(0);
}
#else
    #include<stdio.h>

    void radixSort(int *a,int size)
    {
        int temp[10][20]={0}; //第一个10表示0~9，第二个20表示a的size
        int order[10]={0};
        int i,j,k; //k表示当前比较的那一位上的具体数字
        int n; //n=1,10,100,1000...取决于a中的最大的数
        int p;
        n=1;
        while(n <= 100)
        {
            for(i=0;i<size;i++)
            {
                k = (a[i]/n) % 10;
                temp[k][order[k]] = a[i];
                order[k]++;
            }
            p=0; //p为一次排序过程中,a的脚标
            for(i=0;i<10;i++)
            {
                if(order[i] != 0)
                {
                    for(j=0;j<order[i];j++)
                    {
                        a[p] = temp[i][j];
                        p++;
                    }
                order[i] = 0;
                }
            }
            n *= 10;
        }
    }

    void main()
    {
        int a[20]={3,22,93,3,5,14,28,65,39,81,71,72,48,39,55,105,129,184,196,208};
        int i;
        radixSort(a,20);
        for(i=0;i<20;i++)
            printf("%d  ",a[i]);
    }
#endif
