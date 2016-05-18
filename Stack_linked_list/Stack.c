#include "Stack.h"
#include <stdio.h>

struct Node
{
    ElementType data;
    PtrNode     next;
};

int IsEmpty(Stack s)
{
    return s->next == NULL;
}
void MakeEmpty(Stack s)
{
    if(s == NULL)
    {
        printf("Must use Create first\n");
        return ;
    }
    else
        while(!IsEmpty(s))
            Pop(s);
}
Stack CreateStack(void)
{
    Stack s;
    s = malloc(sizeof(struct Node));
    if(s == NULL)
        return NULL;
    s->next = NULL;
    MakeEmpty(s);
    return s;
}

void Push(ElementType x,Stack s)
{
    PtrNode TmpCell;

    TmpCell = malloc(sizeof(struct Node));
    if(TmpCell == NULL)
    {
        printf("put pf space!!!\n");
        return ;
    }
    else
    {
        TmpCell->next = s->next;
        TmpCell->data = x;
        s->next = TmpCell;
    }
}
ElementType Top(Stack s)
{
    if(!IsEmpty(s))
        return s->next->data;
    else
        printf("Empty Stack\n");
    return 0;
}
void Pop(Stack s)
{
    PtrNode FirstCell;
    if(IsEmpty(s))
    {
        printf("Empty Stack\n");
        return ;
    }
    else
    {
        FirstCell = s->next;
        s->next = s->next->next;
        free(FirstCell);
    }
}

void DestoryStack(Stack s)
{
    PtrNode node,next;
    for(node = s->next;node != NULL;node = next)
    {
        next = node->next;
        free(node);
    }
    free(s);
}
