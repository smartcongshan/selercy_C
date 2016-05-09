#include "queue.h"
#include "stack.h"

#define NUM_BALL	27

static int checkqu(QUEUE *qu)
{
	int i = (qu->head + 1)%SIZE;
	while(i != qu->tail)
	{
		if(qu->data[i] > qu->data[(i + 1)%SIZE])
		return 0;
		i = (i + 1)%SIZE;
	}
	return 1;
}

int main()
{
	int i,time = 0;
	QUEUE *qu;
	STACK *st_min,*st_fivemin,*st_hour;
	type t;	
	datatype value;

	qu         = qu_create();
	if(qu == NULL)
	{	
		printf("qu = NULL!\n");
		exit(1);
	}
	st_min     = st_create();
	if(st_min == NULL)
	{
		printf("st_min = NULL!\n");
		exit(1);
	}
	st_fivemin = st_create();
	if(st_fivemin == NULL)
	{
		printf("st_fivemin = NULL!\n");
		exit(1);
	}
	st_hour    = st_create();
	if(st_hour == NULL)
	{
		printf("st_hour = NULL!\n");
		exit(1);
	}


	for(i = 1;i <= NUM_BALL;i++)
	enqueue(qu,&i);

	qu_travel(qu);
	
	while(1)
	{
		dequeue(qu,&t);
		time++;
		if(st_min->top != 3)
		{
			st_push(st_min,&t);
		}
		else
		{
			while(!st_isempty(st_min))
			{
				st_pop(st_min,&value);
				enqueue(qu,&value);
			}
			if(st_fivemin->top != 10)
			{
				st_push(st_fivemin,&t);
			}
			else
			{
				while(!st_isempty(st_fivemin))
				{
					st_pop(st_fivemin,&value);
					enqueue(qu,&value);
				}
				if(st_hour->top != 10)
				{
					st_push(st_hour,&t);
				}
				else
				{
					while(!st_isempty(st_hour))
					{
						st_pop(st_hour,&value);
						enqueue(qu,&value);
					}
					enqueue(qu,&t);
					if(checkqu(qu))
					break;
				}
			}
		}
	}
	
	printf("%d\n",time);
	qu_travel(qu);

	qu_destory(qu);
	st_destory(st_min);
	st_destory(st_fivemin);
	st_destory(st_hour);
	exit(0);
}



