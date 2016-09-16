#include "quick_sequence.h"

/* ��������ĺ��� */
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
/* Ѱ��һ������λ�� */
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

