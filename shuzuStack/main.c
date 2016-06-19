#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main()
{
    int maxsize = 10;
    int x[10] = {1,2,3,4,5,6,7,8,9,10};
    int i,ret;
    Stack s = NULL;
    s = create_stack(maxsize);
    if(s == NULL)
        exit(1);
    for(i = 0;i < sizeof(x)/sizeof(*x);i++)
        Push(x[i],s);
    ret = Top(s);
    printf("%d\n",ret);
    for(i = 0; i < 10;i++)
    {
        ret = TopAndPop(s);
        printf("%d\n",ret);
    }
    return 0;
}
