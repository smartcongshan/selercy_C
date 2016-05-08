#include "queue.h"

int main()
{
    QUEUE *qu;
    type arr[] = {1,2,3,4};
    int i,ret;
    qu = qu_create();
    if(qu == NULL)
    exit(1);

    for(i = 0;i < sizeof(arr)/sizeof(*arr);i++)
    {
        enqueue(qu,&arr[i]);
    }


    type tmp = 1;
/*
    ret = qu_enqueue(qu,&tmp);
    if(ret == -1)
printf("insert failed\n");
else
*/
    qu_travel(qu);

    dequeue(qu,&tmp);

    printf("DELETE : %d\n",tmp);

    qu_travel(qu);

    qu_destory(qu);

    exit(0);
}

