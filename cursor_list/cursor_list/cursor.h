#ifndef CURSOR_H_INCLUDED
#define CURSOR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef int PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
typedef int datatype;

struct Node
{
    datatype data;
    Position next;
};

void CursorSpace_init(void);

Position cu_create(void);

Position cu_find(datatype ,const List );

int cu_insert(datatype ,Position );

void cu_delete(datatype ,Position );

void cu_destory(Position );

#endif // CURSOR_H_INCLUDED
