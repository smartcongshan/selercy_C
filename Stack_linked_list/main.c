#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

int main()
{
    int i,ret;
    Stack s;
    s = CreateStack();
    for(i = 0;i < 10;i++)
        Push(i,s);
    ret = Top(s);
    printf("%d\n",ret);
    Pop(s);
    ret = Top(s);
    printf("%d\n",ret);
    exit(0);
}
