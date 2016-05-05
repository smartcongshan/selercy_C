#include "stack.h"

int main()
{
    datatype arr[] = {12,13,0,45,323};
    STACK *st;
    int i,ret;
    datatype tmp;
    st = st_create();
    if(st == NULL)
    exit(1);

    for(i = 0;i < sizeof(arr)/sizeof(*arr);i++)
    {
       st_push(st,&arr[i]);
    }

    st_travel(st);
    while(st_pop(st,&tmp) == 0)
    {
        printf("pop:%d",tmp);
    }
    printf("\n");
  /*
    if(ret != 0)
    printf("push filed\n");
    else
    st_travel(st);
*/
    st_destory(st);
    exit(0);
}

