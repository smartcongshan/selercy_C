#include <stdio.h>
#include <stdlib.h>
#include "quick_sequence.h"


int main()
{
    int i;
    int a[6] = {1,3,8,2,10,9};
    quicksort(a,0,5);
    for(i = 0;i < sizeof(a)/sizeof(*a);i++)
        printf("%d ",a[i]);
    return 0;
}


