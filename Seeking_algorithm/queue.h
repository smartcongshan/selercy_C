#ifndef __QUEUE_H
#define __QUEUQ_H

#include <stdio.h>
#include <stdlib.h>

#define SIZE 32

typedef int type;

struct nd_qu{
	type data[SIZE];
	int head,tail;
};

typedef struct nd_qu QUEUE;

QUEUE *qu_create(void);

int enqueue(QUEUE *,type *);

int dequeue(QUEUE *,type *);

int qu_isempty(QUEUE *);

void qu_destory(QUEUE *);

void qu_travel(QUEUE *);

#endif

