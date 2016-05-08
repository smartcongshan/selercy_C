#include "queue.h"


QUEUE *qu_create(void)
{
	QUEUE *qu;
	qu = malloc(sizeof(QUEUE));
	if(qu == NULL)
	return NULL;
	qu->tail = 0;
	qu->head = 0;
	return qu;
}

int enqueue(QUEUE *me,type *data)
{
	if(((me->tail + 1) % SIZE) == me->head)
	return -1;
	me->tail = (me->tail + 1) % SIZE;
	me->data[me->tail] = *data;
	return 0;
}

int qu_isempty(QUEUE *qu)
{
	return (qu->head == qu->tail);
}
int dequeue(QUEUE *qu,type *data)
{
	if(qu_isempty(qu))
	{
		return -1;
	}
	qu->head = (qu->head + 1)%SIZE;
	*data = qu->data[qu->head];
	return 0;
}


void qu_destory(QUEUE *qu)
{
	free(qu);
}

void qu_travel(QUEUE *qu)
{
	int i;
	if(qu->head == qu->tail)
	{
		return ;
	}	
	i = (qu->head + 1)%SIZE;
	while(i != qu->tail)
	{
		printf("%d ",qu->data[i]);
		i = (i + 1)%SIZE;
	}
	printf("%d\n",qu->data[i]);
}

