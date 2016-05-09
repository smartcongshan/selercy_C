#ifndef __STACK_H
#define __STACK_H

#include <stdio.h>
#include <stdlib.h>

#define DATASIZE 32

typedef int datatype;

struct st_node{
	datatype data[DATASIZE];
	int top;
};

typedef struct st_node STACK;

STACK *st_create(void);

int st_push(STACK *,datatype *);

int st_pop(STACK *,datatype *);

int st_isempty(STACK *);

void st_travel(STACK *);

void st_destory(STACK *);

#endif

