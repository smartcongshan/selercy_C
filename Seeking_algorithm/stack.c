#include "stack.h"

STACK *st_create(void)
{
	STACK *me;
	me = malloc(sizeof(STACK));
	if(me == NULL)
		return NULL;
	me->top = -1;
	return me;
}

int st_isempty(STACK *me)
{
	return (me->top == -1);
}

int st_push(STACK *me,datatype *data)
{
	if(me->top == DATASIZE - 1)
	return -1;
	me->data[++me->top] = *data;
	return 0;
}

int st_pop(STACK *me,datatype *data)
{
	if(st_isempty(me))
	return -1;
	*data = me->data[me->top--];
	return 0;
}

void st_travel(STACK *me)
{
	int i;
	if(st_isempty(me))
	return ;
	for(i = 0;i < me->top;i++)
	printf("%d ",me->data[i]);
	printf("\n");
}

void st_destory(STACK *me)
{
	free(me);
}


