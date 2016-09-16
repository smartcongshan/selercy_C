#include "quick_sequence.h"

/* 快速排序的函数 */
void quicksort(int *a,int l,int h)
{
    int pos;
    if(l < h)
    {
        pos = findpos(a,l,h);
        quicksort(a,l,pos - 1);
        quicksort(a,pos + 1,h);
    }
}
/* 寻找一个数的位置 */
int findpos(int *a,int l,int h)
{
    int val = a[l];
    while(l < h)
    {
        while(l < h && a[h] >= val)
            --h;
        a[l] = a[h];
        while(l < h && a[l] <= val)
            ++l;
        a[h] = a[l];
    }
    a[l] = val;

    return h;
}

