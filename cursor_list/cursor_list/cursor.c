#include "cursor.h"

#define size 10

struct Node CursorSpace[size];

static Position alloc(void)
{
    Position p;
    p = CursorSpace[0].next;
    CursorSpace[0].next = CursorSpace[p].next;

    return p;
}

static void cu_free(Position p)
{
    CursorSpace[p].next = CursorSpace[0].next;
    CursorSpace[0].next = p;
}

void CursorSpace_init(void)
{
    int i;
    for(i = 0;i < size;i++)
    {
        CursorSpace[i].next = i + 1;
    }
    CursorSpace[size - 1].next = 0;
}

Position cu_create(void)
{
    Position p;
    p = alloc();
    if(p == 0)
        return 0;
    return p;
}

Position cu_find(datatype x,const List L)
{
    Position p;
    p = CursorSpace[L].next;
    while(p && CursorSpace[p].data != x)
        p = CursorSpace[p].next;

    return p;
}

int cu_insert(datatype x,Position p)
{
    Position tmp;
    tmp = alloc();
    if(tmp == 0)
        return -1;
    CursorSpace[tmp].data = x;
    CursorSpace[tmp].next = CursorSpace[p].next;
    CursorSpace[p].next = tmp;

    return 0;
}

void cu_delete(datatype x,Position p)
{
    Position L,tmp;
    L = cu_find(x,p);
    if(CursorSpace[L].next != 0)
    {
        tmp = CursorSpace[L].next;
        CursorSpace[L].next = CursorSpace[tmp].next;
        cu_free(tmp);
    }
}

void cu_destory(Position p)
{
    cu_free(p);
}
